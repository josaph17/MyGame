#include <iostream>

#include "Matrix.h" 
#include "Personage.h" 
#include "Player.h" 

#pragma once

class Enemy: public Personage
{
public:
	Enemy(Matrix* /*_board*/, Player* /*_player*/);/*board �� ����� ����� ��� ����� ������ board,
	�� �����, ��� �� �����, � private ��� public*/
	void GoDown();
	void GoUp();
	void GoRight();
	void GoLeft();
	void Step();
private:
	Player* player;
};














