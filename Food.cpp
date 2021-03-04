#include "Personage.h"
#include "Matrix.h" 
#include "Food.h"

Food::Food(Matrix* _board) : Personage(-1, -1, _board, 3)
{
	while (true) /*бесконечный цикл*/
	{
		int y = rand() % board->height(); /*назначаем рандомные координаты*/
		int x = rand() % board->width();
		if (board->isExistAndEmpty(y, x)) /*если клетка по этим координатам есть и пуста, то присваиваем значения*/
		{
			SetY(y);
			SetX(x);
			board->Set(y, x, 3);
			break;
		}
	}
}
