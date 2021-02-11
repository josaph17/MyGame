#include "Matrix.h" 

#pragma once
class Personage 
{ //тело класса
public:
	Personage(int _coordinate_x, int _coordinate_y, Matrix* _board, int _personage_value);
	~Personage();
	void GoDown();  
	void GoUp();
	void GoRight();
	void GoLeft();
	int GetX();
	int GetY();
	void SetX(int valueX);
	void SetY(int valueY);
	int GetValue() const; //ф-я константная и она не меняет
	bool isAlive() const;
	void Die();
protected:
	Matrix* board;
	int coordinate_x, coordinate_y;
private:
	int personage_value;
	bool alive;
};