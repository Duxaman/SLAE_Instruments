#include "matrix.h"
#include "float.h"
#pragma once
Matrix::Matrix()
{
	_rows = 0;
	_cols = 0;
}
Matrix::Matrix(int rows, int cols, double** values)
{
	elements = newMatrix(rows, cols);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++i)
		{
			elements[i][j] = values[i][j];
		}
	_rows = rows;
	_cols = cols;

}
Matrix::Matrix(int n) // единичная 
{
	elements = newMatrix(n, n);
	_rows = n;
	_cols = n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) elements[i][j] = 1;
			else elements[i][j] = 0;
		}
}

Matrix::Matrix(const Matrix& Mx)
{
	_rows = Mx.getRowsCount();
	_cols = Mx.getColsCount();
	elements = newMatrix(_rows, _cols);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] = Mx.elements[i][j];
		}
}

Matrix::Matrix(int rows, int cols)
{
	_rows = rows;
	_cols = cols;
	elements = newMatrix(rows, cols);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] = 0;
		}
}

//Matrix::Matrix(Matrix&&Mx)
//{
//	this->elements = Mx.elements;
//	this->_rows = Mx._rows;
//	this->_cols = Mx._cols;
//	Mx.elements = nullptr;
//}

Matrix& Matrix::add(const Matrix& M)
{
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] += M.elements[i][j];
		}
	return *this;
}

Matrix& Matrix::raz(const Matrix& M)
{
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] -= M.elements[i][j];
		}
	return *this;
}

Matrix& Matrix::mult(double n)
{
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] *= n;
		}
	return *this;
}

Matrix Matrix::operator*(const Matrix& M) const
{
	/*n - число строк 1 матрицы, m- число столбцов 1 матрицы, q - число столбцов 2 матрицы*/
	/*Условие согласованности - число столбцов m в первом сомножителе равно числу строк l во втором*/
	int m = _cols;
	int l = M.getRowsCount();
	int n = _rows;
	int q = M.getColsCount();
	Matrix T(n, q);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < q; ++j)
		{
			double temp = 0;
			for (int k = 0; k < m; k++)
				temp = temp + this->elements[i][k] * M.elements[k][j];
			T.elements[i][j] = temp;
		}
	return T;

}
Matrix Matrix::operator*(double n) const
{
	Matrix T(_rows, _cols);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			T.elements[i][j] = this->elements[i][j] * n;
		}
	return T;
}
Matrix& Matrix::operator*=(double n)
{
	return mult(n);
}
Matrix Matrix::operator+(const Matrix& M) const
{
	int rows = M.getRowsCount();
	int cols = M.getColsCount();
	Matrix T(rows, cols);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			T.elements[i][j] = this->elements[i][j] + M.elements[i][j];
		}
	return T;
}
Matrix Matrix::operator-(const Matrix& M) const
{
	int rows = M.getRowsCount();
	int cols = M.getColsCount();
	Matrix T(rows, cols);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			T.elements[i][j] = this->elements[i][j] - M.elements[i][j];
		}
	return T;
}
Matrix& Matrix::operator+=(const Matrix& M)
{
	return add(M);
}
Matrix& Matrix::operator-=(const Matrix& M)
{
	return raz(M);
}
Matrix& Matrix::operator=(const Matrix& M)   /*сомнительная необходимость*/
{
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] = M.elements[i][j];
		}
	return *this;
}
Matrix Matrix::upperTriangular(int* swap_count) const
{
	Matrix Res(*this);
	int i;
	for (int j = 0; j < _cols - 1; ++j)
	{
		i = j;
		if (Res.elements[i][j] == 0)
		{
			for (int k = i; k < _rows; ++k)
				if (Res.elements[k][j] != 0)
				{
					/*заменить строки */
					(*swap_count)++;
					double temp;
					for (int l = 0; l < _cols; ++l)
					{
						temp = Res.elements[i][l];
						Res.elements[i][l] = Res.elements[k][l];
						Res.elements[k][l] = temp;
					}
					break;
				}
		}
		for (int k = i + 1; k < _rows; ++k)
		{
			if (Res.elements[k][j] != 0)
			{
				/*Поиск множителя, и зануления текущей строки (вычитание)*/
				double mul = Res.elements[k][j] / Res.elements[i][j];
				for (int l = j; l < _cols; ++l)
					Res.elements[k][l] = Res.elements[k][l] - (Res.elements[i][l] * mul);
			}
		}
	}
	return Res;
}
Matrix Matrix::upperTriangular() const
{
	Matrix Res(*this);
	int i;
	for (int j = 0; j < _cols - 1; ++j)
	{
		i = j;
		if (Res.elements[i][j] == 0)
		{
			for (int k = i; k < _rows; ++k)
				if (Res.elements[k][j] != 0)
				{
					/*заменить строки */
					double temp;
					for (int l = 0; l < _cols; ++l)
					{
						temp = Res.elements[i][l];
						Res.elements[i][l] = Res.elements[k][l];
						Res.elements[k][l] = temp;
					}
					break;
				}
		}
		for (int k = i + 1; k < _rows; ++k)
		{
			if (Res.elements[k][j] != 0)
			{
				/*Поиск множителя, и зануления текущей строки (вычитание)*/
				double mul = Res.elements[k][j] / Res.elements[i][j];
				for (int l = j; l < _cols; ++l)
					Res.elements[k][l] = Res.elements[k][l] - (Res.elements[i][l] * mul);
			}
		}
	}
	return Res;
}
Matrix::~Matrix()
{
	deleteMatrix(elements);
}
void Matrix::setSize(int rows, int cols)
{
	_rows = rows;
	_cols = cols;
	deleteMatrix(elements);
	elements = newMatrix(rows, cols);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			elements[i][j] = 0;
		}
}

