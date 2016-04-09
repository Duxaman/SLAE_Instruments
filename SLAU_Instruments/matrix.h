#ifndef MATRIX_H
#define MATRIX_H
/*Представляет основные методы для работы с матрицами*/
class Matrix 
{
public:

	Matrix();
	/*Создает единичную матрицу*/
	Matrix (int n);
	/*Создает матрицу размером rows x cols, заполняя ее содержимым массива values*/
    Matrix(int rows, int cols, double** values);
	/*Создает нулевую матрицу размером rows x cols*/
	Matrix(int rows, int cols);
	Matrix(const Matrix& Mx);
	//Matrix(Matrix&& Mx);
	/*Складывает текущую матрицу с матрицей М*/
	Matrix& add(const Matrix& M);
	/*Вычитает из текущей матрицы матрицу М*/
	Matrix& raz(const Matrix& M);
	/*Умножает текущую матрицу на матрицу М*/
	Matrix& mult(double n);
	/*Возвращает матрицу приведенную к ступенчатому виду, позволяя узнать количество перестановок*/
	Matrix upperTriangular(int* swap_count) const;
	/*Возвращает матрицу приведенную к ступенчатому треугольному виду*/
	Matrix upperTriangular() const;
	/*Возвращает транспонированную матрицу от исходной*/
	Matrix transpose() const;  
	/*Возвращает детерминант*/
	double det() const;
	/*Возвращает обратную матрицу от исходной*/
    Matrix inverse()   const;
	/*Создает новую матрицу на основе клеточных подматриц*/
	Matrix(const Matrix& K, const Matrix& L, const Matrix& M, const Matrix& N);
	Matrix operator*(const Matrix& M) const;
	Matrix operator*(double n) const;
	//Matrix& operator*=(const Matrix& M) const;
	Matrix& operator*=(double n);
	Matrix operator+(const Matrix& M) const;
	Matrix operator-(const Matrix& M) const;
	Matrix& operator+=(const Matrix& M);
	Matrix& operator-=(const Matrix& M);
	/*Присваивание матрицы того же размера что и инициализированая*/
	Matrix& operator=(const Matrix&M);
	/*Устанавливает новый размер матрицы, обнуляя ее*/
	void setSize(int rows, int cols);
	/*Устанавливает элемент значением value по указанным координатам*/
	bool setElement(int row, int column, double value) const;
	/*Возвращает элемент по указанным координтам*/
	double getElement(int row, int column) const;
	/*Проверяет квадратная ли матрица*/
	bool isSquare() const;	
	/*Проверяет, обладает ли матрица свойством диагонального преобладания*/
	bool hasDiagonalPrepotency() const;
	int getRowsCount() const;
	int getColsCount() const;
	/*Возвращает максимальный элемент*/
	double getMax();
	/*Возвращает минимальный элемент*/
	double getMin();
	/*Проверяет равны ли главные миноры нулю*/
	bool checkMainMinors() const;
	/*Возвращает разложенную на треугольные текущую матрицу, если вохможно*/
	Matrix** getTriangularDecomposition() const;
	~Matrix();

    private:
	double** elements;	
	int _rows, _cols;
	/*Выделяет память под матрицу размером n x m*/
	double** newMatrix (int n, int m);
	/*Удаляет матрицу из памяти*/
	void deleteMatrix (double** mx);
	/*Обращает матрицу методом деления на клетки если это возможно*/
	bool inverseByCells(Matrix& Inversed) const;
	/*Обращает матрицу методом приведения к треугольному виду, если возможно*/
	bool inverseByTriangles(Matrix& Inversed) const;
	/*Обращает матрицу методом Гаусса*/
	void inverseByGauss(Matrix& Inversed) const;
	/*Проверяет существует ли в матрице элемент по заданным координатам*/
	bool elementExists(int row, int column) const;

};


#endif MATRIX H
