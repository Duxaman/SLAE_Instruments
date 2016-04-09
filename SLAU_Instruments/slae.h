#pragma once
#include "matrix.h"
/*������������� ������ �� ������� ����*/
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
	/*�������� ������� ��� �������� ������ � ������ �������*/
	static void swapColsForKramer(const Matrix& unknown, const Matrix& Free, int column_number);
	/*��������� ��� ������� � ���� ��� ������� ������� ������*/
	static Matrix mergeMatrixes(const Matrix& UnknownPart, const Matrix& FreePart);
	/*��������� ���������� �� ��������� ��������*/
	static bool accuracyIsReached(const Matrix& First, const Matrix& Second, double accuracy);
};


