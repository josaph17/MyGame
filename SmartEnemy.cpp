#include "Personage.h"
#include "Matrix.h" 
#include "Player.h"
#include "Enemy.h"
#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(Matrix* a, Player* b) : Enemy(a, b) //_board , _player : _board , _player
/*��������� Smart Enemy ������ ���� ������� �������, �� ����� �������� � ����������� Enemy*/
{

}

void SmartEnemy::Step()
{

}