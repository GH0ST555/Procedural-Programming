/************************************************************************
University of Leeds
School of Computing
COMP1711/XJCO1711- Procedural Programming
Coursework 2

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Arjun Krishnan
Student ID: 201556830
Email: sc21ak@leeds.ac.uk
Date Work Commenced: 19/11/21
*************************************************************************/


// ********************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS.
// However, please read through this section and look at the array declaration and other functions that you will use in your code

#include <stdio.h>
#include <stdlib.h>
#include "tic.h"

// use this 2d array to store the moves of the game, please don't change its name or size
char grid[MaxGrid][MaxGrid]; // this is the grid that will be used to store the moves of the game

int __Check_Count; // do not use this variable, it is for the grader only

// USE THE FOLLOWING FUNCTIONS TO DISPLAY THE CORRECT PROMPTS AND MESSAGES WHEN YOU NEED THEM
// IN YOUR CODE. THIS WILL GUARANTEE THAT YOU PROGRAM'S OUTPUT MATCHES MINE AND FACILITATE AUTOGRADING

// please use this function to prompt the user to enter the grid size to start a new game
void promptEnterGridSize ()
{
  printf ("Enter grid size (3-10):");
}

// please use this function to prompt the user to enter the winning length for the new game
// the parameter represents the maximum winning length for this game
void promptEnterWinLength (int max_win_length)
{
	printf ("Enter winning length (3-%i):", max_win_length);
}

// please use this function to prompt the user to enter the location of the symbol
// this function takes as a parameter the symbol of the player to be prompted
void promptChooseLocation (char symbol)
{
	printf ("Player %c, Choose Location (row,col): ", symbol);
}

// please use this function to show an error message when an index is out of range
void showErrIndex ()
{
  printf ("Index out of range, please re-enter\n");
}

// please use this function to show an error message when a location is already taken
void showErrTaken ()
{
  printf ("This location is already taken\n");
}

// please use this function to show the win message at the end of the game
// this function takes as parameter the symbol of the player who won the game
void showWinMessage (char symbol)
{
	printf ("**************************\n");
	printf ("Player %c has won the game\n", symbol);
	printf ("**************************\n");
}

// please use this function to show a game over (draw) message at the end of the game
void showGameOverMessage ()
{
	printf ("Game over; there are no winners\n");
}

//  please use this function to prompt the user to choose if they want to play back the game (at the end of the game)
void promptPlayBackGame ()
{
  printf ("\nWould you like to play back the recorded game? (y,n)?");
}

// please use this function to prompt the user to answer with n (next) or e (exit)
// to indicate if they want to proceed with the game's replay or exit the program
void promptNextOrExit ()
{
  printf ("Next or Exit (n,e)?");
}

// You will use this function in effPlayerHasWon (see below).
// This function is basically a wrapper around an if statement to compare the content of the cell at row,col with symbol
// However, it also counts the number of times the function is called
// Needless to say again, don't change this function
int check (int row, int col, char symbol)
{
	__Check_Count++;
	if (grid[row][col] == symbol)
		return 1;
	return 0;
}

// Used by the grader to peek at a certain cell in the grid. Don't use this function
int peek (int row, int col)
{
	return grid[row][col];
}


// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ************************************************

// --------------------------------------------------------------------------------------------------
// NOW IT IS YOUR TURN, YOU CAN DEFINE ANY OTHER GLOBAL VARIABLES YOU MAY NEED IN YOUR CODE BELOW THIS LINE
int count = 0;
int gridsize;
int max_win_length;
int row;
int col;
int arow;
int bcol;
int win = 0;
char c;
char store_the_row_col[3];
int charcount;
int conv_string;
char aaa;
int bbb;
int count_occour;
char Ans;
char replayorexit;
int store_rows[100];
int store_cols[100];
int counter_for_rows_cols;
int rplay=0;



// END OF SECTION FOR DECLARRING ADDITIONAL GLOBAL VARIABLES
// ----------------------------------------------------------

// -------------------------------------------------------------------------------------------------
// NOW, IMPLEMENT THE FOLLOWING FUNCTIONS BY WRITING THE CORRECT CODE IN THE BODIES OF THE FUNCTIONS
// please, don't change the functions' name, return type, or parameters. If you change any of these the grader will crash
// initially these functions contain 'return -99'. Before implementing a function you should delete this statement

