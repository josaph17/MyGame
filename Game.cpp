#include <windows.h> // для цвета
#include <iostream>
#include <iomanip> //для setw
#include <ctime> //для генерации случайных чисел
#include <conio.h> //для _getch()

#include "Matrix.cpp" //т.к. Matrix.cpp находится там же где и Game.cpp

using namespace std;

class Game 
{
public:
	Game(int rows, int cols);
	~Game();
	void FillArray(int k); //ля заполнения игрорвого поля
	void ShowArray();
	void PlayerDown();
	void PlayerUp();
	void PlayerRight();
	void PlayerLeft();
	void EnemyDown();
	void EnemyUp();
	void EnemyRight();
	void EnemyLeft();
	void RandomEnemyMove();
	bool isGameOver();
private:
	Matrix*board;
	int player_i, player_j;
	int enemy_i, enemy_j;
};

void set_cursor(int x = 0, int y = 0)
{
	HANDLE handle; //задал имя заголовка которым будем пользоваться в дальнейшем
	COORD coordinates;  // Задал координаты X и Y. Тип Short - целочисленный знаковый тип
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x; //задаем координаты для X
	coordinates.Y = y; //задаем координаты для Y
	SetConsoleCursorPosition(handle, coordinates); // SetConsoleCursorPosition Установить курсор на позицию
    // заголовка handle в координаты coordinates
}
Game::Game(int rows, int cols) //параметры в конструкторе
{
	board = new Matrix(20, 20);
	player_i = -1; //это означает что игрока нет
	player_j = -1; //это означает что игрока нет
	enemy_i = -1;
	enemy_j = -1;
}//коонструктор
Game::~Game() //полность удаляем нашу ОП после того как поработаем с нашим массивом и он нам станет ненужен
{
	delete board;
}

