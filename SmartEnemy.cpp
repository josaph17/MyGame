#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(Matrix* _board, Player* _player) : Enemy(_board, _player) //_a , _b : _a , _b
/*параметры Smart Enemy должны быть названы именами, их нужно передать в конструктор Enemy*/
{

}

void SmartEnemy::Step()
{
	int distance_x = player->GetX() - GetX();
	int distance_y = player->GetY() - GetY();

	int old_x = GetX(); /*старое расположение врага, после switch*/
	int old_y = GetY();

	int randomMove = 1 + rand() % 2;
	/*тут у тебя все блоки в case 1 благодаря условиям могут выполниться только 1 раз, даже если ты уберёшь все break'и в case 2 - также,
	поэтому все break'и можно убрать из этой функции и сделать break только в одном месте - перед строкой case 2:*/
	switch (randomMove)
	{
	case 1:
		if (distance_x > 0)
			GoRight();
		else if (distance_x < 0)
			GoLeft();
		else if (distance_y > 0)
			GoDown();
		else if (distance_y < 0)
			GoUp();
		break;
	case 2:
		if (distance_y > 0)
			GoDown();
		else if (distance_y < 0)
			GoUp();
		else if (distance_x > 0)
			GoRight();
		else if (distance_x < 0)
			GoLeft();
	}
	if(old_x == GetX() && old_y == GetY())
		Enemy::Step();
}
