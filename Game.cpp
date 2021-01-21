#include <windows.h> // для цвета
#include <iostream>
#include <iomanip> //для setw
#include <ctime> //для генерации случайных чисел
#include <conio.h> //для _getch()

#include "Matrix.h" //т.к. Matrix.cpp находится там же где и Game.cpp
#include "Personage.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game
{
public:
	Game(int rows, int cols);
	~Game();
	void FillBlocks(int k); //ля заполнения игрорвого поля
	void ShowArray();
	void PlayerDown();
	void PlayerUp();
	void PlayerRight();
	void PlayerLeft();
	//у тебя в main-е нигде же не вызывается перемещение вра следовательно, эти функции не нужны
	void RandomEnemyMove();
	bool isGameOver();
 private:
	Matrix* board;
	Player* player;
	Enemy* enemy;
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
	enemy = new Enemy(board, player);
}//коонструктор
Game::~Game() //полность удаляем нашу ОП после того как поработаем с нашим массивом и он нам станет ненужен
{
	delete board;
	delete player;
	delete enemy;
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
	player->GoDown();
}
void Game::PlayerUp()
{
	player->GoUp();
}
void Game::PlayerRight()
{
	player->GoRight();
}
void Game::PlayerLeft()
{
	player->GoLeft();
}
void Game::RandomEnemyMove()
{
	enemy->Step();
}
bool Game::isGameOver()
{
	return player->isAlive();
	
}



int main()
{
	srand((unsigned int)time(NULL)); // только здесь 1 раз , последовательность меняется
	setlocale(LC_ALL, "");
	//int rows = 20, cols = 30, k = 10, pattern = 2;
	Game* game = new Game(20, 20); //было (20, 30)
	int** arr = NULL; //чтобы создать двумерный динамический массив, создаем указатель на массив указателей
	//cout << "Введите количество строк и столбцов и число единиц (не равное размеру матрицы - 2): " << endl;
	//cin >> rows >> cols >> k; 
	
	bool escape_pressed = false; //для выхода их программы
	//arr = CreateArray(rows, cols);
	game->FillBlocks(1); //параметр k - преграда
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
void FillBlocks(int** arr, const int rows, const int cols, int k) - ТАКАЯ СИГНАТУРА НОРМАЛЬНАЯ
						  -- комментарии от Виктора -- */
						  /*const чтобы ф-я гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак поменять константные значения
						  если бы перед arr поставил значения, то я б не смог присвоить никакие зн-я массиву arr*/

















