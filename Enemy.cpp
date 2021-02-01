#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy(Matrix* _board, Player* _player) : Personage(-1, -1, _board, 7)
{
	/*this->*/player = _player;
	//if ((SetY(rand() % board->height()) != player->SetY(rand() % board->height())) && (SetX(rand() % board->width()) != player->SetX(rand() % board->width())))
	//{
	//	board->Set(GetY(), GetX(), 7);//
	//}
	SetY(rand() % board->height());
	SetX(rand() % board->width());
	if ((board->Get(GetY(), GetX()) == 0) && (board->Get(GetY(), GetX()) != 2)) ///
	{
		board->Set(GetY(), GetX(), 7);// враг ///
	}
}

void Enemy::eatDown()
{
	if ((isAlive() && player->isAlive()) && GetY() + 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() + 1, GetX(), GetValue()); /// GetValue() т.к. у врага зукыщтфпу мфдгу = 7
		SetY(GetY() + 1);
		player->Die();
	}
	else
		GoDown();
}
void Enemy::eatUp()
{
	if ((isAlive() && player->isAlive()) && GetY() - 1 == player->GetY() && GetX() == player->GetX()) //если враг может съесть игрока внизу
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() - 1, GetX(), GetValue()); ///
		SetY(GetY() - 1);
		player->Die();
	}
	else
		GoUp();
}
void Enemy::eatRight()
{
	if ((isAlive() && player->isAlive()) && GetX() + 1 == player->GetY() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() + 1, GetValue()); ///
		SetX(GetX() + 1);
		player->Die();
	}
	else
		GoRight();
}
void Enemy::eatLeft()
{
	if ((isAlive() && player->isAlive()) && GetX() - 1 == player->GetY() && GetY() == player->GetY()) //если враг может съесть игрока внизу
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() - 1, GetValue()); ///
		SetX(GetX() - 1);
		player->Die();
	}
	else
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








