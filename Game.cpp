/*�������: �-�� ������������ ��������. ������� ����������� ����� ������, ���������� ���-�� ����� ��������� ���������� ������. � �� ������ ���
������ �� �������. �������������� �-�� ������������ � ��� �����. �-� ������� ������. ����� �� �� ��������.� ����������� ������ � ������������ ����������,
������� ����� ����. ����� �� ������*/
#include <windows.h> // ��� �����
#include<iostream>
#include<iomanip> //��� setw
#include<ctime> //��� ��������� ��������� �����
#include <conio.h> //��� _getch() ��� ������� gotoxy() �������� ������ ���������� ������ 
//� ����� � ������������ �,�. ���� ���� �� ���� �� ��������� ���������������, �� ������� �������� �� �����������.
using namespace std;


class Matrix {
public:
	Matrix(int rows, int cols);
	~Matrix();
	void FillArray(int k);
	void ShowArray();
	void ChangeDown();
	void ChangeUp();
	void ChangeRight();
	void ChangeLeft();
	void EnemyDown();
	void EnemyUp();
	void EnemyRight();
	void EnemyLeft();
	void RandomEnemyMove();
	bool isGameOver();
private:
	int** arr;//������
	int rows, cols;//�������
};

void set_cursor(int x = 0, int y = 0)
{
	HANDLE handle; //����� ��� ��������� ������� ����� ������������ � ����������
	COORD coordinates; // ����� ���������� X � Y. ��� Short - ������������� �������� ���
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x; //������ ���������� ��� X
	coordinates.Y = y;//������ ���������� ��� Y
	SetConsoleCursorPosition(handle, coordinates); // SetConsoleCursorPosition ���������� ������ �� �������
		// ��������� handle � ���������� coordinates
}

