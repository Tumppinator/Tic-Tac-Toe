#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void calculateWinPatterns(char pawns[3][3]);
void handleAITurn(char pawns[3][3]);
void handlePlayerTurn(char pawns[3][3]);
void displayBoard(char pawns[3][3]);

bool gameOver = false;
bool playerWon = false;
bool AIWon = false;
char playerPawn = 'p';
char AIPawn = 'a';
bool playerTurn = false;
int randNumber = 1;

int main()
{
	bool startingPawnChosen = false;
	char start = 's';
	char pawns[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
	srand(time(NULL));


	cout << "Welcome to tic tac toe!\n";

	cout << "Choose your pawn: (x or o)\n";
	while (!startingPawnChosen)
	{
		startingPawnChosen = false;
		cin >> playerPawn;

		if (playerPawn != 'x' && playerPawn != 'o')
		{
			cout << "Incorrect input! Try again: (x or o)\n";
		}
		else
		{
			startingPawnChosen = true;
			AIPawn = (playerPawn == 'x') ? 'o' : 'x';
		}
	}
	cout << "Press the key 'y' if you want to be the first player to make a move. Press 'n' if you want the AI player to start.\n";
	
	while (start != 'y' && start != 'n')
	{
		cin >> start;
		if (start != 'y' && start != 'n')
		{
			cout << "Please choose 'y' or 'n'!\n";
		}
	}

	playerTurn = (start == 'y') ? true : false;

	
	while (!gameOver)
	{
		handlePlayerTurn(pawns);
		handleAITurn(pawns);

		// Display game board
		displayBoard(pawns);
		
		// Decide if game is over and who won
		calculateWinPatterns(pawns);
	}
	return 0;
}

void displayBoard(char pawns[3][3])
{

	cout << "\n " << pawns[0][0] << " " << "|" << " " << pawns[0][1] << " " << "|" << " " << pawns[0][2] << "\n";
	cout << "---|---|---\n";
	cout << " " << pawns[1][0] << " " << "|" << " " << pawns[1][1] << " " << "|" << " " << pawns[1][2] << "\n";
	cout << "---|---|---\n";
	cout << " " << pawns[2][0] << " " << "|" << " " << pawns[2][1] << " " << "|" << " " << pawns[2][2] << "\n";
}

void calculateWinPatterns(char pawns[3][3])
{
	////////////////////////////////////////////////////////////////////////
	// Vertical for x pawn 
	for (int i = 0; i < 3; i++)
	{
		if (pawns[i][0] == 'x' && pawns[i][1] == 'x' && pawns[i][2] == 'x')
		{

			if (pawns[i][0] == playerPawn)
			{
				playerWon = true;
			}
			else if (pawns[i][0] == AIPawn)
			{
				AIWon = true;
			}
			gameOver = true;
		}
	}
	// Vertical for o pawn
	for (int i = 0; i < 3; i++)
	{
		if (pawns[i][0] == 'o' && pawns[i][1] == 'o' && pawns[i][2] == 'o')
		{

			if (pawns[i][0] == playerPawn)
			{
				playerWon = true;
			}
			else if (pawns[i][0] == AIPawn)
			{
				AIWon = true;
			}
			gameOver = true;
		}
	}
	////////////////////////////////////////////////////////////////////////
	// Horizontal for x pawn
	for (int i = 0; i < 3; i++)
	{
		if (pawns[0][i] == 'x' && pawns[1][i] == 'x' && pawns[2][i] == 'x')
		{

			if (pawns[0][i] == playerPawn)
			{
				playerWon = true;
			}
			else if (pawns[0][i] == AIPawn)
			{
				AIWon = true;
			}
			gameOver = true;
		}
	}
	// Horizontal for o pawn
	for (int i = 0; i < 3; i++)
	{
		if (pawns[0][i] == 'o' && pawns[1][i] == 'o' && pawns[2][i] == 'o')
		{

			if (pawns[0][i] == playerPawn)
			{
				playerWon = true;
			}
			else if (pawns[0][i] == AIPawn)
			{
				AIWon = true;
			}
			gameOver = true;
		}
	}
	////////////////////////////////////////////////////////////////////////
	// Diagonal for x pawn
	if (pawns[0][0] == 'x' && pawns[1][1] == 'x' && pawns[2][2] == 'x')
	{
		if (pawns[0][0] == playerPawn)
		{
			playerWon = true;
		}
		else if (pawns[0][0] == AIPawn)
		{
			AIWon = true;
		}
		gameOver = true;
	}
	if (pawns[0][2] == 'x' && pawns[1][1] == 'x' && pawns[2][0] == 'x')
	{
		if (pawns[0][2] == playerPawn)
		{
			playerWon = true;
		}
		else if (pawns[0][2] == AIPawn)
		{
			AIWon = true;
		}
		gameOver = true;
	}
	// Diagonal for o pawn
	if (pawns[0][0] == 'o' && pawns[1][1] == 'o' && pawns[2][2] == 'o')
	{
		if (pawns[0][0] == playerPawn)
		{
			playerWon = true;
		}
		else if (pawns[0][0] == AIPawn)
		{
			AIWon = true;
		}
		gameOver = true;
	}
	if (pawns[0][2] == 'o' && pawns[1][1] == 'o' && pawns[2][0] == 'o')
	{
		if (pawns[0][2] == playerPawn)
		{
			playerWon = true;
		}
		else if (pawns[0][2] == AIPawn)
		{
			AIWon = true;
		}
		gameOver = true;
	}
	////////////////////////////////////////////////////////////////////////

	if (playerWon)
	{
		cout << "You won the game! Congratulations!\n";
	}
	else if (AIWon)
	{
		cout << "You lost! better luck next time!\n";
	}
}

void handleAITurn(char pawns[3][3])
{
	if (!playerTurn)
	{
		// Check for horizontal two in a row condition for AI pawn
		for (int i = 0; i < 3; i++)
		{
			if (pawns[i][0] == AIPawn && pawns[i][1] == AIPawn && pawns[i][2] != playerPawn && !playerTurn)
			{
				pawns[i][2] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[i][1] == AIPawn && pawns[i][2] == AIPawn && pawns[i][0] != playerPawn && !playerTurn)
			{
				pawns[i][0] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[i][0] == AIPawn && pawns[i][2] == AIPawn && pawns[i][1] != playerPawn && !playerTurn)
			{
				pawns[i][1] = AIPawn;
				playerTurn = true;
				break;
			}
		}
		
		// Check for vertical two in a row condition for AI pawn
		for (int i = 0; i < 3; i++)
		{
			if (pawns[0][i] == AIPawn && pawns[1][i] == AIPawn && pawns[2][i] != playerPawn && !playerTurn)
			{
				pawns[2][i] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[1][i] == AIPawn && pawns[2][i] == AIPawn && pawns[0][i] != playerPawn && !playerTurn)
			{
				pawns[0][i] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[0][i] == AIPawn && pawns[2][i] == AIPawn && pawns[1][i] != playerPawn && !playerTurn)
			{
				pawns[1][i] = AIPawn;
				playerTurn = true;
				break;
			}
		}
		
		// Check for two diagonals for AI pawn
		if (pawns[0][0] == AIPawn && pawns[1][1] == AIPawn && pawns[2][2] != playerPawn && !playerTurn)
		{
			pawns[2][2] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[1][1] == AIPawn && pawns[2][2] == AIPawn && pawns[0][0] != playerPawn && !playerTurn)
		{
			pawns[0][0] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][0] == AIPawn && pawns[2][2] == AIPawn && pawns[1][1] != playerPawn && !playerTurn)
		{
			pawns[1][1] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][2] == AIPawn && pawns[1][1] == AIPawn && pawns[2][0] != playerPawn && !playerTurn)
		{
			pawns[2][0] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[2][0] == AIPawn && pawns[1][1] == AIPawn && pawns[0][2] != playerPawn && !playerTurn)
		{
			pawns[0][2] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][2] == AIPawn && pawns[2][0] == AIPawn && pawns[1][1] != playerPawn && !playerTurn)
		{
			pawns[1][1] = AIPawn;
			playerTurn = true;
		}
		// Check for checkmate conditions ///////
		// Horizontal two in a row checkmate
		for (int i = 0; i < 3; i++)
		{
			if (pawns[i][0] == playerPawn && pawns[i][1] == playerPawn && pawns[i][2] != AIPawn && !playerTurn)
			{
				pawns[i][2] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[i][1] == playerPawn && pawns[i][2] == playerPawn && pawns[i][0] != AIPawn && !playerTurn)
			{
				pawns[i][0] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[i][0] == playerPawn && pawns[i][2] == playerPawn && pawns[i][1] != AIPawn && !playerTurn)
			{
				pawns[i][1] = AIPawn;
				playerTurn = true;
				break;
			}
		}
		// Vertical two in a row checkmate
		for (int i = 0; i < 3; i++)
		{
			if (pawns[0][i] == playerPawn && pawns[1][i] == playerPawn && pawns[2][i] != AIPawn && !playerTurn)
			{
				pawns[2][i] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[1][i] == playerPawn && pawns[2][i] == playerPawn && pawns[0][i] != AIPawn && !playerTurn)
			{
				pawns[0][i] = AIPawn;
				playerTurn = true;
				break;
			}
			else if (pawns[0][i] == playerPawn && pawns[2][i] == playerPawn && pawns[1][i] != AIPawn && !playerTurn)
			{
				pawns[1][i] = AIPawn;
				playerTurn = true;
				break;
			}
		}
		// Diagonal two in a row checkmate
		if (pawns[0][0] == playerPawn && pawns[1][1] == playerPawn && pawns[2][2] != AIPawn && !playerTurn)
		{
			pawns[2][2] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[1][1] == playerPawn && pawns[2][2] == playerPawn && pawns[0][0] != AIPawn && !playerTurn)
		{
			pawns[0][0] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][0] == playerPawn && pawns[2][2] == playerPawn && pawns[1][1] != AIPawn && !playerTurn)
		{
			pawns[1][1] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][2] == playerPawn && pawns[1][1] == playerPawn && pawns[2][0] != AIPawn && !playerTurn)
		{
			pawns[2][0] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[2][0] == playerPawn && pawns[1][1] == playerPawn && pawns[0][2] != AIPawn && !playerTurn)
		{
			pawns[0][2] = AIPawn;
			playerTurn = true;
		}
		else if (pawns[0][2] == playerPawn && pawns[2][0] == playerPawn && pawns[1][1] != AIPawn && !playerTurn)
		{
			pawns[1][1] = AIPawn;
			playerTurn = true;
		}

		// Take center
		if (pawns[1][1] == '5')
		{
			pawns[1][1] = AIPawn;
			playerTurn = true;
		}
		// Prioritize corners
		else
		{
			int corners[4][2] = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
			for (int i = 0; i < 4; i++)
			{
				int row = corners[i][0];
				int col = corners[i][1];
				if (pawns[row][col] != playerPawn && pawns[row][col] != AIPawn)
				{
					pawns[row][col] = AIPawn;
					playerTurn = true;
					break;
				}
			}
		}

		// If no corners are available, take an edge
		if (!playerTurn)
		{
			int edges[4][2] = { {0, 1}, {1, 0}, {1, 2}, {2, 1} };
			for (int i = 0; i < 4; i++)
			{
				int row = edges[i][0];
				int col = edges[i][1];
				if (pawns[row][col] != playerPawn && pawns[row][col] != AIPawn)
				{
					pawns[row][col] = AIPawn;
					playerTurn = true;
					break;
				}
			}
		}

		// If no center, corners, or edges are available, choose a random spot
		if (!playerTurn)
		{
			do
			{
				randNumber = rand() % 9 + 1;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (pawns[i][j] == (char)randNumber && randNumber != 5)
						{
							pawns[i][j] = AIPawn;
							playerTurn = true;
							break;
						}
					}
				}

			} while (!playerTurn);
		}
	}
	playerTurn = true;
}

void handlePlayerTurn(char pawns[3][3])
{
	if (playerTurn)
	{
		cout << "\nchoose a spot by pressing a number between 1-9\n";
		displayBoard(pawns);
		char number = 'n';
		while (number != '0' && number != '1' && number != '2' && number != '3' && number != '4' && number != '5' && number != '6' && number != '7' && number != '8' && number != '9')
		{
			cin >> number;
			if (number != '0' && number != '1' && number != '2' && number != '3' && number != '4' && number != '5' && number != '6' && number != '7' && number != '8' && number != '9')
			{
				cout << "Please input a number between 1-9\n";
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (pawns[i][j] == number)
				{
					pawns[i][j] = playerPawn;
					break;
				}

			}
		}
	}
	playerTurn = false;
}
