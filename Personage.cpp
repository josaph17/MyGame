#include "Personage.h"
#include "Matrix.h" 

Personage::Personage(int _coordinate_x, int _coordinate_y, Matrix* _board, int _personage_value) //параметры в конструкторе
{
	board = _board;
	coordinate_x = _coordinate_x;
	coordinate_y = _coordinate_y;
	personage_value = _personage_value;
	//coordinate_x = -1; //Ты присваиваешь -1 тем переменным (параметрам), которые сейчас удалятся.
	//coordinate_y = -1; //смысла в этом нет/
}
Personage::~Personage() 
{

}

void Personage::GoDown()
{
	//if ((coordinate_y < board->height() - 1) && (board->Get(coordinate_y + 1, coordinate_x) == 0))
	if (board->isExistAndEmpty(coordinate_y + 1, coordinate_x))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y+1, coordinate_x, personage_value); /// была 2 вместо personage_value
		coordinate_y++;
	}
}
void Personage::GoUp()
{
	//if ((coordinate_y > 0) && (board->Get(coordinate_y - 1, coordinate_x) == 0))
	if (board->isExistAndEmpty(coordinate_y - 1, coordinate_x))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y - 1, coordinate_x, personage_value); ///
		coordinate_y--;
	}
}
void Personage::GoRight()
{
	//if ((coordinate_x < board->width()) && ((board->Get(coordinate_y, coordinate_x + 1) == 0)))
	if (board->isExistAndEmpty(coordinate_y, coordinate_x + 1))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y, coordinate_x+1, personage_value); ///
		coordinate_x++;
	}
}
void Personage::GoLeft()
{
	//if ((coordinate_x > 0) && ((board->Get(coordinate_y, coordinate_x - 1) == 0)))
	if (board->isExistAndEmpty(coordinate_y, coordinate_x - 1))
	{
		board->Set(coordinate_y, coordinate_x, 0); ///
		board->Set(coordinate_y, coordinate_x - 1, personage_value); ///
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
int Personage::GetValue()
{
	return personage_value;
}
void Personage::SetValue(int valueNew)
{
	personage_value = valueNew;
}















