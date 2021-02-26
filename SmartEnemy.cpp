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

	int randomMove = 1 + rand() % 2;
	switch (randomMove)
	{
	case 1:
		if (distance_x > 0)
		{
			GoRight();
			break;
		}
		else if (distance_x < 0)
		{
			GoLeft();
			break;
		}
		else
		{
			if (distance_y > 0)
			{
				GoDown();
				break;
			}
			else if (distance_y < 0)
			{
				GoUp();
				break;
			}
		}
	case 2:
		if (distance_y > 0)
		{
			GoDown();
			break;
		}
		else if (distance_y < 0)
		{
			GoUp();
			break;
		}
		else
		{
			if (distance_x > 0)
			{
				GoRight();
				break;
			}
			else if (distance_x < 0)
			{
				GoLeft();
				break;
			}
		}
	}
}
