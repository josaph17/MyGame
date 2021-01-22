#include "Matrix.h"

Matrix::Matrix(int rows, int cols) //параметры в конструкторе
{
	this->rows = rows;
	this->cols = cols;
	arr = new int* [rows];  //переменная arr будет хранить указатель на указатель  
			//мы создаем массив указателей, мы здесь будем хранить указатели  
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]; /*в каждый элемент который будет хранить указатель на int мы будем присваивать новый динамический массив, размер массива будет соответсвовать переменной colls*/
		//объявление и создание массива, выделение под него памяти5
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 0;
		}
	}
}//коонструктор
Matrix::~Matrix() //полность удаляем нашу ОП после того как поработаем с нашим массивом и он нам станет ненужен
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

int Matrix::Get(int i, int j)
{
	return arr[i][j];
}
void Matrix::Set(int i, int j, int value)
{
	arr[i][j] = value;
}
int Matrix::height()
{
	return rows; // строки т.е. высота
}//строки
int Matrix::width()//столбцы т.е. ширина
{
	return cols;
}
bool Matrix::isExistAndEmpty(int i, int j)
{
	return ((((i >= 0) && (i < height())) && ((j >= 0) && (j < width()))) && (arr[i][j] == 0));
}

















