#pragma once

class Matrix
{
public:
	Matrix(int rows, int cols);
	~Matrix();
	int Get(int i, int j); //возвращает в ф-ю рез-т эл-т массива
	void Set(int i, int j, int value); //присваивает эл-у массива какое то число, ф-я меняет како-то эл-т массива
	int height();
	int width();
private:
	int** arr;//данные
	int rows, cols;//размеры
};








