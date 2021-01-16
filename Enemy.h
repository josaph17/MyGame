#include "Matrix.h" 
#include "Personage.h" 
#include "Player.h" 

#pragma once

class Enemy: public Personage
{
public:
	Enemy(Matrix* board, Player* player);/*board �� ����� ����� ��� ����� ������ board,
	�� �����, ��� �� �����, � private ��� public*/
	void eatDown();
	void eatUp();
	void eatRight();
	void eatLeft();
private:
	Player* player;
};














