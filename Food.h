#include <iostream>

#include "Matrix.h" 
#include "Personage.h" 

#pragma once

class Food: public Personage
{
public:
	Food(Matrix* /*_board*/);/*board �� ����� ����� ��� ����� ������ board,
	�� �����, ��� �� �����, � private ��� public*/
};