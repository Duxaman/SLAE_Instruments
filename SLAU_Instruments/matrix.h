#ifndef MATRIX_H
#define MATRIX_H
/*������������ �������� ������ ��� ������ � ���������*/
class Matrix 
{
public:

	Matrix();
	/*������� ��������� �������*/
	Matrix (int n);
	/*������� ������� �������� rows x cols, �������� �� ���������� ������� values*/
    Matrix(int rows, int cols, double** values);
	/*������� ������� ������� �������� rows x cols*/
	Matrix(int rows, int cols);
	Matrix(const Matrix& Mx);
	//Matrix(Matrix&& Mx);
	/*���������� ������� ������� � �������� �*/
	Matrix& add(const Matrix& M);
	/*�������� �� ������� ������� ������� �*/
	Matrix& raz(const Matrix& M);
	/*�������� ������� ������� �� ������� �*/
	Matrix& mult(double n);
	/*���������� ������� ����������� � ������������ ����, �������� ������ ���������� ������������*/
	Matrix upperTriangular(int* swap_count) const;
	/*���������� ������� ����������� � ������������ ������������ ����*/
	Matrix upperTriangular() const;
	/*���������� ����������������� ������� �� ��������*/
	Matrix transpose() const;  
	/*���������� �����������*/
	double det() const;
	/*���������� �������� ������� �� ��������*/
    Matrix inverse()   const;
	/*������� ����� ������� �� ������ ��������� ���������*/
	Matrix(const Matrix& K, const Matrix& L, const Matrix& M, const Matrix& N);
	Matrix operator*(const Matrix& M) const;
	Matrix operator*(double n) const;
	//Matrix& operator*=(const Matrix& M) const;
	Matrix& operator*=(double n);
	Matrix operator+(const Matrix& M) const;
	Matrix operator-(const Matrix& M) const;
	Matrix& operator+=(const Matrix& M);
	Matrix& operator-=(const Matrix& M);
	/*������������ ������� ���� �� ������� ��� � �����������������*/
	Matrix& operator=(const Matrix&M);
	/*������������� ����� ������ �������, ������� ��*/
	void setSize(int rows, int cols);
	/*������������� ������� ��������� value �� ��������� �����������*/
	bool setElement(int row, int column, double value) const;
	/*���������� ������� �� ��������� ����������*/
	double getElement(int row, int column) const;
	/*��������� ���������� �� �������*/
	bool isSquare() const;	
	/*���������, �������� �� ������� ��������� ������������� ������������*/
	bool hasDiagonalPrepotency() const;
	int getRowsCount() const;
	int getColsCount() const;
	/*���������� ������������ �������*/
	double getMax();
	/*���������� ����������� �������*/
	double getMin();
	/*��������� ����� �� ������� ������ ����*/
	bool checkMainMinors() const;
	/*���������� ����������� �� ����������� ������� �������, ���� ��������*/
	Matrix** getTriangularDecomposition() const;
	~Matrix();

    private:
	double** elements;	
	int _rows, _cols;
	/*�������� ������ ��� ������� �������� n x m*/
	double** newMatrix (int n, int m);
	/*������� ������� �� ������*/
	void deleteMatrix (double** mx);
	/*�������� ������� ������� ������� �� ������ ���� ��� ��������*/
	bool inverseByCells(Matrix& Inversed) const;
	/*�������� ������� ������� ���������� � ������������ ����, ���� ��������*/
	bool inverseByTriangles(Matrix& Inversed) const;
	/*�������� ������� ������� ������*/
	void inverseByGauss(Matrix& Inversed) const;
	/*��������� ���������� �� � ������� ������� �� �������� �����������*/
	bool elementExists(int row, int column) const;

};


#endif MATRIX H