void Game::FillArray(int k) //ф-я заполнения массива данными, &arr т.к.  ассив меняется и адрес тоже
{
	//srand((unsigned int)time(NULL));
	for (int p = 0; p < k;)
	{
		int randomRow = rand() % board->height();
		int randomCol = rand() % board->width();

		if (board->Get(randomRow, randomCol)== 0)
		{
			board->Set(randomRow, randomCol, 1); //преграда
			p++;
		}
		else
			continue;
	}
	for (int p = 0; p < 1;)    //для рандомной 2//////////////////////////////////////
	{
		player_i = rand() % board->height();
		player_j = rand() % board->width();

		if (board->Get(player_i, player_j) == 0) ///
		{
			board->Set(player_i, player_j, 2);// игрок ///
			p++;
		}
		else
			continue;  
	}
	for (int p = 0; p < 1;)    //для врагов
	{
		enemy_i = rand() % board->height(); //не ставить int т.к. это новые перем
		enemy_j = rand() % board->width();

		
		if (board->Get(enemy_i, enemy_j) == 0) ///
		{
			board->Set(enemy_i, enemy_j, 7);// игрок ///
			p++;
		}
		else
			continue;
	}
}
void Game::ShowArray() //вывод массива
{
	//system("cls"); //ф-я очистки экрана (консоли)
	set_cursor(0, 0);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	cout << "+";
	for (int j = 0; j < board->width(); j++)
		cout << "--";
	cout << "+" << endl;
	for (int i = 0; i < board->height(); i++)
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
		cout << "|";
		for (int j = 0; j < board->width(); j++)
		{
			//для получения дискрипптора
			if (board->Get(i, j) == 0) ///  		
			{
				cout << "  ";
			}
			if (board->Get(i, j) == 1) ///
			{
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //зеленые
				cout << "[]";
			}
			if (board->Get(i, j) == 2) ///
			{
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); //белый
				cout << "()";
			}
			if (board->Get(i, j) == 7) ///
			{
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //синий
				cout << "**";
			}
		}
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
		cout << "|";
		cout << endl;//в конце каждой строки будет отвечать за переход на следующую строчку
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	cout << "+";
	for (int j = 0; j < board->width(); j++)
		cout << "--";
	cout << "+" << endl;
	/*cout << "Для продолжения работы программы нажмите любую кнопку ";
	cin.get();*/
	cout << endl;
}
void Game::PlayerDown()
{
	if ((player_i < 0) || (player_i == board->height()-1)) // если меньше 0 или на последней строке 
		return; // я выйду из ф-ии
	if (board->Get(player_i+1, player_j) == 0) /// board->Get(player_i, player_j)
	{
		board->Set(player_i, player_j, 0); ///
		board->Set(player_i+1, player_j, 2); ///
		player_i++; //меняем координату игрока
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(player_i + 1, player_j) == 7) /// 
	{
		board->Set(player_i, player_j, 0); //игрок становится нулем /// 
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	
}
void Game::PlayerUp()
{
	if (player_i <= 0) // если player_i меньше или равно 0 и на последней строке
		return; // я выйду из ф-ии
	if (board->Get(player_i - 1, player_j) == 0)  ///
	{
		board->Set(player_i, player_j, 0); ///
		board->Set(player_i - 1, player_j, 2); ///
		player_i--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(player_i - 1, player_j) == 7) ///
	{
		board->Set(player_i, player_j, 0); ///
		player_i = -1;
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::PlayerRight()
{
	if ((player_j < 0) || (player_j > board->width()))
		return;
	if (board->Get(player_i, player_j+1) == 0)
	{
		board->Set(player_i, player_j, 0);
		board->Set(player_i, player_j + 1, 2);
		player_j++;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(player_i, player_j + 1) == 7)
	{
		board->Set(player_i, player_j, 0);
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::PlayerLeft()
{
	if (player_j < 0)
		return;
	if (board->Get(player_i, player_j - 1) == 0)
	{
		board->Set(player_i, player_j, 0);
		board->Set(player_i, player_j - 1, 2);
		player_j--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(player_i, player_j - 1) == 7)
	{
		board->Set(player_i, player_j, 0);
		player_i = -1;//т.к. меня съели 
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::EnemyDown()
{
	if ((enemy_i < 0) || (enemy_i == board->height() - 1)) // если меньше 0 или на последней строке 
		return; // я выйду из ф-ии
	if (board->Get(enemy_i + 1, enemy_j) == 0) //	if (board->Get(enemy_i+1, enemy_j) == 0)
	{
		board->Set(enemy_i, enemy_j, 0); //		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i+1, enemy_j, 7);
		enemy_i++; //меняем координату игрока
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(enemy_i + 1, enemy_j) == 2) //если враг встретит игрока
	{
		board->Set(enemy_i, enemy_j, 0);  //игрок становится нулем
		board->Set(enemy_i + 1, enemy_j, 7);
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::EnemyUp()
{
	if (enemy_i <= 0) // если player_i меньше или равно 0 и на последней строке
		return; // я выйду из ф-ии
	if (board->Get(enemy_i - 1, enemy_j) == 0)
	{
		board->Set(enemy_i, enemy_j, 0); 
		board->Set(enemy_i - 1, enemy_j, 7);
		enemy_i--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(enemy_i - 1, enemy_j) == 2) 
	{
		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i - 1, enemy_j, 7);
		player_i = -1;
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::EnemyRight()
{
	if ((enemy_j < 0) || (enemy_j > board->width()))
		return;
	if (board->Get(enemy_i, enemy_j + 1) == 0) 
	{
		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i, enemy_j+1, 7);
		enemy_j++;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(enemy_i, enemy_j + 1) == 2)
	{
		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i, enemy_j + 1, 7);
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::EnemyLeft()
{
	if (enemy_i < 0)
		return;
	if (board->Get(enemy_i, enemy_j - 1) == 0)
	{
		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i, enemy_j - 1, 7);
		enemy_j--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (board->Get(enemy_i, enemy_j - 1) == 2)
	{
		board->Set(enemy_i, enemy_j, 0);
		board->Set(enemy_i, enemy_j - 1, 7);
		player_i = -1;//т.к. меня съели 
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Game::RandomEnemyMove()
{
	for (int p=1; p>0; )
	{
		//srand((unsigned int)time(NULL)); надо вызывать 1 раз, а то вызывают одинаковые числа, здесь ф-я не успевает выдать другое числа.
		int randomMove = 1 + rand() % 4;
		switch (randomMove)
		{
		case 1:
			EnemyDown();
			break;
		case 2:
			EnemyUp();
			break;
		case 3:
			EnemyRight();
			break;
		case 4:
			EnemyLeft();
			break;
		}
		return;// чтобы выйти из ф-ии randomMove после совершения движения, return выходит из ф-ии в котор
	}
	return;
}
bool Game::isGameOver()
{
	return (player_i == -1) && (player_j == -1);
	//player_j == -1 //если они равны -1, то это выражени будет true
}



int main()
{
	srand((unsigned int)time(NULL)); // только здесь 1 раз , последовательность меняется
	setlocale(LC_ALL, "");
	//int rows = 20, cols = 30, k = 10, pattern = 2;
	Game* game = new Game(10, 10); //было (20, 30)
	int** arr = NULL; //чтобы создать двумерный динамический массив, создаем указатель на массив указателей
	//cout << "Введите количество строк и столбцов и число единиц (не равное размеру матрицы - 2): " << endl;
	//cin >> rows >> cols >> k; 
	
	bool escape_pressed = false; //для выхода их программы
	//arr = CreateArray(rows, cols);
	game->FillArray(1); //параметр k - преграда
	game->ShowArray();
	for (int i = 1; (!escape_pressed) && (!game->isGameOver()); i++)
	{
		Sleep(70);
		if (i % 5 == 0) //каждое 5-ое i выводить случайное движение врага, 5:5 = 0, без остатка
		{
			game->RandomEnemyMove();
			game->ShowArray();
		}
		if (_kbhit())
		{
			switch (_getch()) //if else для проверки переменной
			{
			case 27:
				escape_pressed = true;
				break;
			case 72:
				game->PlayerUp();
				game->ShowArray();
				break;
			case 80:
				game->PlayerDown();
				game->ShowArray();
				break;

			case 75:
				game->PlayerLeft();
				game->ShowArray();
				break;

			case 77:
				game->PlayerRight();
				game->ShowArray();
				break;
			}
		}
	}
	delete game;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //для получения дискрипптора
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	cout << "Game over." << endl;
	return 0;
}








/*void ShowArray()
const чтобы ф-я гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак поменять константные значения
если бы перед arr поставил значения, то я б не смог присвоить никакие зн-я массиву arr*/
/* НЕ СОГЛАСЕН
ТЫ ВЕДЬ УКАЗАТЕЛЬ ПЕРЕДАЁШЬ, А ПО НЕМУ МОЖНО ДОЙТИ ДО НУЖНЫХ ОБЛАСТЕЙ ПАМЯТИ И МЕНЯТЬ ЗНАЧЕНИЯ
& - ТУТ НЕ НУЖЕН, ПЕРЕДАЧА ПО ССЫЛКЕ НЕ ОБЯЗАТЕЛЬНА
const - ТОЖЕ НЕ НУЖЕН, В НЁМ ВООБЩЕ СМЫСЛЕ НЕТ, ТАК КАК ТЕБЕ НУЖНО ПОМЕНЯТЬ ЗНАЧЕНИЯ
int &k - ЗАЧЕМ ПО ССЫЛКЕ ПЕРЕДАВАТЬ? ТЫ ЖЕ НЕ СОБИРАЕШЬСЯ МЕНЯТЬ ЗНАЧЕНИЕ k
void FillArray(int** arr, const int rows, const int cols, int k) - ТАКАЯ СИГНАТУРА НОРМАЛЬНАЯ
						  -- комментарии от Виктора -- */
						  /*const чтобы ф-я гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак поменять константные значения
						  если бы перед arr поставил значения, то я б не смог присвоить никакие зн-я массиву arr*/

















