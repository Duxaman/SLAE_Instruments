#pragma once
#include "matrix.h"
/*Предоставляет методы по решению СЛАУ*/
class SLAE
{
	public:
	static Matrix solveByKramer(const Matrix& UnknownPart, const Matrix& FreePart);
	static Matrix solveByReverse(const Matrix& UnknownPart, const Matrix& FreePart);
	static Matrix solveByGauss(const Matrix& UnknownPart, const Matrix& FreePart);
	static Matrix solveByHolec(const Matrix& UnknownPart, const Matrix& FreePart);
	static Matrix solveByIteration(const Matrix& UnknownPart, const Matrix& FreePart, double Accuracy);
	static Matrix solveByZedel(const Matrix& UnknownPart, const Matrix& FreePart, double Accuracy);
	private:
	/*Заменяет столбцы для рассчета корней в методе Крамера*/
	static void swapColsForKramer(const Matrix& unknown, const Matrix& Free, int column_number);
	/*Соединяет две матрицы в одну для решения методом Гаусса*/
	static Matrix mergeMatrixes(const Matrix& UnknownPart, const Matrix& FreePart);
	/*Проверяет достигнута ли требуемая точность*/
	static bool accuracyIsReached(const Matrix& First, const Matrix& Second, double accuracy);
};


