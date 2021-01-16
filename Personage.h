#include "Matrix.h" 

#pragma once
class Personage 
{ //тело класса
public:
	Personage(int coordinate_x, int coordinate_y, Matrix* board, int personage_value);
	~Personage();
	void GoDown();  
	void GoUp();
	void GoRight();
	void GoLeft();
	int GetX();
	int GetY();
	void SetX(int valueX);
	void SetY(int valueY);
	int GetValue();
	void SetValue(int valueNew);
protected:
	Matrix* board;
	int coordinate_x, coordinate_y;
	int personage_value;
};