// The purpose of this function is to to start a new game
// It is used to initialise everything at the start of a new game
// This functions takes two integer parameters:
// The first parameter (gridsize) represents the size of the grid of the new game, .e.g. 3 for 3x3 game
// The minimum size of the grid is 3 and the maximum size is 10, if the value of the parameter is wrong (less than 3 or > 10)
// the function returns 0 indicating failure to start a new game.
// The second parameter (winlength) is the number of consecutive symbols for the winning case.
// This number cannot be less than 3 or > gridsize (why?), think but don't click :-)
// If the value of the second parameter is invalid (<3 or >gridsize) the function returns 0 (failure)
// If everything is correct the function returns 1 indicating success in initialising the game.
int newGame (int gridsize, int winlength)
{
	if (gridsize >= 3 && gridsize <= 10)
  {
    if (winlength >= 3 && winlength <= gridsize)
    {
      for (int c = 0; c<=gridsize ; c++)
      {
        for (int r=0 ; r<=gridsize; r++)
        {
          grid[c][r]='.';
        }
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else{
    return 0;
  }
}

// The purpose of this function is to show the game's grid on the screen
// The grid should exactly look like the examples in the assignment specification
// Please note the following when you implement the function:
// There is one empty line before the grid to make it stand out from text before it
// The column indices are printed at the top and the first one is indented by exactly one tab (\t); indices are separated by exactly one space
// The row indices are printed at the left followed by exactly one tab (\t)
// The grid symbols are separated by exactly one space
// There is one empty line after the grid to make it stand out from text after it
void showGrid ()
{
 printf("\n");
 printf("\t");
 for (int x=0 ; x<gridsize ; x++)
 {
   printf("%i ",x);
 }
 printf("\n");
 printf("\n");
 for (int x=0 ; x<gridsize; x++)
 {
    printf("%i",x);
    printf("\t");
   for (int y=0 ; y<gridsize; y++)
   {

     printf("%c ",grid[x][y]);

   }
   printf("\n");
 }


}

// The purpose of this function is to make a move by a player.
// Making a move means putting the player's symbol (letter) in the desired cell
// This function takes 3 parameters. The first two represent indices of the row and column of the cell in which the player
// wants to place their symbol.
// The last parameter is the symbol (letter) of that player.
// A move can only be made if:
// 1- The row and column numbers are valid (not less than 0 or greater than the game's grid size), and
// 2- the cell is not already occupied by another symbol, and
// 3- the symbol is a valid one (X or O).
// If the move can be made (because it is valid), the function makes the move (i.e. puts the symbol in the cell) and returns 1 indicating success.
// otherwise the function returns 0 indicating failure to make the move
// my solution is 4 lines only
int makeMove(int row, int col, char symbol)
{
    if (row < gridsize && col < gridsize)
    {
      if (grid[col][row] =='X' || grid[col][row] =='O')
      {
        return 0;
      }
      else
      {
        store_rows[counter_for_rows_cols]=row;
        store_cols[counter_for_rows_cols]=col;
        counter_for_rows_cols+=1;
        grid[col][row] = symbol;
        return 1;
      }
    }
    else
    {
    return 0;
    }
}

// This function is used to check if the board is full, i.e. every location in the grid is filled with either X or O
// it returns 1 if the grid is full, 0 otherwise
// my solution is 5 lines
int boardIsFull()
{
  count = 0;
  for (int c = 0; c<=gridsize ; c++)
  {
    for (int r=0 ; r<=gridsize; r++)
    {
      if (grid[c][r] == 'X' || grid[c][r] == 'O')
      {
        count += 1 ;
      }
    }
  }
  if (count == gridsize*gridsize)
  {
    printf("\n");
    showGameOverMessage();
    promptPlayBackGame();
    scanf("%s", &Ans);
    win +=1;
    return 1;
  }
  else
  {
    return 0;
  }
}


// This function is used to check if there is any horizontal line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a horizontal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a horizontal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkHorizontal (char symbol, int length)
{
  if (symbol == 'X' || symbol == 'O')
  {
    if (length <= max_win_length)
    {
      for (int a = 0; a<=gridsize ; a++)
      {
        count_occour = 0;
        for (int b=0 ; b<=gridsize; b++)
        {
          if (grid[a][b] == symbol)
          {
            count_occour +=1;
          }
          else
          {
            count_occour = 0;
          }
          if (count_occour == length)
          {
            win += 1;
            return 1;
          }
        }
        return 0;
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }
}


// This function is used to check if there is any vertical line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a vertical run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a vertical line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkVertical (char symbol, int length)
{
  if (symbol == 'X' || symbol == 'O')
  {
    if (length <= max_win_length)
    {
      for (int a = 0; a<=gridsize ; a++)
      {
        count_occour = 0;
        for (int b=0 ; b<=gridsize; b++)
        {
          if (grid[b][a] == symbol)
          {
            count_occour +=1;
          }
          if (count_occour == length)
          {
            win += 1;
            return 1;
          }
        }
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }
}

// This function is used to check if there is any diagonal line in the grid that contains a consecutive sequence of the same symbol
// A diagonal line runs from higher left to lower right (or vice versa). Note that there are more than one diagonal line in a grid.
// It can be used to check that a player has won the game by forming a diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkDiagonals (char symbol, int length)
{
  if (symbol == 'X' || symbol == 'O')
  {
    if (length <= gridsize)
    {
      for (int k=0 ; k<gridsize; k++)
      {
        count_occour=0;
        for (int i=0 ; i<gridsize ; i++)
        {
          for (int j = 0; j<gridsize; j++)
          {
            if (grid[j][i]==symbol && grid[j+1][i+1]==symbol)
            {
              count_occour+=1;
            }
            if (count_occour ==length-1)
            {
              win+=1;
              return 1;
            }
          }
        }
      }
      return 0;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }
}

// This function is used to check if there is any anti-diagonal (reverse diagonal) section in the grid that contains a consecutive sequence of the same symbol
// An anti-diagonal line runs from higher right to lower left (or vice versa). Note that there are more than one anti-diagonal line in a grid.
// It can be used to check that a player has won the game by forming an anti-diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed an anti-diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating an failure to make a move
int checkAntiDiagonals (char symbol, int length)
{
  if (symbol == 'X' || symbol == 'O')
  {
    if (length <= gridsize)
    {
      for (int k=0 ; k<gridsize; k++)
      {
        count_occour=0;
        for (int i=gridsize-1 ; i>=0 ; i--)
        {
          for (int j = 0; j<gridsize; j++)
          {
            if (grid[i][j]==symbol && grid[i-1][j+1]==symbol)
            {
              count_occour+=1;
            }
            if (count_occour ==length-1)
            {
              win+=1;
              return 1;
            }
          }
        }
      }
      return 0;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }
}


// This function is used to check if a player has won the game by forming a horizontal, vertical, diagonal, or anti-diagonal line
// of the required length. This function should use the above four functions (checkHorizontal, checkVertical, checkDiagonals, and checkAntiDiagonals)
// to determine if the player has one
// The function returns 1 if the player given by symbol has won, and 0 if the player has not won
// If any of the parameters is invalid the function returns -1 indicating failure to check
// my solution is 5 lines
int playerHasWon (char symbol , int length)
{
  if (symbol == 'X' || symbol == 'O')
  {
    if (length <= max_win_length)
    {
      checkVertical(symbol,length);
      checkHorizontal(symbol,length);
      checkDiagonals(symbol,length);
      checkAntiDiagonals(symbol,length);

      if (win == 1)
      {
        counter_for_rows_cols =0;
        for (int i=0 ; i<gridsize ; i++)
        {
          for (int j = 0; j<gridsize; j++)
          {
            if (grid[i][j]=='X' || grid[i][j]=='O')
            {
              counter_for_rows_cols+=1;
            }
          }
        }
        printf("\n");
        showWinMessage(symbol);
        promptPlayBackGame();
        scanf("%s", &Ans);
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }
}

// Do you think the above function (playerHasWon) is the most efficient way of detecting a win?
// Do we do this as humans when we play the game?
// The answer is NO.
// The purpose of this function is to implement a much more efficient version of the playerHasWon function
// The function takes four parameters.
// The first two parameters represent the location (row, and col) of the last move made
// by a player.
// The second parameter is the symbol of that player.
// The last parameter is the length of the winning line
// We will assess the efficiency of the function by the number of times we need to check the contents of a cell.
// To count the number of checks, I have prepared a function called check - see the top of this file - that you have
// to use instead of an if statement when you need to compare the contents of a cell to a given symbol.
//
// This function returns 1 if the player has formed a winning line immediately after placing their symbol in the
// cell given by row,col. If the player did not win, the function returns 0
// It returns -1 if any of the parameters have an invalid value.
int effPlayerHasWon (int row, int col, char symbol , int length)
{
	return 1;
}

// IF YOU NEED ADDITIONAL FUNCTIONS YOU CAN DEFINE THEM BELOW THIS LINE
//----------------------------------------------------------------------
int MakeMove(int row, int col, char symbol)
{
  grid[col][row]=symbol;
}




// DON'T CHANGE THE FOLLOWING 3 LINES
#ifndef TEST
int  main (int argc, char* argv[])
{
	// ENTER THE CODE OF YOUR main FUNCTION BELOW
  promptEnterGridSize();
  scanf("%i", &gridsize);
  promptEnterWinLength(gridsize);
  scanf("%i",&max_win_length );
  newGame(gridsize,max_win_length);
  showGrid();
  counter_for_rows_cols = 0;
  while (win == 0)
  {
    printf("\n");
    if (charcount % 2 == 0)
    {
      c = 'X';
    }
    else
    {
      c = 'O';
    }
    promptChooseLocation(c);
    scanf("%s",store_the_row_col);
    aaa = store_the_row_col[2];
    conv_string = atoi(store_the_row_col);
    bbb = aaa - '0';
    arow =bbb;
    bcol =conv_string;
    if (arow>gridsize-1 || bcol>gridsize-1)
    {
      showErrIndex();
      charcount -= 1;
      promptChooseLocation(c);
      scanf("%s",store_the_row_col);
      aaa = store_the_row_col[2];
      conv_string = atoi(store_the_row_col);
      bbb = aaa - '0';
      arow =bbb;
      bcol =conv_string;
      makeMove(arow,bcol,c);
      showGrid();
      charcount+=1;
    }
    else if (grid[bcol][arow]=='X' || grid[bcol][arow]=='O')
    {
      showErrTaken();
      charcount -= 1;
      promptChooseLocation(c);
      scanf("%s",store_the_row_col);
      aaa = store_the_row_col[2];
      conv_string = atoi(store_the_row_col);
      bbb = aaa - '0';
      arow =bbb;
      bcol =conv_string;
      makeMove(arow,bcol,c);
      showGrid();
      charcount+=1;
    }
    else
    {
      makeMove(arow,bcol,c);
      showGrid();
    }
    charcount += 1;
    playerHasWon(c,max_win_length);
    boardIsFull();
    if (Ans == 'y')
    {
      newGame(gridsize,max_win_length);
      charcount = 0;
      showGrid();
      printf("\n");
      promptNextOrExit();
      scanf("%s",&replayorexit);
    }
  }
  while (replayorexit == 'n' && charcount !=counter_for_rows_cols)
  {
    if (charcount == counter_for_rows_cols)
    {
      break;
    }
    else
    {
      if (charcount % 2 == 0)
      {
        c = 'X';
      }
      else if (charcount % 2 != 0)
      {
        c = 'O';
      }
      if (charcount == counter_for_rows_cols-1)
      {
        MakeMove(store_rows[charcount],store_cols[charcount],c);
        showGrid();
        printf("\n");
        break;
      }
      else
      {
        MakeMove(store_rows[charcount],store_cols[charcount],c);
        showGrid();
        charcount +=1;
        printf("\n");
        promptNextOrExit();
        scanf("%s",&replayorexit);
      }
    }
  }





// DON'T CHANGE THE FOLLOWING 3 LINES
return 0;
}
#endif
// DON'T WRITE ANYTHING BELOW THIS LINE
