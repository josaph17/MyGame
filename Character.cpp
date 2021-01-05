#include "Matrix.cpp" 

class Personage 
{ //тело класса
public:
	Personage();
	~Personage();
	void GoDown();
	void GoUp();
	void GoRight();
	void GoLeft();
	int GetX(valueX);
	int GetY(valueY);
private:
	Matrix* board;
	int coodrinate_x, coordinate_y;
};

Personage::Personage() //параметры в конструкторе
{
	board = new Matrix(20, 20);
	this -> coodrinate_x = coodrinate_x;
	this-> coordinate_y = coordinate_y;
	//coodrinate_x = -1; //Ты присваиваешь -1 тем переменным (параметрам), которые сейчас удалятся.
	//coordinate_y = -1; //смысла в этом нет
}
Personage::~Personage() 
{
	delete board;
}

void Personage::GoDown()
{
	if ((coodrinate_x < 0) || (coodrinate_x == board->height()-1)) // если меньше 0 или на последней строке 
		return; // я выйду из ф-ии
	if (board->Get(coodrinate_x +1, coodrinate_x) == 0) /// board->Get(coordinate_x, coordinate_y)
	{
		board->Set(coodrinate_x, coordinate_y, 0); ///
		board->Set(coodrinate_x +1, coordinate_y, 2); ///
		coodrinate_x++; //меняем координату игрока
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
	return coodrinate_x;
}
int Personage::GetY()
{
	return coodrinate_y;
}
void Personage::SetX(valueX)
{
	coodrinate_x = valueX;
}
void Personage::SetY(valueY)
{
	coodrinate_y = valueY;
}















