#pragma once
//#include <vector>
#include "Enemy.h"
class SmartEnemy :public Enemy
{
public:
	SmartEnemy(Matrix*, Player*);
	virtual void Step();
/*player тоже наследуется, все насл-ся просто доступа нет, для доступа enemy вогнал в prootected в Enemy.cpp, либо гетер сделать */
};

