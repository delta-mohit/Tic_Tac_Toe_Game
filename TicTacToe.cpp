/*
    TITLE  ======>>>

                    Tic Tac Toe Game in C++

    CODER  ======>>>

                     MOHIT SAINI


    So, Let's get stared.........                                                                                                                              */

#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string n1;
string n2;
int row;
int col;
char token = 'X';
bool tie;

// function 1 to display Matrix on console---
void functionOne()
{

    cout << "      |         |       \n";
    cout << "  " << space[0][0] << "   |"
         << "   " << space[0][1] << "     |   " << space[0][2] << "   \n";
    cout << "______|_________|_______\n";
    cout << "      |         |       \n";
    cout << "  " << space[1][0] << "   |"
         << "   " << space[1][1] << "     |   " << space[1][2] << "   \n";
    cout << "______|_________|_______\n";
    cout << "      |         |       \n";
    cout << "  " << space[2][0] << "   |"
         << "   " << space[2][1] << "     |   " << space[2][2] << "   \n";
    cout << "      |         |       \n";
}

// functionTwo() is responsible for handling player moves and updating the game board accordingly.
void functionTwo()
{
    char digit;

    // According to current condition of Matrix, it is telling players about their turn and enter a position on board
    if (token == 'X')
    {
        cout << "Move is: " << token << endl;
        cout << n1 << ", enter your desired position: ";
        cin >> digit;
    }

    if (token == '@')
    {
        cout << "Move is: " << token << endl;
        cout << n2 << ", enter your desired position: ";
        cin >> digit;
    }

    // Check if the entered position is '0'
    if (digit == '0')
    {
        cout << "Invalid input! Please enter a valid position." << endl;
        cout << endl;
        functionTwo(); // Ask for input again
        return;
    }

    // Find the row and column corresponding to the entered digit
    bool check;
    for (int i = 0; i < 3; i++)
    {
        check = false;
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] == digit)
            {
                row = i;
                col = j;
                check = true;
                break;
            }
        }
        if (check == true)
        {
            break;
        }
    }

    // Check if the entered position is already filled
    if (space[row][col] != 'X' && space[row][col] != '@')
    {
        if (token == 'X')
        {
            space[row][col] = 'X';
            token = '@';
        }
        else
        {
            space[row][col] = '@';
            token = 'X';
        }
    }
    else
    {
        cout << "Invalid input! The entered position is already filled." << endl;
        cout << endl;
        functionTwo(); // Ask for input again
    }

    return;
}

// functionThree is checking that Does Game is still going on OR (n1 wins or n2 wins or Draw)

bool functionThree()
{
    // Check if any row or column matches
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    // Check if any diagonal matches
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[0][2] == space[2][0]))
    {
        return true;
    }

    // Check if the matrix is completely filled
    bool isFilled = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '@')
            {
                isFilled = false;
                break;
            }
        }
        if (isFilled == false)
        {
            break;
        }
    }

    if (isFilled == true)
    {
        tie = true;
        return true; // Return true to indicate a tie
    }

    return false; // Return false for ongoing game
}

int main()
{
    cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;
    cout << "________________________________________________________________________________________________" << endl;
    cout << endl; cout << endl;

    cout << "Enter the name of 1st player: ";
    getline(cin, n1);
    cout << endl;
    cout << "Enter the name of 2nd player: ";
    getline(cin, n2);
    cout << endl;
    cout << n1 << " is 1st player and your move is 'X'" << endl;
    cout << n2 << " is 2nd player and your move is '@'" << endl;
    cout << endl;
    cout << endl;

    cout << "--------------------------------------------------" << endl;
    cout << endl;
    cout << "           " << n1 << " (X)  VS  " << n2 << " (@)                 " << endl;
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    while (functionThree() == false)
    {
        functionOne();
        cout << endl;
        cout << endl;
        functionTwo();
        cout << endl;
    }

    functionOne();

    if (token == 'X' && tie == false)
    {
        cout << endl;
        cout << "Results: " << endl;
        cout << endl;
        cout << "Congratulation " << n2 << ", Since your move is '@' so You Win !!" << endl;
    }
    else if (token == '@' && tie == false)
    {
        cout << endl;
        cout << "Results: " << endl;
        cout << endl;
        cout << "Congratulation " << n1 << ", Since your move is 'X' so You Win !!" << endl;
    }
    else
    {
        cout << endl;
        cout << "Results: " << endl;
        cout << endl;
        cout << "It's a match draw !! But, You both played well." << endl;
        cout << "Play Again !!" << endl;
    }

    cout << endl; cout<<endl;
    cout << endl;    cout << "          ||   Program Ended Successfully ||   " << endl;
    cout << endl; cout << endl; cout << endl;    
    cout << "________________________________________________________________________________________________" << endl;
    cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;
 
    return 0;
}