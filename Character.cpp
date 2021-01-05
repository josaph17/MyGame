class Character 
{ //тело класса
public:
	Characters();
	~Characters();
	void GoDown();
	void GoUp();
	void GoRight();
	void GoLeft();
	int GetX(valueX);
	int GetY(valueY);
private:
	int coodrinate_x, coordinate_y;
};

Character::Character() //параметры в конструкторе
{
	this -> coodrinate_x = coodrinate_x;
	this-> coordinate_y = coordinate_y;
	coodrinate_x = -1; //это означает что игрока нет
	coordinate_y = -1; //это означает что игрока нет
}
Character::~Characters() 
{

}

void Character::GoDown()
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
void Character::GoUp()
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
void Character::GoRight()
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
void Character::GoLeft()
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
int Character::GetX()
{
	return coodrinate_x;
}
int Character::GetY()
{
	return coodrinate_y;
}
void Character::SetX(valueX)
{
	coodrinate_x = valueX;
}
void Character::SetY(valueY)
{
	coodrinate_y = valueY;
}















