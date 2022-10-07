#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// boolean of either pvp or pvc
int menuInput;

void displayMenu();



int main()
{
	int player; // 0 is false, 1 is true

	displayMenu();
	
	// get input on menu
	while (menuInput != 1 && menuInput != 2 )
	{
		displayMenu();
	}
	if (menuInput == 1) player = 1;
	else player = 0;


	// check if input is valid and go to the game of choice

	// Long String Matrix? or Array2D of Chars?

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
	printf("======================\n");
	printf("WELCOME TO TIC TAC TOE!\n");
	printf("1 --- person vs. person\n");
	printf("2 --- person vs. random computer\n");
	scanf("%d", &menuInput);
}

// boolean checkGameState()

// void displayGameState()

// computerInput()
