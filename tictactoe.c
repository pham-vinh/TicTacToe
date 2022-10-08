#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// boolean of either pvp or pvc
int menuInput;

// Long String Matrix
int board[3][3];
int x;
int y;


// Declare Methods
void displayMenu();
int getPlayerTurn();
int isGameOver();
void computerInput();
void setGameState();
int isValid();
void printBoard();
bool drawCheck();

int main()
{

	int player; // 0 is false, 1 is true

	// get input on menu
	displayMenu();
	while (menuInput != 1 && menuInput != 2)
	{
		displayMenu();
	}
	if (menuInput == 1)
		player = 1;
	else
		player = 0;

	// print out the first game state via method in a while loop while getting input
	setGameState(0, 0, 0);
	printBoard();

	int playerTurn = 1;
	while (isGameOver() == 0)
	{
		if (player == 1 || player == 2)
			playerTurn = getPlayerTurn(playerTurn);
		else
		{
			getPlayerTurn(1);
			computerInput();
		}
		setGameState(x, y, playerTurn);
		printBoard();
	}

	// if pvc get random space and input in. check if the spot is open or not.
	// similar to pvp check if spot is open. Method here()
	// in gameState method check if the game is over or not.

	// ***Make sure to document throughout methods***

	return 0;
}

// method for displaying menu
void displayMenu()
{
	printf("\n======================\n");
	printf("WELCOME TO TIC TAC TOE!\n");
	printf("1 --- person vs. person\n");
	printf("2 --- person vs. random computer\n");

	printf("Enter your choice (1 or 2)\n");
	printf("=======================\n");
	scanf("%d", &menuInput);
	printf("\nYou have entered choice %d\n", menuInput);

	if (menuInput > 2)
		printf("\nInvalid Choice Please Choose Again\n");
}

int isGameOver()
{

	return 0; // false
}

int getPlayerTurn(int pT)
{
	if (pT == 1)
	{
		printf("Player 1: make your move\n");
		scanf("%d %d", &x, &y);
		if (isValid(x, y) == 1)
		{
			x -= 1;
			y -= 1;
		}
		else
			getPlayerTurn(1);
		pT = 2;
	}
	else
	{
		printf("Player 2: make your move\n");
		scanf("%d %d", &x, &y);
		if (isValid(x, y) == 1)
		{
			x -= 1;
			y -= 1;
		}
		else
			getPlayerTurn(2);
		pT = 1;
	}
	return pT;
}

void setGameState(int x, int y, int player)
{
	if (board[x][y] == 0)
	{
		if (player == 1)
			board[x][y] = 1;
		else if (player == 2)
			board[x][y] = 2;
		else
		{
			board[x][y] = 0;
		}
	}
	else
	{
		printf("Invalid Input Please try again.\n");
		player == 1 ? setGameState(x, y, getPlayerTurn(1)) : setGameState(x, y, getPlayerTurn(2));
	
		printBoard();
	}
}

void printBoard()
{
	for (int i = 0; i < 3; i++)
	{
		printf("+-----------+\n");
		for (int j = 0; j < 3; j++)
		{
			printf(" | ");

			if (board[i][j] == 1)
				printf("X");
			else if (board[i][j] == 2)
				printf("O");
			else
				printf(" ");
		}
		printf(" |\n");
	}
	printf("+-----------+\n");
}
void computerInput()
{
}

int isValid(int x, int y)
{
	if ((x < 4 && x > 0) && (y < 4 && y > 0))
	{
		printf("\nGood!\n");
		return 1;
	}
	else
		return 0;
}