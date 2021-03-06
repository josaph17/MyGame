/*создать food (3 шт, если все съел - победил) точки другого цвета(объекты которые съедает игрок ) и счетчик очков, таймер сколько ты продержался*/
//Режим невидимки для врагов
#include <windows.h> // для цвета
#include <iostream>
#include <iomanip> //для setw
#include <ctime> //для генерации случайных чисел
#include <conio.h> //для _getch()

#include "Matrix.h" //т.к. Matrix.cpp находится там же где и Game.cpp
#include "Personage.h"
#include "Player.h"
#include "Enemy.h"
#include "SmartEnemy.h"
#include "Food.h"

using namespace std;

class Game
{
public:
	Game(int _rows, int _cols);
	~Game();
	void FillBlocks(int k); //ля заполнения игрорвого поля
	void ShowArray();
	void PlayerDown();
	void PlayerUp();
	void PlayerRight();
	void PlayerLeft();
	//у тебя в main-е нигде же не вызывается перемещение вра следовательно, эти функции не нужны
	void randomEnemyArrMove();
	bool isGameOver();
	void KillEnemy();
 private:
	Food** food_arr;
	Matrix* board;  
	Player* player;
	Enemy** enemy_arr;
	int enemyCount;
	int foodCount;
};

void set_cursor(int x = 0, int y = 0)
{
	HANDLE handle; //задал имя заголовка которым будем пользоваться в дальнейшем
	COORD coordinates;  // Задал координаты X и Y. Тип Short - целочисленный знаковый тип
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x; //задаем координаты для X
	coordinates.Y = y; //задаем координаты для Y
	SetConsoleCursorPosition(handle, coordinates); // SetConsoleCursorPosition Установить курсор на поз7ицию
    // заголовка handle в координаты coordinates
}

Game::Game(int _rows, int _cols) //параметры в конструкторе
{
	board = new Matrix(_rows, _cols);
	player = new Player(board); /*при помощи оператора new - создаём объекты,
	а при помощи оператора присваивания - инициализируем переменные (указатели) player и enemy*/
	enemyCount = 10;
	enemy_arr = new Enemy*[enemyCount]; 	//enemy /*Динамическое создание массива. Каждый эл-т массива - указатель на динамический объект*/
	///*Есть класс Enemy. Enemy* - это тип "указатель на объект класса Enemy".
	//Enemy** - это "указатель на указатель на объект класса Enemy" (или "указатель на массив указателей на класс Enemy").*/
	for(int i = 0; i < enemyCount; i++)
	{
		enemy_arr[i] = new SmartEnemy(board, player);
	}
	foodCount = 3;
	food_arr = new Food*[foodCount];
	for (int i = 0; i < foodCount; i++)
	{
		food_arr[i] = new Food(board);
	}
}

Game::~Game() //полность удаляем нашу ОП после того как поработаем с нашим массивом и он нам станет ненужен
{
	delete board;
	delete player;
	for (int i = 0; i < enemyCount; i++)
	{
		delete enemy_arr[i];
	}
	for (int i = 0; i < foodCount; i++)
	{
		delete food_arr[i];
	}
	/*delete []enemy_arr;*/
 }

void Game::FillBlocks(int k) //ф-я заполнения массива данными
{
	for (int p = 0; p < k;)/*преграды*/
	{
		int randomRow = rand() % board->height();
		int randomCol = rand() % board->width();

		if (board->Get(randomRow, randomCol)== 0)
		{
			board->Set(randomRow, randomCol, 1); 
			p++;
		}
		else
			continue;
	}
	ShowArray();
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
			if (board->Get(i, j) == 3) /// еда
			{
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //оранжевый
				cout << "et";
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
	player->GoDown();
	ShowArray();
}
void Game::PlayerUp()
{
	player->GoUp();
	ShowArray();
}
void Game::PlayerRight()
{
	player->GoRight();
	ShowArray();
}
void Game::PlayerLeft()
{
	player->GoLeft();
	ShowArray();
}
void Game::randomEnemyArrMove()
{
	for (int i = 0; i < enemyCount; i++)
	{
		enemy_arr[i]->Step(); /*это ф-я фирт поэтом у будет вызываться из реально созданного объекта*/
	}
	/*smartenemy->Step();
	supersmartenemy->Step();*/
	ShowArray();
}
bool Game::isGameOver()
{
	return !player->isAlive(); //not Alive , т.к. Alive=true
}
void Game::KillEnemy()
{
	//enemy->Die();
	ShowArray();
}

void main()
{
	srand((unsigned int)time(NULL)); // только здесь 1 раз , последовательность меняется
	setlocale(LC_ALL, "");
	//int rows = 20, cols = 30, k = 10, pattern = 2;
	Game* game = new Game(24, 38); //было (20, 30)
	int** arr = NULL; //чтобы создать двумерный динамический массив, создаем указатель на массив указателей
	//cout << "Введите количество строк и столбцов и число единиц (не равное размеру матрицы - 2): " << endl;
	//cin >> rows >> cols >> k; 
	bool escape_pressed = false; //для выхода их программы
	//arr = CreateArray(rows, cols);
	game->FillBlocks(25); //параметр k - преграда
	for (int i = 1; (!escape_pressed) /*&& (!game->isGameOver())*/; i++)
	{
		Sleep(70);
		if (i % 5 == 0) //каждое 5-ое i выводить случайное движение врага, 5:5 = 0, без остатка
		{
			game->randomEnemyArrMove();
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
				break;
			case 80:
				game->PlayerDown();
				break;
			case 75:
				game->PlayerLeft();
				break;
			case 77:
				game->PlayerRight();
				break;
			case '1':
				game->KillEnemy();
				break;
			}
		}
	}
	delete game;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //для получения дискрипптора
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	cout << "Game over." << endl;
}

/*void ShowArray()
const чтобы ф-я гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак поменять константные значения
если бы перед arr поставил значения, то я б не смог присвоить никакие зн-я массиву arr*/
/* НЕ СОГЛАСЕН
ТЫ ВЕДЬ УКАЗАТЕЛЬ ПЕРЕДАЁШЬ, А ПО НЕМУ МОЖНО ДОЙТИ ДО НУЖНЫХ ОБЛАСТЕЙ ПАМЯТИ И МЕНЯТЬ ЗНАЧЕНИЯ
& - ТУТ НЕ НУЖЕН, ПЕРЕДАЧА ПО ССЫЛКЕ НЕ ОБЯЗАТЕЛЬНА
const - ТОЖЕ НЕ НУЖЕН, В НЁМ ВООБЩЕ СМЫСЛЕ НЕТ, ТАК КАК ТЕБЕ НУЖНО ПОМЕНЯТЬ ЗНАЧЕНИЯ
int &k - ЗАЧЕМ ПО ССЫЛКЕ ПЕРЕДАВАТЬ? ТЫ ЖЕ НЕ СОБИРАЕШЬСЯ МЕНЯТЬ ЗНАЧЕНИЕ k
void FillBlocks(int** arr, const int rows, const int cols, int k) - ТАКАЯ СИГНАТУРА НОРМАЛЬНАЯ
						  -- комментарии от Виктора -- */
						  /*const чтобы ф-я гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак поменять константные значения
						  если бы перед arr поставил значения, то я б не смог присвоить никакие зн-я массиву arr*/