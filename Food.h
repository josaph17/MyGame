#include <iostream>

#include "Matrix.h" 
#include "Personage.h" 

#pragma once

class Food: public Personage
{
public:
	Food(Matrix* /*_board*/);/*board не нужно иначе это будет другой board,
	не важно, где он будет, в private или public*/
};