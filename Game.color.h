#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include<fstream>
#include<windows.h>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int a[5][5], b[5][5];
void show_goal();
void show_initial();
void initialize(int arr[5][5]);
bool is_goal(int arr[5][5], int arr2[5][5]);
bool is_solvable(int arr1[5][5], int arr2[5][5]);
int inverse_count(int arr[5][5]);
void make_move(int arr[5][5], char move);
void print_path();

char path[1500];
int turn = 0;
void show_initial()
{
    SetConsoleTextAttribute(h, 1);
    cout << "\ninitial state:" << endl<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (b[i][j] == 0)
            {
                cout << "\t" << " ";
            }
            else
            {
                cout << "\t" << b[i][j];
            }
        }
        cout << endl;
    }
}
void show_goal()
{
    SetConsoleTextAttribute(h, 2);
    cout << "Goal state:\n\n" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] == 0)
            {
                cout << "\t" << " ";
            }
            else
            {
                cout << "\t" << a[i][j];
            }
        }
        cout << endl;
    }
}
void initialize(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = -(2 * i + j) - 1;
        }
    }
    int k;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 25;
            k = 0;
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    if (arr[i][j] == arr[x][y])
                    {
                        k++;
                    }
                }
            }
            if (k > 1)
            {
                j--;
            }
        }

    }
}
bool is_goal(int arr1[5][5], int arr2[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    SetConsoleTextAttribute(h, 6);
    cout << "You Win";
    return true;
}
bool is_solvable(int arr1[5][5], int arr2[5][5])
{
    if (inverse_count(arr1) % 2 == inverse_count(arr2) % 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int inverse_count(int arr[5][5])
{
    int count = 0;
    for (int i = 0; i < 25; i++)
    {
        int num = arr[i / 5][i % 5];
        for (int j = i; j < 25; j++)
        {
            if (num > arr[j / 5][j % 5])
            {
                count++;
            }
        }
    }
    return count;
}
void make_move(int arr[5][5], char move)
{
    SetConsoleTextAttribute(h, 6);
    int r, c;
    for (int i = 0; i < 25; i++)
    {
        if (arr[i / 5][i % 5] == 0)
        {
            r = i / 5, c = i % 5;
            break;
        }
    }
    int temp;
    switch (move)
    {
    case 'w':
        if (r != 4)
        {
            path[turn++] = 'U';
            temp = arr[r][c];
            arr[r][c] = arr[r + 1][c];
            arr[r + 1][c] = temp;
        }
        break;
    case 's':
        if (r != 0)
        {
            path[turn++] = 'D';
            temp = arr[r][c];
            arr[r][c] = arr[r - 1][c];
            arr[r - 1][c] = temp;
        }
        break;
    case 'd':
        if (c != 0)
        {
            path[turn++] = 'R';
            temp = arr[r][c];
            arr[r][c] = arr[r][c - 1];
            arr[r][c - 1] = temp;
        }
        break;
    case 'a':
        if (c != 4)
        {
            path[turn++] = 'L';
            temp = arr[r][c];
            arr[r][c] = arr[r][c + 1];
            arr[r][c + 1] = temp;
        }
        break;
    default:
        cout << "Wrong Input. Try again ";
        break;
    }
    cout << endl;
}
void print_path()
{
    SetConsoleTextAttribute(h, 3);
    ofstream result;
    result.open("result game", ios::out);
    result << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<YOUR GAME RESULT>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    result << "\n\t Your moves from initial to goal state is :   ";
    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Your Puzzle Result is as follow >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cout<<endl<<endl;
	cout << " Your moves from initial to goal state is as follow :   ";
    for (int i = 0; path[i] != '\0'; ++i)
    {
        switch (path[i])
        {
        case('U'):

        {
            result << "UP\t";
            cout << "UP\t";
            break;
        }
        case('D'):

        {
            result << "DOWN\t";
            cout << "DOWN\t";
            break;
        }
        case('L'):

        {
            result << "LEFT\t";
            cout << "LEFT\t";
            break;
        }
        case('R'):

        {
            result << "RIGHT\t";
            cout << "RIGHT\t";
            break;
        }
        }

    }

    result.close();
    cout<<endl;
    cout << " You can see you game report in the text file";
    cout<<endl;

}

