#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy(Matrix* _board, Player* _player) : Personage(-1, -1, _board, 7)
{
	/*this->*/player = _player;

	SetY(rand() % board->height());
	SetX(rand() % board->width());

	if (board->Get(GetY(), GetX()) == 0) ///
	{
		board->Set(GetY(), GetX(), 7);// враг ///
	}
}

void Enemy::eatDown()
{
	if (board->Get(GetY() + 1, GetX()) == 2)
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() + 1, GetX(), GetValue()); /// GetValue() т.к. у врага зукыщтфпу мфдгу = 7
	//прописать уничтожение игрока
		player->SetX(-1);
		player->SetY(-1);
	}
}
void Enemy::eatUp()
{
	if (board->Get(GetY() - 1, GetX()) == 2)
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() - 1, GetX(), GetValue()); ///
		player->SetX(-1);
		player->SetY(-1);
	}
}
void Enemy::eatRight()
{
	if ((board->Get(GetY(), GetX() + 1) == 0))
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() + 1, GetValue()); ///
		player->SetX(-1);
		player->SetY(-1);
	}
}
void Enemy::eatLeft()
{
	if ((GetX() > 0) && ((board->Get(GetY(), GetX() - 1) == 0)))
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() - 1, GetValue()); ///
		player->SetX(-1);
		player->SetY(-1);
	}
}
void Enemy::Step()
{
	for (int p = 1; p > 0; )
	{
		int randomMove = 1 + rand() % 4;
		switch (randomMove)
		{
		case 1:
			GoDown();
			eatDown();
			break;
		case 2:
			GoUp();
			eatDown();
			break;
		case 3:
			GoRight();
			eatDown();
			break;
		case 4:
			GoLeft();
			eatDown();
			break;
		}
		return;// чтобы выйти из ф-ии randomMove после совершения движения, return выходит из ф-ии в котор
	}
	return;
}







