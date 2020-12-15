#include <windows.h> // дл€ цвета
#include<iostream>
#include<iomanip> //дл€ setw
#include<ctime> //дл€ генерации случайных чисел
#include <conio.h> //дл€ _getch()
using namespace std; 
int** CreateArray(int rows, int cols) //выделение пам€ти
{
    int** arr = new int* [rows];  //переменна€ arr будет хранить указатель на указатель  
            //мы создаем массив указателей, мы здесь будем хранить указатели  
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols]; /*в каждый элемент который будет хранить указатель на int мы будем присваивать новый динамический массив, размер массива будет соответсвовать переменной colls*/
        //объ€вление и создание массива, выделение под него пам€ти5
    }
    return arr;
}
void DestroyArray(int** arr, int rows, int cols) //полность удал€ем нашу ќѕ после того как поработаем с нашим массивом и он нам станет ненужен
{
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
void FillArray(int** arr, int rows, int cols, int k) //ф-€ заполнени€ массива данными, &arr т.к.  ассив мен€етс€ и адрес тоже
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
    for (int p = 0; p < 1;)    //дл€ рандомной 2//////////////////////////////////////
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
    for (int p = 0; p < 10;)    //дл€ рандомной 2//////////////////////////////////////
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
void ShowArray(int** const arr, const int rows, const int cols) //вывод массива
{
    system("cls"); //ф-€ очистки экрана (консоли)
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
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
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
             //дл€ получени€ дискрипптора
            if (arr[i][j] == 0)
            {
                cout <<"  ";
            }
            if (arr[i][j] == 1)
            {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //зеленые
                cout << "[]";
            }
            if (arr[i][j] == 2)
            {
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); //белый
                cout <<"()";
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
    /*cout << "ƒл€ продолжени€ работы программы нажмите любую кнопку ";
    cin.get();*/
    cout << endl;
}
void ChangeDown(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows - 1; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
    {
        for (int j = 0; j < cols; j++)
        {
            if ((arr[i][j] == 2) && (arr[i + 1][j] == 0))
            {
                arr[i][j] = 0;
                arr[i + 1][j] = 2;          
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
            if ((arr[i][j] == 2) && (arr[i + 1][j] == 7))
            {
                arr[i][j] = 7;
                arr[i + 1][j] = 0;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
        }
    }
}
void ChangeUp(int** const arr, const int rows, const int cols)
{
    for (int i = rows-1; i>0; i--) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов  
        /*_____число rows мен€етс€_____*/
    { 
        for (int j = 0; j < cols; j++)
        {
            if ((arr[i][j] == 2) && (arr[i - 1][j] == 0))
            {
                arr[i][j] = 0;
                arr[i - 1][j] = 2;          
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
            if ((arr[i][j] == 2) && (arr[i - 1][j] == 7))
            {
                arr[i][j] = 7;
                arr[i - 1][j] = 0;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
        }
    }
}
void ChangeRight(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
    {
        for (int j = 0; j < cols-1; j++)
        {
            if ((arr[i][j] == 2) && (arr[i][j + 1] == 0))
            {
                arr[i][j] = 0;
                arr[i][j + 1] = 2;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
            if ((arr[i][j] == 2) && (arr[i][j + 1] == 7))
            {
                arr[i][j] = 7;
                arr[i][j + 1] = 0;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
        }
    }
}
void ChangeLeft(int** const arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов 
    {
        for (int j = cols-1; j >0; j--)
        {
            if ((arr[i][j] == 2) && (arr[i][j - 1] == 0))
            {
                arr[i][j] = 0;
                arr[i][j - 1] = 2;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
            if ((arr[i][j] == 2) && (arr[i][j - 1] == 7))
            {
                arr[i][j] = 7;
                arr[i][j - 1] = 0;
                return; // этот оператор нужен нам чтобы выйти из ф-ии, чтобы цикл прошел 1 раз и вышел
            }
        }
    }
}
//Enemy
void EnemyDown(int** const arr, const int rows, const int cols)
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
void EnemyUp(int** const arr, const int rows, const int cols)
{
    for (int i = rows - 1; i > 0; i--) // ограничение на последнюю строку (rows - 1), т.к. под последней строкой не может быть эл-ов  
        /*_____число rows мен€етс€_____*/
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
void EnemyRight(int** const arr, const int rows, const int cols)
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
void EnemyLeft(int** const arr, const int rows, const int cols)
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
    int** arr = NULL; //чтобы создать двумерный динамический массив, создаем указатель на массив указателей
    cout << "¬ведите количество строк и столбцов и число единиц (не равное размеру матрицы - 2): " << endl;    
    //cin >> rows >> cols >> k;
    if (k < (rows * cols)-2)
    {
        bool escape_pressed = false; //дл€ выхода их программы
        bool nowGameOver =false; //глобальна€ переменна€
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
                switch (_getch()) //if else дл€ проверки переменной
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
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //дл€ получени€ дискрипптора
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //белый
    cout << endl;
    cout << "ѕрограмма завершена." << endl; 
    return 0;
}








/*void ShowArray(int** const arr, const int rows, const int cols)
const чтобы ф-€ гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак помен€ть константные значени€
если бы перед arr поставил значени€, то € б не смог присвоить никакие зн-€ массиву arr*/
/* Ќ≈ —ќ√Ћј—≈Ќ
“џ ¬≈ƒ№ ” ј«ј“≈Ћ№ ѕ≈–≈ƒј®Ў№, ј ѕќ Ќ≈ћ” ћќ∆Ќќ ƒќ…“» ƒќ Ќ”∆Ќџ’ ќЅЋј—“≈… ѕјћя“» » ћ≈Ќя“№ «Ќј„≈Ќ»я
& - “”“ Ќ≈ Ќ”∆≈Ќ, ѕ≈–≈ƒј„ј ѕќ ——џЋ ≈ Ќ≈ ќЅя«ј“≈Ћ№Ќј
const - “ќ∆≈ Ќ≈ Ќ”∆≈Ќ, ¬ Ќ®ћ ¬ќќЅў≈ —ћџ—Ћ≈ Ќ≈“, “ј   ј  “≈Ѕ≈ Ќ”∆Ќќ ѕќћ≈Ќя“№ «Ќј„≈Ќ»я
int &k - «ј„≈ћ ѕќ ——џЋ ≈ ѕ≈–≈ƒј¬ј“№? “џ ∆≈ Ќ≈ —ќЅ»–ј≈Ў№—я ћ≈Ќя“№ «Ќј„≈Ќ»≈ k
void FillArray(int** arr, const int rows, const int cols, int k) - “ј јя —»√Ќј“”–ј Ќќ–ћјЋ№Ќјя
                          -- комментарии от ¬иктора -- */
                          /*const чтобы ф-€ гарантированна пробежала по всем эл-ам  массива, в ф-ии мы не сможем никак помен€ть константные значени€
                          если бы перед arr поставил значени€, то € б не смог присвоить никакие зн-€ массиву arr*/

















