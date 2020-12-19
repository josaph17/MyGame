#include <windows.h> // для цвета
#include<iostream>
#include<iomanip> //для setw
#include<ctime> //для генерации случайных чисел
#include <conio.h> //для _getch()
using namespace std;


class Matrix {
public:
	Matrix(int rows, int cols);
	~Matrix();
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
	int** arr;//данные
	int rows, cols;//размеры
	int player_i, player_j;
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

Matrix::Matrix(int rows, int cols) //выделение памяти
{
	this->rows = rows;
	this->cols = cols;
	arr = new int* [rows];  //переменная arr будет хранить указатель на указатель  
			//мы создаем массив указателей, мы здесь будем хранить указатели  
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]; /*в каждый элемент который будет хранить указатель на int мы будем присваивать новый динамический массив, размер массива будет соответсвовать переменной colls*/
		//объявление и создание массива, выделение под него памяти5
	}
	player_i = -1; //чтобы не были в зоне видимости поля
	player_j = -1; //чтобы не были в зоне видимости поля
}//коонструктор
Matrix::~Matrix() //полность удаляем нашу ОП после того как поработаем с нашим массивом и он нам станет ненужен
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void Matrix::FillArray(int k) //ф-я заполнения массива данными, &arr т.к.  ассив меняется и адрес тоже
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 0;
		}
	}
	//srand((unsigned int)time(NULL));
	for (int p = 0; p < k;)
	{
		int randomRow = rand() % rows;
		int randomCol = rand() % cols;

		if (arr[randomRow][randomCol] == 0)
		{
			arr[randomRow][randomCol] = 1;
			p++;
		}
		else
			continue;
	}
	for (int p = 0; p < 1;)    //для рандомной 2//////////////////////////////////////
	{
		player_i = rand() % rows;
		player_j = rand() % cols;

		if (arr[player_i][player_j] == 0)
		{
			arr[player_i][player_j] = 2;// игрок
			p++;
		}
		else
			continue;
	}
	for (int p = 0; p < 1;)    //для врагов
	{
		int randomRow = rand() % rows;
		int randomCol = rand() % cols;

		if (arr[randomRow][randomCol] == 0)
		{
			arr[randomRow][randomCol] = 7; //enemy
			p++;
		}
		else
			continue;
	}
}
void Matrix::ShowArray() //вывод массива
{
	//system("cls"); //ф-я очистки экрана (консоли)
	set_cursor(0, 0);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	for (int j = 0; j <= cols + 1; j++)
	{
		if ((j == 0) || (j == cols + 1))
			cout << "+";
		else
			cout << "--";
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
		cout << "|";
		for (int j = 0; j < cols; j++)
		{
			//для получения дискрипптора
			if (arr[i][j] == 0)
			{
				cout << "  ";
			}
			if (arr[i][j] == 1)
			{
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //зеленые
				cout << "[]";
			}
			if (arr[i][j] == 2)
			{
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); //белый
				cout << "()";
			}
			if (arr[i][j] == 7)
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
	for (int j = 0; j <= cols + 1; j++)
	{
		if ((j == 0) || (j == cols + 1))
			cout << "+";
		else
			cout << "--";

	}
	cout << endl;
	/*cout << "Для продолжения работы программы нажмите любую кнопку ";
	cin.get();*/
	cout << endl;
}
void Matrix::PlayerDown()
{
	if ((player_i < 0) || (player_i == rows-1)) // если меньше 0 или на последней строке 
		return; // я выйду из ф-ии
	if (arr[player_i + 1][player_j] == 0)
	{
		arr[player_i][player_j] = 0;
		arr[player_i + 1][player_j] = 2;
		player_i++; //меняем координату игрока
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (arr[player_i + 1][player_j] == 7)
	{
		arr[player_i][player_j] = 0; //игрок становится нулем
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	
}
void Matrix::PlayerUp()
{
	if (player_i <= 0) // если player_i меньше или равно 0 и на последней строке
		return; // я выйду из ф-ии
	if (arr[player_i - 1][player_j] == 0)
	{
		arr[player_i][player_j] = 0;
		arr[player_i - 1][player_j] = 2;
		player_i--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (arr[player_i - 1][player_j] == 7)
	{
		arr[player_i][player_j] = 0;
		player_i = -1;
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Matrix::PlayerRight()
{
	if ((player_j < 0) || (player_j > cols))
		return;
	if (arr[player_i][player_j + 1] == 0)
	{
		arr[player_i][player_j] = 0;
		arr[player_i][player_j + 1] = 2;
		player_j++;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (arr[player_i][player_j + 1] == 7)
	{
		arr[player_i][player_j] = 0;
		player_i = -1;//т.к. меня съели 
		player_j = -1; //т.к. меня съели
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
void Matrix::PlayerLeft()
{
	if (player_j < 0)
		return;
	if (arr[player_i][player_j - 1] == 0)
	{
		arr[player_i][player_j] = 0;
		arr[player_i][player_j - 1] = 2;
		player_j--;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
	if (arr[player_i][player_j - 1] == 7)
	{
		arr[player_i][player_j] = 0;
		player_i = -1;//т.к. меня съели 
		player_j = -1;
		return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
	}
}
//Enemy
void Matrix::EnemyDown()
{
	for (int i = 0; i < rows - 1; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 7) && (arr[i + 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i + 1][j] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
			if ((arr[i][j] == 7) && (arr[i + 1][j] == 2))
			{
				arr[i][j] = 0;
				arr[i + 1][j] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
		}
	}
}
void Matrix::EnemyUp()
{
	for (int i = rows - 1; i > 0; i--) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов  
		/*_____число rows меняется_____*/
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 7) && (arr[i - 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i - 1][j] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
			if ((arr[i][j] == 7) && (arr[i - 1][j] == 2))
			{
				arr[i][j] = 0;
				arr[i - 1][j] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
		}
	}
}
void Matrix::EnemyRight()
{
	for (int i = 0; i < rows; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
	{
		for (int j = 0; j < cols - 1; j++)
		{
			if ((arr[i][j] == 7) && (arr[i][j + 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j + 1] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
			if ((arr[i][j] == 7) && (arr[i][j + 1] == 2))
			{
				arr[i][j] = 0;
				arr[i][j + 1] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
		}
	}
}
void Matrix::EnemyLeft()
{
	for (int i = 0; i < rows; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
	{
		for (int j = cols - 1; j > 0; j--)
		{
			if ((arr[i][j] == 7) && (arr[i][j - 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j - 1] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
			if ((arr[i][j] == 7) && (arr[i][j - 1] == 2))
			{
				arr[i][j] = 0;
				arr[i][j - 1] = 7;
				return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
			}
		}
	}
}
void Matrix::RandomEnemyMove()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 7)//2.4//2.5
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
					EnemyRight();//2.5
					break;

				case 4:
					EnemyLeft();
					break;
				}
				return;// чтобы выйти из ф-ии randomMove послде совершения движения, return выходит из ф-ии в котор
			}
		}
	}
	return;

}

bool Matrix::isGameOver()
{
	bool found = true; 
	if (arr[player_i][player_j] == 2)
	//if ((player_i == -1) || (player_j == -1))
	{
		found = false; 
		return found;
	}
	return found;
}
int main()
{
	srand((unsigned int)time(NULL)); // только здесь 1 раз , последовательность меняется
	setlocale(LC_ALL, "");
	//int rows = 20, cols = 30, k = 10, pattern = 2;
	Matrix* matr = new Matrix(10, 10); //было (20, 30)
	int** arr = NULL; //чтобы создать двумерный динамический массив, создаем указатель на массив указателей
	//cout << "Введите количество строк и столбцов и число единиц (не равное размеру матрицы - 2): " << endl;
	//cin >> rows >> cols >> k; 
	
	bool escape_pressed = false; //для выхода их программы
	bool nowGameOver = false; //глобальная переменная
	//arr = CreateArray(rows, cols);
	matr->FillArray(1); //параметр k - преграда
	matr->ShowArray();
	for (int i = 1; (!escape_pressed) && (!nowGameOver); i++)
	{
		nowGameOver = matr->isGameOver();
		Sleep(70);
		if (i % 5 == 0)
		{
			matr->RandomEnemyMove();
			matr->ShowArray();
		}
		if (_kbhit())
		{
			switch (_getch()) //if else для проверки переменной
			{
			case 27:
				escape_pressed = true;
			case 72:
				matr->PlayerUp();
				matr->ShowArray();
				break;
			case 80:
				matr->PlayerDown();
				matr->ShowArray();
				break;

			case 75:
				matr->PlayerLeft();
				matr->ShowArray();
				break;

			case 77:
				matr->PlayerRight();
				matr->ShowArray();
				break;
			}
		}
	}
	delete matr;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //для получения дискрипптора
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
	cout << endl;
	cout << "Программа завершена." << endl;
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

















