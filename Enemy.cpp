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

void Enemy::GoDown()
{
	if ((isAlive() && player->isAlive()) && GetY() + 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	Personage::GoDown();
}
void Enemy::GoUp()
{
	if ((isAlive() && player->isAlive()) && GetY() - 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	Personage::GoUp();
}
void Enemy::GoRight()
{
	if ((isAlive() && player->isAlive()) && GetX() + 1 == player->GetX() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	Personage::GoRight();
}
void Enemy::GoLeft()
{
	if ((isAlive() && player->isAlive()) && GetX() - 1 == player->GetX() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		player->Die();
	}
	Personage::GoLeft();
}
void Enemy::Step()
{
	int randomMove = 1 + rand() % 4;
	switch (randomMove)
	{
	case 1:
		GoDown();
		break;
	case 2:
		GoUp();
		break;
	case 3:
		GoRight();
		break;
	case 4:
		GoLeft();
		break;
	}	
}








