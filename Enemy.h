#include "Matrix.h" 
#include "Personage.h" 
#include "Player.h" 

#pragma once

class Enemy: public Personage
{
public:
	Enemy(Matrix* /*_board*/, Player* /*_player*/);/*board не нужно иначе это будет другой board,
	не важно, где он будет, в private или public*/
	void eatDown();
	void eatUp();
	void eatRight();
	void eatLeft();
private:
	Player* player;
};