Matrix::Matrix(int rows, int cols) //��������� ������
{
	this->rows = rows; //��� ����������, ������� ������� � ������
	this->cols = cols;
	arr = new int* [rows];  /*����� ��� ** �.�. � private 26 ��� ���� **arr*/
	/*���������� arr ����� ������� ��������� �� ���������  
	�� ������� ������ ����������, �� ����� ����� ������� ���������*/  
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]; /*� ������ ������� ������� ����� ������� ��������� �� int �� ����� ����������� ����� ������������ ������, ������ ������� ����� �������������� ���������� colls*/
		//���������� � �������� �������, ��������� ��� ���� ������5
	}
}//������������
Matrix::~Matrix() //�������� ������� ���� �� ����� ���� ��� ���������� � ����� �������� � �� ��� ������ �������
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void Matrix::FillArray(int k) //�-� ���������� ������� �������, &arr �.�.  ����� �������� � ����� ����
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
	for (int p = 0; p < 1;)    //��� ��������� 2//////////////////////////////////////
	{
		int randomRow = rand() % rows;
		int randomCol = rand() % cols;

		if (arr[randomRow][randomCol] == 0)
		{
			arr[randomRow][randomCol] = 2;
			p++;
		}
		else
			continue;
	}
	for (int p = 0; p < 1;)    //��� ������
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
void Matrix::ShowArray() //����� �������
{
	//system("cls"); //�-� ������� ������ (�������)
    set_cursor(0, 0);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
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
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
		cout << "|";
		for (int j = 0; j < cols; j++)
		{
			//��� ��������� ������������
			if (arr[i][j] == 0)
			{
				cout << "  ";
			}
			if (arr[i][j] == 1)
			{
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //�������
				cout << "[]";
			}
			if (arr[i][j] == 2)
			{
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); //�����
				cout << "()";
			}
			if (arr[i][j] == 7)
			{
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
				cout << "**";
			}
		}
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
		cout << "|";
		cout << endl;//� ����� ������ ������ ����� �������� �� ������� �� ��������� �������
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
	for (int j = 0; j <= cols + 1; j++)
	{
		if ((j == 0) || (j == cols + 1))
			cout << "+";
		else
			cout << "--";

	}
	cout << endl;
	/*cout << "��� ����������� ������ ��������� ������� ����� ������ ";
	cin.get();*/
	cout << endl;
}
void Matrix::ChangeDown()
{
	for (int i = 0; i < rows - 1; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 2) && (arr[i + 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i + 1][j] = 2;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 2) && (arr[i + 1][j] == 7))
			{
				arr[i][j] = 7;
				arr[i + 1][j] = 0;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::ChangeUp()
{
	for (int i = rows - 1; i > 0; i--) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-��  
		/*_____����� rows ��������_____*/
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 2) && (arr[i - 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i - 1][j] = 2;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 2) && (arr[i - 1][j] == 7))
			{
				arr[i][j] = 7;
				arr[i - 1][j] = 0;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::ChangeRight()
{
	for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = 0; j < cols - 1; j++)
		{
			if ((arr[i][j] == 2) && (arr[i][j + 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j + 1] = 2;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 2) && (arr[i][j + 1] == 7))
			{
				arr[i][j] = 7;
				arr[i][j + 1] = 0;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::ChangeLeft()
{
	for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = cols - 1; j > 0; j--)
		{
			if ((arr[i][j] == 2) && (arr[i][j - 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j - 1] = 2;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 2) && (arr[i][j - 1] == 7))
			{
				arr[i][j] = 7;
				arr[i][j - 1] = 0;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
//Enemy
void Matrix::EnemyDown()
{
	for (int i = 0; i < rows - 1; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 7) && (arr[i + 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i + 1][j] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 7) && (arr[i + 1][j] == 2))
			{
				arr[i][j] = 0;
				arr[i + 1][j] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::EnemyUp()
{
	for (int i = rows - 1; i > 0; i--) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-��  
		/*_____����� rows ��������_____*/
	{
		for (int j = 0; j < cols; j++)
		{
			if ((arr[i][j] == 7) && (arr[i - 1][j] == 0))
			{
				arr[i][j] = 0;
				arr[i - 1][j] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 7) && (arr[i - 1][j] == 2))
			{
				arr[i][j] = 0;
				arr[i - 1][j] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::EnemyRight()
{
	for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = 0; j < cols - 1; j++)
		{
			if ((arr[i][j] == 7) && (arr[i][j + 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j + 1] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 7) && (arr[i][j + 1] == 2))
			{
				arr[i][j] = 0;
				arr[i][j + 1] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
		}
	}
}
void Matrix::EnemyLeft()
{
	for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
	{
		for (int j = cols - 1; j > 0; j--)
		{
			if ((arr[i][j] == 7) && (arr[i][j - 1] == 0))
			{
				arr[i][j] = 0;
				arr[i][j - 1] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
			}
			if ((arr[i][j] == 7) && (arr[i][j - 1] == 2))
			{
				arr[i][j] = 0;
				arr[i][j - 1] = 7;
				return; // ���� �������� ����� ��� ����� ����� �� �-��, ����� ���� ������ 1 ��� � �����
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
				//srand((unsigned int)time(NULL)); ���� �������� 1 ���, � �� �������� ���������� �����, ����� �-� �� �������� ������ ������ �����.
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
				return;// ����� ����� �� �-�� randomMove ������ ���������� ��������, return ������� �� �-�� � �����
			}
		}
	}
	return;

}
bool Matrix::isGameOver()
{
	bool found = true;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 2)
			{
				found = false;
				return found;;
			}
		}
	}
	return found;
}


int main()
{
	srand((unsigned int)time(NULL)); /* ������ ����� 1 ��� , ������������������ ��������. � ������ main(), �.�. ���� srand ��������� � �-��
									 ���� � �-�� ��������� ����� ������, � ����� ��������� ��������� �� ������ ���������, ������� ����� time(NULL)
									 ����������, �� ������ ����� srabd ���������� ���������� �����-�� ������������������ �����*/
	setlocale(LC_ALL, "");
	//int rows = 20, cols = 30, k = 10, pattern = 2;
	/*���� ������� 4 ������ matr, enemy, �����, game*/
	Matrix* matr = new Matrix(20, 30); 
	int** arr = NULL; //����� ������� ��������� ������������ ������, ������� ��������� �� ������ ����������
	//cout << "������� ���������� ����� � �������� � ����� ������ (�� ������ ������� ������� - 2): " << endl;
	//cin >> rows >> cols >> k; 
	
	bool escape_pressed = false; //��� ������ �� ���������
	bool nowGameOver = false; //���������� ����������
	//arr = CreateArray(rows, cols);
	matr->FillArray(1); //�������� k - ��������
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
			switch (_getch()) //if else ��� �������� ����������
			{
			case 27:
				escape_pressed = true;
			case 72:
				matr->ChangeUp();
				matr->ShowArray();
				break;
			case 80:
				matr->ChangeDown();
				matr->ShowArray();
				break;

			case 75:
				matr->ChangeLeft();
				matr->ShowArray();
				break;

			case 77:
				matr->ChangeRight();
				matr->ShowArray();
				break;
			}
		}
	}
	delete matr;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //��� ��������� ������������
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
	cout << endl;
	cout << "��������� ���������." << endl;
	return 0;
}








/*void ShowArray()
const ����� �-� �������������� ��������� �� ���� ��-��  �������, � �-�� �� �� ������ ����� �������� ����������� ��������
���� �� ����� arr �������� ��������, �� � � �� ���� ��������� ������� ��-� ������� arr*/
/* �� ��������
�� ���� ��������� ���������, � �� ���� ����� ����� �� ������ �������� ������ � ������ ��������
& - ��� �� �����, �������� �� ������ �� �����������
const - ���� �� �����, � ͨ� ������ ������ ���, ��� ��� ���� ����� �������� ��������
int &k - ����� �� ������ ����������? �� �� �� ����������� ������ �������� k
void FillArray(int** arr, const int rows, const int cols, int k) - ����� ��������� ����������
						  -- ����������� �� ������� -- */
						  /*const ����� �-� �������������� ��������� �� ���� ��-��  �������, � �-�� �� �� ������ ����� �������� ����������� ��������
						  ���� �� ����� arr �������� ��������, �� � � �� ���� ��������� ������� ��-� ������� arr*/

















