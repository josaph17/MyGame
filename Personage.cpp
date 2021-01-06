#include "Personage.h"
#include "Matrix.h" 

Personage::Personage(int coordinate_x, int coordinate_y, Matrix* board) //параметры в конструкторе
{
	this->board = board;
	this->coordinate_x = coordinate_x;
	this->coordinate_y = coordinate_y;
	//coordinate_x = -1; //Ты присваиваешь -1 тем переменным (параметрам), которые сейчас удалятся.
	//coordinate_y = -1; //смысла в этом нет/
}
Personage::~Personage() 
{

}

void Personage::GoDown()
{
	if ((coordinate_y < board->height() - 1) && (board->Get(coordinate_y + 1, coordinate_x) == 0))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y+1, coordinate_x, 2); ///
		coordinate_y++;
	}
}
void Personage::GoUp()
{
	if ((coordinate_y > 0) && (board->Get(coordinate_y - 1, coordinate_x) == 0))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y - 1, coordinate_x, 2); ///
		coordinate_y--;
	}
}
void Personage::GoRight()
{
	if ((coordinate_x < board->width()) && ((board->Get(coordinate_y, coordinate_x + 1) == 0)))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y, coordinate_x+1, 2); ///
		coordinate_x++;
	}
}
void Personage::GoLeft()
{
	if ((coordinate_x > 0) && ((board->Get(coordinate_y, coordinate_x - 1) == 0)))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y, coordinate_x - 1, 2); ///
		coordinate_x--;
	}
}
int Personage::GetX()
{
	return coordinate_x;
}
int Personage::GetY()
{
	return coordinate_y;
}
void Personage::SetX(int valueX)
{
	coordinate_x = valueX;
}
void Personage::SetY(int valueY)
{
	coordinate_y = valueY;
}















