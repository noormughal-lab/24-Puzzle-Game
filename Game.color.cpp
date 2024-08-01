#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include<fstream>
#include<windows.h>
#include"Game.color.h"
using namespace std;

int main()
{
    system("color 7E");
    char move;
    srand(time(0));
    initialize(a);
    int choice, z = 0;
    char choice2;
    SetConsoleTextAttribute(h, 3);
    cout << "************************************************************************************__************************************************************************************" << endl << endl;
    cout << "*************************************************************************** Welcome to Puzzle Game ***********************************************************************"<<endl<<endl;
    cout << "************************************************************************************__************************************************************************************" << endl <<endl<< endl;
    cout << "L E T S _ S T A R T _ T H E _ G A M E ('_')" << endl << endl << endl;
    cout << "Enter 1 if you want to take numbers from file\nEnter 0 if you want to generate randomly\n\n";  
    cin >> choice;
    if (choice == 0)
    {
        do
        {
            initialize(b);
        } while (is_solvable(a, b) == 0);

    }
    else if (choice == 1)
    {
        ifstream number;
        number.open("input number.txt");
        if (!number)                                     //check to handle exception
        {
            cout << " Error opening in file ";
        }
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    number >> b[i][j];
                }
            }
        }
        number.close();
    }


    show_goal();
    show_initial();
    do
    {
        SetConsoleTextAttribute(h, 6);
        cout << "\n\n Enter \"d\" to move the tile to Left   ";                    //instructions
        cout << "\n Enter \"a\" to move the tile to Right   ";
        cout << "\n Enter \"w\" to move the tile to Down   ";
        cout << "\n Enter \"s\" to move the tile to Up \n  "<<endl;
        cout << " Enter Move: " ;
        move = _getche();
        path[z] = move;
        ++z;
        system("CLS");
        make_move(b, move);
        show_goal();
        show_initial();
        SetConsoleTextAttribute(h, 8);
        cout << "\nENTER 'E' FOR EXIT GAME"<<endl;
        cout << "\nENTER 'C' FOR CONTINUE"<<endl;
        cin >> choice2;
        if (choice2 == 'E' || choice2 == 'e')
        {
            break;
        }
        else if (choice2 == 'C' || choice2 == 'c')
        {
            continue;
        }
        else 
		{

            continue;
        }
    } while (is_goal(a, b) == 0);
    print_path();

    return 0;
}


