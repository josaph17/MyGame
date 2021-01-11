#include "Matrix.h" 

#pragma once
class Personage 
{ //тело класса
public:
	Personage(int coordinate_x, int coordinate_y, Matrix* board);
	~Personage();
	void GoDown(int personage_value);
	void GoUp(int personage_value);
	void GoRight(int personage_value);
	void GoLeft(int personage_value);
	int GetX();
	int GetY();
	void SetX(int valueX);
	void SetY(int valueY);
private:
	Matrix* board;
	int coordinate_x, coordinate_y;
	//int personage_value;
};















