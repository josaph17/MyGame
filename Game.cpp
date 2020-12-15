#include <windows.h> // ��� �����
#include<iostream>
#include<iomanip> //��� setw
#include<ctime> //��� ��������� ��������� �����
#include <conio.h> //��� _getch()
using namespace std; 
int** CreateArray(int rows, int cols) //��������� ������
{
    int** arr = new int* [rows];  //���������� arr ����� ������� ��������� �� ���������  
            //�� ������� ������ ����������, �� ����� ����� ������� ���������  
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols]; /*� ������ ������� ������� ����� ������� ��������� �� int �� ����� ����������� ����� ������������ ������, ������ ������� ����� �������������� ���������� colls*/
        //���������� � �������� �������, ��������� ��� ���� ������5
    }
    return arr;
}
void DestroyArray(int** arr, int rows, int cols) //�������� ������� ���� �� ����� ���� ��� ���������� � ����� �������� � �� ��� ������ �������
{
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
void FillArray(int** arr, int rows, int cols, int k) //�-� ���������� ������� �������, &arr �.�.  ����� �������� � ����� ����
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 0;
        }
    }
    srand((unsigned int)time(NULL));
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
    for (int p = 0; p < 10;)    //��� ��������� 2//////////////////////////////////////
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
void ShowArray(int** const arr, const int rows, const int cols) //����� �������
{
    system("cls"); //�-� ������� ������ (�������)
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
    for (int j = 0; j <= cols+1; j++)
    {
        if ((j==0) || (j==cols+1))
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
                cout <<"  ";
            }
            if (arr[i][j] == 1)
            {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //�������
                cout << "[]";
            }
            if (arr[i][j] == 2)
            {
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); //�����
                cout <<"()";
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
void ChangeDown(int** const arr, const int rows, const int cols)
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
void ChangeUp(int** const arr, const int rows, const int cols)
{
    for (int i = rows-1; i>0; i--) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-��  
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
void ChangeRight(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
    {
        for (int j = 0; j < cols-1; j++)
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
void ChangeLeft(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++) // ����������� �� ��������� ������ (rows - 1), �.�. ��� ��������� ������� �� ����� ���� ��-�� 
    {
        for (int j = cols-1; j >0; j--)
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
void EnemyDown(int** const arr, const int rows, const int cols)
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
void EnemyUp(int** const arr, const int rows, const int cols)
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
void EnemyRight(int** const arr, const int rows, const int cols)
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
void EnemyLeft(int** const arr, const int rows, const int cols)
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
void RandomEnemyMove(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 7)
            {
                srand((unsigned int)time(NULL));
                int randomMove = 1 + rand() % 4;
                switch (randomMove)
                {
                case 1:
                    EnemyDown(arr, rows, cols);
                case 2:
                    EnemyUp(arr, rows, cols);
                    break;
                case 3:
                    EnemyRight(arr, rows, cols);
                    break;

                case 4:
                    EnemyLeft(arr, rows, cols);
                    break;
                }
            }
        }
    }
    return;

}
bool isGameOver(int** const arr, const int rows, const int cols)
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
    setlocale(LC_ALL, "");
    int rows=20, cols=30, k=10, pattern=2;
    int** arr = NULL; //����� ������� ��������� ������������ ������, ������� ��������� �� ������ ����������
    cout << "������� ���������� ����� � �������� � ����� ������ (�� ������ ������� ������� - 2): " << endl;    
    //cin >> rows >> cols >> k;
    if (k < (rows * cols)-2)
    {
        bool escape_pressed = false; //��� ������ �� ���������
        bool nowGameOver =false; //���������� ����������
        arr = CreateArray(rows, cols);
        FillArray(arr, rows, cols, k);
        ShowArray(arr, rows, cols);
        for (int i=1;(!escape_pressed)&&(!nowGameOver);i++)
        {
            nowGameOver = isGameOver(arr, rows, cols);  
            Sleep(70);
            if (i % 5 == 0)
            {
                RandomEnemyMove(arr, rows, cols);
                ShowArray(arr, rows, cols);
            }           
            if (_kbhit())
            {
                switch (_getch()) //if else ��� �������� ����������
                {
                case 27:
                    escape_pressed = true;
                case 72:
                    ChangeUp(arr, rows, cols);
                    ShowArray(arr, rows, cols);
                    break;
                case 80:
                    ChangeDown(arr, rows, cols);
                    ShowArray(arr, rows, cols);
                    break;

                case 75:
                    ChangeLeft(arr, rows, cols);
                    ShowArray(arr, rows, cols);
                    break;

                case 77:
                    ChangeRight(arr, rows, cols);
                    ShowArray(arr, rows, cols);
                    break;
                }
            }          
        }
        DestroyArray(arr, rows, cols);
    }
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //��� ��������� ������������
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //�����
    cout << endl;
    cout << "��������� ���������." << endl; 
    return 0;
}








/*void ShowArray(int** const arr, const int rows, const int cols)
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

















