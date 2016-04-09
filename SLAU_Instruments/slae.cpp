#include "slae.h"
#include <math.h>

Matrix SLAE::solveByKramer(const Matrix& UnknownPart, const Matrix& FreePart)
{
	double determinant = UnknownPart.det();
	int size = UnknownPart.getColsCount();
	Matrix Answer(1, size);
	for (int i = 0; i < size; ++i)
	{
		Matrix Temp(UnknownPart);
		swapColsForKramer(Temp, FreePart, i);
		double cur_det = Temp.det();
		Answer.setElement(0, i, (cur_det / determinant));
	}

	return Answer;
}

void SLAE::swapColsForKramer(const Matrix& unknown, const Matrix& Free, int column_number)
{
	int size = unknown.getColsCount();
	for (int i = 0; i < size; ++i)
	{
		unknown.setElement(i, column_number, Free.getElement(i, 0));
	}
}

Matrix SLAE::solveByReverse(const Matrix& UnknownPart, const Matrix& FreePart)
{
	Matrix Answer((UnknownPart.inverse() * FreePart));
	return Answer.transpose();
}

Matrix SLAE::solveByGauss(const Matrix& UnknownPart, const Matrix& FreePart)
{
	/*Соеденяем матрицы, и приводимим к треугольному виду*/
	Matrix Source(mergeMatrixes(UnknownPart, FreePart).upperTriangular());
	int rootnum = Source.getRowsCount();
	/*количество строк исходной матрицы*/
	int sorcecols = Source.getColsCount();
	Matrix Answer(1, rootnum);
	/*Проход снизу вверх*/
	for (int i = rootnum - 1; i >= 0; --i)
	{
		/*считаем очередную сумму*/
		double sum = 0;
		for (int j = i + 1; j < rootnum; ++j)
		{
			sum += Source.getElement(i, j) * Answer.getElement(0, j);
		}
		/*считаем очередной корень*/
		Answer.setElement(0, i, (Source.getElement(i, sorcecols - 1) - sum) / Source.getElement(i, i));

	}
	return Answer;
}

Matrix SLAE::mergeMatrixes(const Matrix& UnknownPart, const Matrix& FreePart)
{
	int rows = UnknownPart.getRowsCount();
	int cols = UnknownPart.getColsCount();
	Matrix Result(rows, cols + 1);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			Result.setElement(i, j, UnknownPart.getElement(i, j));
		}
	for (int i = 0; i < rows; ++i)
	{
		;
		Result.setElement(i, cols, FreePart.getElement(i, 0));
	}
	return Result;
}

Matrix SLAE::solveByHolec(const Matrix& UnknownPart, const Matrix& FreePart)
{
	int size = UnknownPart.getColsCount();
	double* y = new double[size];
	Matrix Answer(1, size);
	Matrix** Triangulars = UnknownPart.getTriangularDecomposition();

	y[0] = FreePart.getElement(0, 0) / Triangulars[0]->getElement(0, 0);
	for (int i = 1; i < size; ++i)
	{
		double sum = 0;
		for (int k = 0; k < i; ++k)
		{
			sum += Triangulars[0]->getElement(i, k) * y[k];
		}
		y[i] = (FreePart.getElement(i, 0) - sum) / Triangulars[0]->getElement(i, i);
	}
	Answer.setElement(0, size - 1, y[size - 1]);
	for (int i = size - 2; i >= 0; --i) /*отсчет с нуля + предпоследний*/
	{
		double sum = 0;
		for (int k = i + 1; k < size; ++k)
		{
			sum += Triangulars[1]->getElement(i, k) * Answer.getElement(0, k);
		}
		Answer.setElement(0, i, y[i] - sum);
	}

	return Answer;
}

bool SLAE::accuracyIsReached(const Matrix& First, const Matrix& Second, double accuracy)
{
	int size = First.getColsCount();
	double maxinc = fabs(First.getElement(0, 0) - Second.getElement(0, 0));
	double temp = 0;
	for (int i = 1; i < size; ++i)
	{
		temp = fabs(First.getElement(0, i) - Second.getElement(0, i));
		if (temp > maxinc) maxinc = temp;
	}
	if (maxinc < accuracy) return true;
	else return false;
}

Matrix SLAE::solveByIteration(const Matrix& UnknownPart, const Matrix& FreePart, double Accuracy)
{
	int size = UnknownPart.getRowsCount();
	/*Введем матрицу D и С*/
	Matrix D(size, size);
	Matrix C(size, 1);
	for (int i = 0; i < size; ++i)
	{
		C.setElement(i, 0, FreePart.getElement(i, 0) / UnknownPart.getElement(i, i));
		for (int j = 0; j < size; ++j)
		{
			if (i == j) D.setElement(i, j, 0);
			else D.setElement(i, j, -(UnknownPart.getElement(i, j) / UnknownPart.getElement(i, i)));
		}
	}
	/*Задаем нулевое приближение = столбцу свободных членов*/
	Matrix Xk(size, 1);
	Matrix Xknext(FreePart);
	int count = 0;
	do
	{
		Xk = Xknext;
		Xknext = C + D * Xk;  /*Рассчет очередного приближения*/
		count++;
		if (count > 1000) break;
	} while (!accuracyIsReached(Xk, Xknext, Accuracy));

	return Xk.transpose();
}
Matrix SLAE::solveByZedel(const Matrix& UnknownPart, const Matrix& FreePart, double Accuracy)
{
	int size = UnknownPart.getRowsCount();
	/*Введем матрицу D и С*/
	Matrix D(size, size);
	Matrix C(size, 1);
	for (int i = 0; i < size; ++i)
	{
		C.setElement(i, 0, FreePart.getElement(i, 0) / UnknownPart.getElement(i, i));
		for (int j = 0; j < size; ++j)
		{
			if (i == j) D.setElement(i, j, 0);
			else D.setElement(i, j, -(UnknownPart.getElement(i, j) / UnknownPart.getElement(i, i)));
		}
	}
	Matrix Xk(size, 1);
	Matrix Xkn(FreePart);
	int count = 0;
	do
	{
		Xk = Xkn;
		for (int i = 0; i < size; ++i)
		{
			double sum1 = 0;
			double sum2 = 0;
			/*Рассчет слагаемых от 0 < i - 1*/
			for (int j = 0; j < i; ++j)
			{
				sum1 += D.getElement(i, j) * Xkn.getElement(j, 0);
			}
			/*Рассчет слагаемых от i итерации*/
			for (int j = i; j < size; ++j)
			{
				sum2 += D.getElement(i, j) * Xk.getElement(j, 0);
			}
			Xkn.setElement(i, 0, C.getElement(i, 0) + sum1 + sum2);
		}
		count++;
		if (count > 1000) break;

	} while (!accuracyIsReached(Xk, Xkn, Accuracy));
	return Xkn.transpose();
}