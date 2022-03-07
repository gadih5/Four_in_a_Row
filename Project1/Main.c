//Gadi Haik 206897639

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];


/*********** Declarations ************/

/// This function initializes the game board by assigning each cell
/// with ' ' (resulting with an empty game board).
void initBoard();

/// This function gets a row number and a column number (a cell),
/// and returns the character in that cell (could be 'X', 'O' or ' ').
/// For example:
/// char c = getCell(1, 1);
char getCell(int row, int col);

/// This function gets a row number, a column number and a sign,
/// and assigns the cell with the given sign.
/// For example:
/// setCell(1, 1, 'X');
void setCell(int row, int col, char sign);

/// This function clears the screen.
void clearScreen();

/// This function prints the current status of the game board.
void printBoard();

///This function checks who's the winner of the game (for each turn).
bool isWinner(int turn);

/*************** Main ****************/
int main()
{
	int col, i , turn;
	bool stopGame = false;

	initBoard();
	printBoard();

	for (turn = 1; turn <= 42 && stopGame == false ; turn++) //Stops if there's a winner or the game reaches to the maximum turns (42).
	{
		///Player 1 turn:
		if (turn % 2 != 0)
		{
			printf("Player Number 1:\nPlease enter column input (a number between 1-7):");
			scanf("%d", &col);

			///Checking if the column number is valid.
			while (col < 1 || col > COLS || getCell(1, col) != ' ')
			{
				///Checking if the chosen column is between one to seven.
				if (col < 1 || col > COLS)
				{
					printf("The col you entered is not between 1-7.\nPlease enter column input (a number between 1-7):");
					scanf("%d", &col);
				}
				///Checking if the chosen column is full. 
				else if (getCell(1, col) != ' ')
				{
					printf("The col you entered is full.\nPlease enter column input(a number between 1 - 7):");
					scanf("%d", &col);
				}
			}

			///Enter 'X' at the "free" cell at the chosen column.
			for (i = ROWS; i >= 1; i--)
			{
				if (getCell(i, col) == ' ')
				{
					setCell(i, col, 'X');
					i = 0;
				}
			}

			///Checking if player number 1 is the winner.
			if (isWinner(turn))
			{
				clearScreen();
				printBoard();
				printf("Player number 1 won! :)\n");
				stopGame = true;
			}
			///Player number 1 didn't win, the game continues.
			else
			{
				clearScreen();
				printBoard();
			}

		}

		///Player 2 turn:
		else if (turn % 2 == 0)
		{
			printf("Player Number 2:\nPlease enter column input (a number between 1-7):");
			scanf("%d", &col);

			///Checking if the column number is valid.
			while (col < 1 || col > COLS || getCell(1, col) != ' ')
			{
				///Checking if the chosen column is between one to seven.
				if (col < 1 || col > COLS)
				{
					printf("The col you entered is not between 1-7.\nPlease enter column input (a number between 1-7):");
					scanf("%d", &col);
				}
				///Checking if the chosen column is full. 
				else if (getCell(1, col) != ' ')
				{
					printf("The col you entered is full.\nPlease enter column input(a number between 1 - 7):");
					scanf("%d", &col);
				}
			}

			///Enter 'O' at the "free" cell at the chosen column.
			for (i = ROWS; i >= 1; i--)
			{
				if (getCell(i, col) == ' ')
				{
					setCell(i, col, 'O');
					i = 0;
				}
			}

			///Checking if player number 2 is the winner.
			if (isWinner(turn))
			{
				clearScreen();
				printBoard();
				printf("Player number 2 won! :)\n");
				stopGame = true;
			}
			///Player number 2 didn't win, the game continues.
			else
			{
				clearScreen();
				printBoard();
			}
		}
	}

	///After all the turns there's no winner, so its a tie.
	if (stopGame == false)
	{
		printf("There's a tie!\n");
	}

	system("pause");
}


/********** Implementations **********/
void printBoard()
{
	int row, col;
	char rowChar = 'A';

	///Prints the game board:
	printf("     1    2    3    4    5    6    7\n\n"); ///Prints column numbers.

	///Prints the rows and cells:
	for (row = 1; row <= ROWS; row++)
	{
		printf("%c", rowChar); ///Prints the row's letter.
		rowChar++;
		for (col = 1; col <= COLS; col++)
		{
			printf("    %c", getCell(row, col)); ///Prints the status ('X'/'O'/' ') of every cell.
		}
		printf("\n\n");
	}
}

bool isWinner(int turn)
{
	int row, col;
	for (row = 1; row <= ROWS; row++)
	{
		for (col = 1; col <= COLS; col++)
		{
			///Player 1 victory conditions:
			if (turn % 2 != 0) ///Player's 1 turn.
			{
				///Victory from 4 'X' in a row.
				if (col <= 4)
				{
					if (getCell(row, col) == 'X' && getCell(row, col + 1) == 'X' && getCell(row, col + 2) == 'X' && getCell(row, col + 3) == 'X')
						return true;
				}
				///Victory from 4 'X' in a column.
				if (row <= 3)
				{
					if (getCell(row, col) == 'X' && getCell(row + 1, col) == 'X' && getCell(row + 2, col) == 'X' && getCell(row + 3, col) == 'X')
						return true;
				}
				///Victory from 4 'X' in a diagonal line.
				if (col >= 4)
				{
					if (getCell(row, col) == 'X' && getCell(row - 1, col - 1) == 'X' && getCell(row - 2, col - 2) == 'X' && getCell(row - 3, col - 3) == 'X')
						return true;
				}
				///Victory from 4 'X' in a reverse diagonal line.
				if (col <= 4)
				{
					if (getCell(row, col) == 'X' && getCell(row - 1, col + 1) == 'X' && getCell(row - 2, col + 2) == 'X' && getCell(row - 3, col + 3) == 'X')
						return true;
				}
			}

			///Player 2 victory conditions:
			if (turn % 2 == 0) //Player's 2 turn.
			{
				///Victory from 4 'O' in a row.
				if (col <= 4)
				{
					if (getCell(row, col) == 'O' && getCell(row, col + 1) == 'O' && getCell(row, col + 2) == 'O' && getCell(row, col + 3) == 'O')
						return true;
				}
				///Victory from 4 'O' in a column.
				if (row <= 3)
				{
					if (getCell(row, col) == 'O' && getCell(row + 1, col) == 'O' && getCell(row + 2, col) == 'O' && getCell(row + 3, col) == 'O')
						return true;
				}
				///Victory from 4 'O' in a diagonal line.
				if (col >= 4)
				{
					if (getCell(row, col) == 'O' && getCell(row - 1, col - 1) == 'O' && getCell(row - 2, col - 2) == 'O' && getCell(row - 3, col - 3) == 'O')
						return true;
				}
				///Victory from 4 'O' in a reverse diagonal line.
				if (col <= 4)
				{
					if (getCell(row, col) == 'O' && getCell(row - 1, col + 1) == 'O' && getCell(row - 2, col + 2) == 'O' && getCell(row - 3, col + 3) == 'O')
						return true;
				}
			}
		}
	}

	///No winner yet.
	return false;
}

char getCell(int row, int col)
{
	return board[row - 1][col - 1];
}

void setCell(int row, int col, char sign)
{
	board[row - 1][col - 1] = sign;
}

void initBoard()
{
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			setCell(i+1, j+1, ' ');
		}
	}
}

void clearScreen()
{
	system("cls");
}