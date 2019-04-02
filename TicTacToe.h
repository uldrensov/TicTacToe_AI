#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <string>
using namespace std;

//Define the class for a TicTacToe object.
class TicTacToe
{
    //Create the 2D array representing the game board.
   private:
   char board[3][3];
   public:
   TicTacToe() {}


   //This function initialises the board's appearance with asterisks.
   void createBoard()
   {
      int i = 0;
      int j = 0;

      for (i = 0; i < 3; i++)
      {
         for (j = 0; j < 3; j++)
         {
            board[i][j] = '*';
         }
      }
   }


   //This function prints the game board's appearance to standard output.
   void showBoard()
   {
      int i = 0;
      int j = 0;

      for (i = 0; i < 3; i++)
      {
         for (j = 0; j < 3; j++)
         {
            if (j < 2) cout << board[i][j] << "  |  ";
            else cout << board[i][j] << endl;
         }
      }
   }


   //This function handles the event when the player takes their turn.
   void playerTurn(int num1, int num2, char Player)
   {
      //This loop validates proper input.
      while ((num1-1 != 0 && num1-1 != 1 && num1-1 != 2) || (num1-1 != 0 && num1-1 != 1 && num1-1 != 2))
      {
          cout << "Invalid coordinates. Enter a row number, then a column number between 1 and 3." << endl;
          cin >> num1;
          cin >> num2;
      }

     if( board[num1-1][num2-1] == '*') board[num1-1][num2-1] = Player;
     else cout << "You may only mark open slots." << endl;
   }


    //This function checks for a winner periodically. If there exists no winner, continue the game or call a draw.
   bool checkResult(char Player, bool GameOver)
   {
       //Row check
      for(int i = 0; i < 3; i++)
      {
         if(board[i][0] == Player && board[i][1] == Player && board[i][2] == Player) GameOver = true;
      }

      //Column check
      for(int i = 0; i < 3; i++)
      {
         if(board[0][i] == Player && board[1][i] == Player && board[2][i] == Player) GameOver = true;
      }

      //Diagonal check
      if(board[0][0] == Player && board[1][1] == Player && board[2][2] == Player) GameOver = true;
      if(board[0][2] == Player && board[1][1] == Player && board[2][0] == Player) GameOver = true;

      //If a check passes, declare victory.
      if(GameOver == true) cout << "Player " << Player << " wins!" << endl;

      return GameOver;
   }


    //This function checks for a draw.
    bool checkDraw(bool GameOver)
    {
      int i = 0;
      int j = 0;
      int counter = 0;

      for(i = 0; i < 3; i++)
      {
         for(j = 0; j < 3; j++)
         {
            //Check to see if the board is full. Counter will increment if spaces are open.
            if(board[i][j] == '*')
            {
               counter++;
            }
         }
      }

      //A draw is called if the counter did not increment, and therefore the board is filled.
      if(counter < 1)
      {
		  cout << "The cat wins." << endl;
		  GameOver = true;
      }

      return GameOver;
   }


