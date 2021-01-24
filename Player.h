#include "Matrix.h" 
#include "Personage.h" 
#include <iostream>
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














