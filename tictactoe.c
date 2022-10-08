#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// boolean of either pvp or pvc
int menuInput;

// Long String Matrix
int board[3][3];
int x;
int y;

// Declare Methods
void displayMenu();
void initBoard();
int getPlayerTurn();
int isGameOver();
void computerInput();
void displayGameState();
int isValid();

int main()
{

	int player; // 0 is false, 1 is true

	displayMenu();

	// get input on menu
	while (menuInput != 1 && menuInput != 2)
	{
		displayMenu();
	}
	if (menuInput == 1)
		player = 1;
	else
		player = 0;

	displayGameState(0, 0, 0);

	int playerTurn = 1;
	while (isGameOver() == 0)
	{
		if (player == 1)
			playerTurn = getPlayerTurn(playerTurn);
		else
		{
			getPlayerTurn(1);
			computerInput();
		}
		displayGameState(x, y, playerTurn);
	}


	// print out the first game state via method in a while loop while getting input
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

void initBoard()
{
	for (int i = 1; i < 4; i++)
	{
		printf("+-----------+\n");
		for (int j = 1; j < 4; j++)
		{
			printf(" | ");
			board[i][j] = 0;
		}
		printf("|\n");
	}
	printf("+-----------+\n");
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
			printf("\nGood!\n");
		else
			getPlayerTurn(1);
		pT = 2;
	}
	else
	{
		printf("Player 2: make your move\n");
		scanf("%d %d", &x, &y);
		if (isValid(x, y) == 1)
			printf("\nGood!\n");
		else
			getPlayerTurn(2);
		pT = 1;
	}

	return pT;
}
void displayGameState(int x, int y, int player)
{
	for (int i = 1; i < 4; i++)
	{
		printf("+-----------+\n");
		for (int j = 1; j < 4; j++)
		{
			if (i == x && j == y)
			{
				if (player == 1)
				{
					printf("X");
					board[i][j] = 1;
				}
				else if (player == 2)
				{
					printf("O");
					board[i][j] = 2;
				}
			}
			printf(" | ");
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
	if (x < 4 && y <= 4)
		return 1;
	else
		return 0;
}