   //This function checks if the computer can execute a winning move.
   bool killMove(bool V)
   {
       if(board[0][0] == '*' && ((board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[2][0] == 'X') || (board[2][2] == 'X')))
       {
           board[0][0] = 'X';
           V = false;
       }
       else if(board[0][1] == '*' && ((board[0][0] == 'X' && board[0][2] == 'X') || (board[2][1] == 'X')))
       {
           board[0][1] = 'X';
           V = false;
       }
       else if(board[0][2] == '*' && ((board[0][0] == 'X' && board[0][1] == 'X') || (board[1][2] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X')))
       {
           board[0][2] = 'X';
           V = false;
       }
       else if(board[1][0] == '*' && ((board[0][0] == 'X' && board[2][0] == 'X') || (board[1][2] == 'X')))
       {
           board[1][0] = 'X';
           V = false;
       }
       else if(board[1][2] == '*' && ((board[0][2] == 'X' && board[2][2] == 'X') || (board[1][0] == 'X')))
       {
           board[1][2] = 'X';
           V = false;
       }
       else if(board[2][0] == '*' && ((board[0][0] == 'X' && board[1][0] == 'X') || (board[2][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X')))
       {
           board[2][0] = 'X';
           V = false;
       }
       else if(board[2][1] == '*' && ((board[2][0] == 'X' && board[2][2] == 'X') || (board[0][1] == 'X')))
       {
           board[2][1] = 'X';
           V = false;
       }
       else if(board[2][2] == '*' && ((board[2][0] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X') || (board[0][0] == 'X')))
       {
           board[2][2] = 'X';
           V = false;
       }

       return V;
   }


   //This function checks if the computer can deny a player's winning move.
   bool denial(bool Q)
   {
       if(board[0][0] == '*' && ((board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[2][0] == 'O')))
       {
           board[0][0] = 'X';
           Q = false;
       }
       else if(board[0][1] == '*' && ((board[0][0] == 'O' && board[0][2] == 'O')))
       {
           board[0][1] = 'X';
           Q = false;
       }
       else if(board[0][2] == '*' && ((board[0][0] == 'O' && board[0][1] == 'O') || (board[1][2] == 'O' && board[2][2] == 'O')))
       {
           board[0][2] = 'X';
           Q = false;
       }
       else if(board[1][0] == '*' && ((board[0][0] == 'O' && board[2][0] == 'O')))
       {
           board[1][0] = 'X';
           Q = false;
       }
       else if(board[1][2] == '*' && ((board[0][2] == 'O' && board[2][2] == 'O')))
       {
           board[1][2] = 'X';
           Q = false;
       }
       else if(board[2][0] == '*' && ((board[0][0] == 'O' && board[1][0] == 'O') || (board[2][1] == 'O' && board[2][2] == 'O')))
       {
           board[2][0] = 'X';
           Q = false;
       }
       else if(board[2][1] == '*' && ((board[2][0] == 'O' && board[2][2] == 'O')))
       {
           board[2][1] = 'X';
           Q = false;
       }
       else if(board[2][2] == '*' && ((board[2][0] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O')))
       {
           board[2][2] = 'X';
           Q = false;
       }

       return Q;
   }


   //This function checks if the computer can deny an incoming double-pronged or two-way victory for the player.
   bool doubleProng(bool D)
   {
       if(board[0][1] == 'O' && board[2][0] == 'O' && board[0][0] == '*')
       {
           board[0][0] = 'X';
           D = false;
       }
       else if(board[0][1] == 'O' && board[2][2] == 'O' && board[0][2] == '*')
       {
           board[0][2] = 'X';
           D = false;
       }
       else if(board[2][1] == 'O' && board[0][0] == 'O' && board[2][0] == '*')
       {
           board[2][0] = 'X';
           D = false;
       }
       else if(board[2][1] == 'O' && board[0][2] == 'O' && board[2][2] == '*')
       {
           board[2][2] = 'X';
           D = false;
       }
       else if(board[1][0] == 'O' && board[0][2] == 'O' && board[0][0] == '*')
       {
           board[0][0] = 'X';
           D = false;
       }
       else if(board[1][0] == 'O' && board[2][2] == 'O' && board[2][0] == '*')
       {
           board[2][0] = 'X';
           D = false;
       }
       else if(board[1][2] == 'O' && board[0][0] == 'O' && board[0][2] == '*')
       {
           board[0][2] = 'X';
           D = false;
       }
       else if(board[1][2] == 'O' && board[2][0] == 'O' && board[2][2] == '*')
       {
           board[2][2] = 'X';
           D = false;
       }

       return D;
   }


   //This function commands the computer to make an arbitrary move, in case of an inability to kill or deny.
   void randomPick()
   {
       bool stopLooking = false;

       for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '*' && stopLooking == false)
                {
                    board[i][j] = 'X';
                    stopLooking = true;
                }
            }
        }
   }
};

#endif /* TICTACTOE_H_ */