int Matrix::getRowsCount() const
{
	return _rows;
}
int Matrix::getColsCount() const
{
	return _cols;
}
Matrix Matrix::transpose() const
{
	Matrix Tr(_cols, _rows);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			Tr.elements[j][i] = this->elements[i][j];
		}
	return Tr;

	/*for (int i = 0; i < _rows; ++i)
	for (int j = 0; j < _cols; ++j)
	{
	Tr.elements[j][i] = this->elements[i][j];
	}
	return Tr;
	*/
}
void Matrix::deleteMatrix(double** mx)
{
	//int cols = this->getRowsCount();
	for (int i = 0; i < _rows; ++i) delete[]mx[i];
	delete[]mx;
}
double** Matrix::newMatrix(int rows, int cols)
{
	double** mx;
	mx = new double*[rows];
	for (int i = 0; i < rows; ++i)
		mx[i] = new double[cols];
	return mx;
}
Matrix Matrix::inverse() const
{
	/*Позаботиться чтобы метод могли вызывать только квадратные невырожденные матрицы*/
	/*Matrix Inversed(_rows, _cols);
	if (!inverseByCells(Inversed))
		if (!inverseByTriangles(Inversed)) inverseByGauss(Inversed);
	return Inversed;*/
	Matrix Inversed(_rows, _cols);
	inverseByGauss(Inversed);
	return Inversed; /*для теста*/


}
double Matrix::det() const
{ /*Сюда должны попадать только квадратные матрицы*/
  /*Метод приведения к треугольному виду*/
	int swap_count = 0; /*счетчик смены знака, если строки меняются местами*/
	Matrix T(this->upperTriangular(&swap_count));
	double _det = 1;
	for (int i = 0; i < swap_count; ++i) _det *= -1;
	for (int i = 0; i < _cols; ++i)
		_det = _det * T.elements[i][i];
	return _det;

}
Matrix::Matrix(const Matrix& A, const Matrix& B, const Matrix& C, const Matrix& D)
{
	_rows = A.getRowsCount() + B.getColsCount();
	_cols = _rows;
	elements = newMatrix(_rows, _cols);
	int n = A.getRowsCount();
	int l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			elements[i][j] = A.elements[i][j];
		}
	l = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n; j < _cols; ++j)
		{
			elements[i][j] = B.elements[i][l];
			l++;
		}
		l = 0;
	}
	int k = 0; l = 0;
	for (int i = n; i < _rows; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			elements[i][j] = C.elements[k][l];
			l++;
		}
		k++;
		l = 0;
	}
	k = l = 0;
	for (int i = n; i < _rows; ++i)
	{
		for (int j = n; j < _cols; ++j)
		{
			elements[i][j] = D.elements[k][l];
			l++;
		}
		k++;
		l = 0;
	}
}
bool Matrix::inverseByCells(Matrix& Inversed) const
{
	/*Cначала разбиваем на подматрицы, затем проверяем верхнюю левую на вырожденность, затем
	если верхняя вырожденная, то проверяем нижнюю правую, если же она тоже, то обращение идет треугольниками.
	*/
	if (_rows % 2 != 0 || _rows < 3) return 0;
	int n = _cols / 2;
	Matrix A(n, n), B(n, n), C(n, n), D(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			A.elements[i][j] = this->elements[i][j];
		}
	int k; int l = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			B.elements[i][j] = this->elements[i][l];
			l++;
		}
		l = n;
	}
	k = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			C.elements[i][j] = this->elements[k][j];
		}
		k++;
	}
	l = k = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			D.elements[i][j] = this->elements[k][l];
			l++;
		}
		k++;
		l = n;
	}

	double det_A = A.det();
	double det_D = D.det();
	double det_T = 0;
	if (det_A != 0)
	{
		Matrix A_inversed(A.inverse());
		Matrix T(D - (C * A_inversed * B));
		det_T = T.det();
		if (det_T != 0)
		{
			/*формулы первой группы*/
			Matrix N(T.inverse());
			Matrix M((N * C * A_inversed) * -1);
			Matrix L((A_inversed * B * N) * -1);
			Matrix K(A_inversed - (A_inversed * B * M));
			Matrix Inv(K, L, M, N);
			Inversed = Inv;
			return true;
		}
	}
	if (det_T == 0 && det_D != 0)
	{
		Matrix D_inversed(D.inverse());
		Matrix T(A - (B * D_inversed * C));
		det_T = T.det();
		if (det_T != 0)
		{
			/*формулы второй группы*/
			Matrix K(T.inverse());
			Matrix L(((K * -1) * B) * D_inversed);
			Matrix M(((D_inversed * -1) * C) * K);
			Matrix N(D_inversed - ((D_inversed * C) * L));
			Matrix Inv(K, L, M, N);
			Inversed = Inv;
			return true;
		}
	}
	if (det_A == 0 && det_D == 0) return false;
}
bool Matrix::inverseByTriangles(Matrix& Inversed) const
{
	Matrix t(_rows, _cols), r(_rows, _cols);
	for (int i = 0; i < _rows; ++i)
		for (int j = 0; j < _cols; ++j)
		{
			if (i < j)
			{
				double temp = 0;
				for (int g = 0; g < (i); ++g)
				{
					temp += t.elements[i][g] * r.elements[g][j];
				}
				r.elements[i][j] = (elements[i][j] - temp) / t.elements[i][i];
			}

			if (i == j)
			{
				r.elements[i][j] = 1;
			}

			if (i >= j)
			{
				double temp = 0;
				for (int g = 0; g < (i); ++g)
				{
					temp += t.elements[i][g] * r.elements[g][j];
				}
				t.elements[i][j] = elements[i][j] - temp;
			}
		}
	/*теперь обращаем*/
	double sum;
	int n = _rows;
	Matrix T1_inversed(n, n), T2_inversed(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) T1_inversed.elements[i][i] = 1 / t.elements[i][i];
			if (i > j)
			{
				sum = 0;
				for (int k = j; k < (i); ++k)
				{
					sum -= T1_inversed.elements[k][j] * t.elements[i][k];
				}
				T1_inversed.elements[i][j] = sum / t.elements[i][i];
			}
		}
	for (int i = 0; i < n; ++i) T2_inversed.elements[i][i] = 1;
	for (int i = n - 1; i >= 0; --i)
		for (int j = i + 1; j < n; ++j)
		{
			sum = 0;
			for (int k = i + 1; k <= (j); ++k)
				sum -= T2_inversed.elements[k][j] * r.elements[i][k];
			T2_inversed.elements[i][j] = sum / r.elements[i][i];
		}
	Inversed = T2_inversed * T1_inversed;
	if (!_finite(Inversed.elements[0][0])) return 0;
	else return 1;
}
void Matrix::inverseByGauss(Matrix& Inversed) const
{
	Matrix E(_rows);
	Inversed = E;
	E = *this;
	int i;
	for (int j = 0; j < _cols; ++j)
	{
		i = j;
		if (E.elements[i][i] == 0)
		{
			/*заменить строки*/
			for (int k = i + 1; k < _rows; ++k)
			{
				if (E.elements[k][j] != 0)
				{
					for (int l = 0; l < _cols; ++l)
					{
						/*исходная*/
						double temp = E.elements[i][l];
						E.elements[i][l] = E.elements[k][l];
						E.elements[k][l] = temp;
						/*приписываемая*/
						temp = Inversed.elements[i][l];
						Inversed.elements[i][l] = Inversed.elements[k][l];
						Inversed.elements[k][l] = temp;
					}
					break;
				}
			}
		}
		if (E.elements[i][i] != 1 && E.elements[i][i] != 0)
		{
			/*Сделать на текущей диагонали единицу*/
			double m = 1 / E.elements[i][i];
			for (int k = 0; k < _cols; ++k)
			{
				/*исходная*/
				E.elements[i][k] *= m;
				/*приписываемая*/
				Inversed.elements[i][k] *= m;
			}
		}
		for (int k = i + 1; k < _rows; ++k)
		{
			if (E.elements[k][j] != 0)
			{
				/*Занулить элементы ниже главной диагонали*/
				/*Поиск множителя, и зануления текущей строки (вычитание)*/
				double mul = E.elements[k][j] / E.elements[i][i];
				for (int l = 0; l < _cols; ++l)
				{
					/*исходная*/
					E.elements[k][l] -= E.elements[i][l] * mul;
					/*приписываемая*/
					Inversed.elements[k][l] -= Inversed.elements[i][l] * mul;
				}
			}
		}


	}
	for (int j = _cols - 1; j >= 0; --j)
	{
		i = j;
		for (int k = i - 1; k >= 0; --k)
		{
			if (E.elements[k][j] != 0)
			{
				/*Занулить элементы выше главной диагонали*/
				/*Поиск множителя, и зануления текущей строки (вычитание)*/
				double mul = E.elements[k][j] / E.elements[i][i];
				for (int l = 0; l < _cols; ++l)
				{
					/*исходная*/
					E.elements[k][l] -= E.elements[i][l] * mul;
					/*приписываемая*/
					Inversed.elements[k][l] -= Inversed.elements[i][l] * mul;
				}
			}
		}
	}
}
bool Matrix::setElement(int row, int column, double value) const
{
	if (elementExists(row, column))
	{
		elements[row][column] = value;
		return true;
	}
	return false;
}
double Matrix::getElement(int row, int column) const
{
	if (elementExists(row, column))
	{
		return elements[row][column];
	}
	else return 0;
}
bool Matrix::elementExists(int row, int column) const
{
	if ((row >= 0) && (column >= 0))
	{
		if ((row < _rows) && (column < _cols))
		{
			return true;
		}
	}
	return false;
}

