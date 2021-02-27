#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(Matrix* _board, Player* _player) : Enemy(_board, _player) //_a , _b : _a , _b
/*��������� Smart Enemy ������ ���� ������� �������, �� ����� �������� � ����������� Enemy*/
{

}

void SmartEnemy::Step()
{
	int distance_x = player->GetX() - GetX();
	int distance_y = player->GetY() - GetY();

	int old_x = GetX(); /*������ ������������ �����, ����� switch*/
	int old_y = GetY();

	int randomMove = 1 + rand() % 2;
	/*��� � ���� ��� ����� � case 1 ��������� �������� ����� ����������� ������ 1 ���, ���� ���� �� ������ ��� break'� � case 2 - �����,
	������� ��� break'� ����� ������ �� ���� ������� � ������� break ������ � ����� ����� - ����� ������� case 2:*/
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
