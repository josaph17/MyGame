#include "Matrix.h" 
#include "Personage.h" 
#pragma once

class Player : public Personage
{
public:
	Player(Matrix* board);
	void destroyDown();
	void destroyUp();
	void destroyRight();
	void destroyLeft();
};














