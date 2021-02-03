#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy(Matrix* _board, Player* _player) : Personage(-1, -1, _board, 7)
{
	/*this->*/player = _player;
	while (true)
	{
		int y = rand() % board->height();
		int x = rand() % board->width();
		if (board->isExistAndEmpty(y, x))
		{
			SetY(y);
			SetX(x);
			board->Set(y, x, 7);
			break;
		}
	}
}

void Enemy::eatDown()
{
	if ((isAlive() && player->isAlive()) && GetY() + 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	GoDown();
}
void Enemy::eatUp()
{
	if ((isAlive() && player->isAlive()) && GetY() - 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	GoUp();
}
void Enemy::eatRight()
{
	if ((isAlive() && player->isAlive()) && GetX() + 1 == player->GetX() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	GoRight();
}
void Enemy::eatLeft()
{
	if ((isAlive() && player->isAlive()) && GetX() - 1 == player->GetX() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	GoLeft();
}
void Enemy::Step()
{
	for (int p = 1; p > 0; )
	{
		int randomMove = 1 + rand() % 4;
		switch (randomMove)
		{
		case 1:
			eatDown();
			break;
		case 2:
			eatUp();
			break;
		case 3:
			eatRight();
			break;
		case 4:
			eatLeft();
			break;
		}
		return;// чтобы выйти из ф-ии randomMove после совершения движения, return выходит из ф-ии в котор
	}
	return;
}








