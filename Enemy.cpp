#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy(Matrix* board, Player* player) : Personage(-1, -1, board, 7)
{
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








