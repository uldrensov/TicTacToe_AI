#include <iostream>
using namespace std;

#include "TicTacToe.h"

int main()
{
    bool GameOver = false;
    char Player = 'O';
    int numX, numY;

    cout << "Welcome to TicTacToe!" << endl;

    //Create an instance of a TicTacToe object, called myGame.
    TicTacToe myGame;

    //Call the createBoard function and generate the playing field. Display the blank slate.
    myGame.createBoard();
    myGame.showBoard();

    //Force the computer to go first by marking the center space with an X. Print the resulting board.
    cout << "Computer's turn:" << endl;
    myGame.playerTurn(2, 2, 'X');
    myGame.showBoard();

    do
    {
        //---------------Player's turn-------------------

        //Prompt user input.
        cout << "User's turn, enter row and column:" << endl;
        cin >> numX;
        cin >> numY;

        //Pass information to the playerTurn function to carry out the action.
        myGame.playerTurn(numX, numY, Player);

        //At the end of the player's turn, print the resulting board and check to see if the game is over.
        myGame.showBoard();
        GameOver = myGame.checkResult(Player, GameOver);
        GameOver = myGame.checkDraw(GameOver);

        //---------------AI's turn-----------------

        //Declare the start of the AI's turn.
        cout << "Computer's turn:" << endl;

        //This boolean will turn false and prevent further action from the AI once it has chosen a course of action.
        bool AI = true;

        //Aim for a potential killmove first.
        AI = myGame.killMove(AI);

        //If a killmove was not possible, aim to deny an imminent player victory.
        if (AI == true) AI = myGame.denial(AI);

        //If imminent denial was not possible, aim to deny an oncoming double-pronged attack.
        if (AI == true) AI = myGame.doubleProng(AI);

        //If all aforementioned options are not possible, make an arbitrary maneuver.
        if (AI == true) myGame.randomPick();

        //At the end of the computer's turn, print the resulting board and check to see if the game is over.
        myGame.showBoard();
        GameOver = myGame.checkResult('X', GameOver);
        GameOver = myGame.checkDraw(GameOver);
    }
    while(GameOver == false);

    system("pause");
    return 0;
}
