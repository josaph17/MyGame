#pragma once
//#include <vector>
#include "Enemy.h"
class SmartEnemy :public Enemy
{
public:
	SmartEnemy(Matrix*, Player*);
	virtual void Step();
/*player ���� �����������, ��� ����-�� ������ ������� ���, ��� ������� enemy ������ � prootected � Enemy.cpp, ���� ����� ������� */
};