bool Matrix::isSquare() const
{
	if (_rows == _cols) return true;
	else return false;
}

bool Matrix::hasDiagonalPrepotency() const
{
	if (isSquare())
	{
		for (int i = 0; i < _rows; ++i)
			for (int j = 0; j < _cols; ++j)
			{
				double sum = 0;
				for (int k = 0; k < _cols; ++k)
				{
					if (k != i)
					{
						sum += elements[i][k];
					}
				}
				if (elements[i][i] < sum) return false;
			}
		return true;
	}
	return false;
}
double Matrix::getMax()
{
	double max = elements[0][0];
	for (int i = 0; i < _rows; ++i)
		for (int j = 1; j < _cols; ++j)
		{
			if (elements[i][j] > max) max = elements[i][j];
		}
	return max;
}

double Matrix::getMin()
{
	double min = elements[0][0];
	for (int i = 0; i < _rows; ++i)
		for (int j = 1; j < _cols; ++j)
		{
			if (elements[i][j] < min) min = elements[i][j];
		}
	return min;
}
bool Matrix::checkMainMinors() const
{
	if (isSquare())
	{
		for (int i = 1; i < _rows; ++i)
		{
			/*создаем подматрицу*/
			Matrix temp(i, i);
			for (int j = 0; j <= i; ++j)
				for (int k = 0; k <= i; ++k)
				{
					temp.setElement(j, k, getElement(j, k));
				}
			if (temp.det() == 0) return false;
		}
		return true;
	}
	return false;
}

Matrix** Matrix::getTriangularDecomposition() const
{
	Matrix** res = new Matrix*[2];
	res[0] = new Matrix(_rows, _cols);
	res[1] = new Matrix(_rows, _cols);
	if (this->checkMainMinors())
	{
		for (int i = 0; i < _rows; ++i)
			for (int j = 0; j < _cols; ++j)
			{
				if (i < j)
				{
					double temp = 0;
					for (int k = 0; k < (i); ++k)
					{
						temp += res[0]->getElement(i, k) * res[1]->getElement(k, j);
					}
					res[1]->setElement(i, j, (this->getElement(i, j) - temp) / res[0]->getElement(i, i));

				}

				if (i == j)
				{
					res[1]->setElement(i, j, 1);
				}

				if (i >= j)
				{
					if (j == 0)
					{
						res[0]->setElement(i, j, this->getElement(i, j));
					}
					else
					{
						double temp = 0;
						for (int k = 0; k < (j); ++k)
						{
							temp += res[0]->getElement(i, k) * res[1]->getElement(k, j);
						}
						res[0]->setElement(i, j, this->getElement(i, j) - temp);
					}
				}
			}
	}
	return res;
}