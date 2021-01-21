#include "Personage.h"
#include "Matrix.h" 
#include "Player.h" 

Player::Player(Matrix* _board) : Personage(-1, -1, _board, 2)
{ 
	SetY(rand() % board->height()); //для i
	SetX(rand() % board->width()); // было player_j = rand() % board->width()

	if (board->Get(GetY(), GetX()) == 0) ///
	{
		board->Set(GetY(), GetX(), 2);// игрок ///
	}
}

void Player::destroyDown()
{ 
	if (board->Get(GetY() + 1, GetX()) == 7)
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() + 1, GetX(), 7); /// GetValue() т.к. у врага зукыщтфпу мфдгу = 7
	}
}
void Player::destroyUp()
{
	if (board->Get(GetY() - 1, GetX()) == 7)
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY() - 1, GetX(), 7); ///
	}
}
void Player::destroyRight()
{
	if ((board->Get(GetY(), GetX() + 1) == 7))
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() + 1, 7); ///
	}
}
void Player::destroyLeft()
{
	if ((GetX() > 0) && ((board->Get(GetY(), GetX() - 1) == 7)))
	{
		board->Set(GetY(), GetX(), 0); ///
		board->Set(GetY(), GetX() - 1, 7); ///
	}
}
bool Player::isAlive()
{
	return (GetY() == -1) && (GetX() == -1);
	//return player->isDead();
	//player_j == -1 //если они равны -1, то это выражени будет true
}











