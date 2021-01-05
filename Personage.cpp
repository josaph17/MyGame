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
	if ((coordinate_x < 0) || (coordinate_x == board->height()-1)) // если меньше 0 или на последней строке 
		return; // я выйду из ф-ии
	if (board->Get(coordinate_x +1, coordinate_x) == 0) /// board->Get(coordinate_x, coordinate_y)
	{
		board->Set(coordinate_x, coordinate_y, 0); ///
		board->Set(coordinate_x +1, coordinate_y, 2); ///
		coordinate_x++; //меняем координату игрока
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел.
	}
}
void Personage::GoUp()
{
	if (coordinate_x <= 0) // если coordinate_x меньше или равно 0 и на последней строке
		return; // я выйду из ф-ии
	if (board->Get(coordinate_x - 1, coordinate_y) == 0)  ///
	{
		board->Set(coordinate_x, coordinate_y, 0); ///
		board->Set(coordinate_x - 1, coordinate_y, 2); ///
		coordinate_x--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Personage::GoRight()
{
	if ((coordinate_y < 0) || (coordinate_y > board->width()))
		return;
	if (board->Get(coordinate_x, coordinate_y+1) == 0)
	{
		board->Set(coordinate_x, coordinate_y, 0);
		board->Set(coordinate_x, coordinate_y + 1, 2);
		coordinate_y++;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Personage::GoLeft()
{
	if (coordinate_y < 0)
		return;
	if (board->Get(coordinate_x, coordinate_y - 1) == 0)
	{
		board->Set(coordinate_x, coordinate_y, 0);
		board->Set(coordinate_x, coordinate_y - 1, 2);
		coordinate_y--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
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















