#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// boolean of either pvp or pvc
int menuInput;

// Swapping between player 1 and 2
int playerTurn = 1;

// Long String Matrix
int board[3][3];

// Coords
int x;
int y;

// Max Turns == 9
int maxTurns = 0;

// Declare Methods
void displayMenu();
void getPlayerTurn();
bool isGameOver();
void computerInput();
void setGameState();
int isValid();
void printBoard();
bool drawCheck();
void boardP();

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

	while (!isGameOver())
	{
		printBoard();
		if (player == 1)
			getPlayerTurn(playerTurn);
		else
		{
			getPlayerTurn(1);
			setGameState(x, y, 1);
			computerInput(); // sets x and y randomly
			playerTurn = 2;
		}
		setGameState(x, y, playerTurn);
	}

	return 0;
}

bool drawCheck()
{
	if (maxTurns >= 9)
		return true;
	return false;
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

bool isGameOver()
{
	if (drawCheck())
		return true;

	return false; // false
}

// get coords and swap
void getPlayerTurn(int pT)
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
		playerTurn = 2;
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
		playerTurn = 1;
	}
}

void setGameState(int x, int y, int player)
{
	if (player == 1)
	{
		maxTurns++;
		board[x][y] = 1;
	}
	else if (player == 2)
	{
		maxTurns++;
		board[x][y] = 2;
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
	time_t t;
	srand((unsigned)time(&t));
	x = rand() % 3;
	y = rand() % 3;

	while (board[x][y] != 0)
	{
		x = rand() % 3;
		y = rand() % 3;
	}
}

int isValid(int x, int y)
{
	if ((x < 4 && x > 0) && (y < 4 && y > 0))
	{
		int tempX = x - 1;
		int tempY = y - 1;
		if (board[tempX][tempY] == 0)
			printf("\nGood!\n");
		else
		{
			printf("\nInvalid Input Please try again.\n");
			return 0;
		}
		return 1;
	}
	else
		return 0;
}

void boardP()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d (%d,%d)", board[i][j], i, j);
		}
		printf("       %d   %d  \n", x, y);
	}
}