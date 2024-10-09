#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;


void calculateWinPatterns(char pawns[3][3]);
void handleAITurn(char pawns[3][3]);
void handlePlayerTurn(char pawns[3][3]);
void displayBoard(char pawns[3][3]);

bool gameOver = false;
bool playerWon = false;
bool AIWon = false;
bool draw = true;
int totalTurns = 0;
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


		if (playerTurn)
		{
			handlePlayerTurn(pawns);
		}
		else 
		{
			handleAITurn(pawns);
		}

		// Display game board
		displayBoard(pawns);

		// Decide if game is over, check if it's a draw or decide who won
		calculateWinPatterns(pawns);

		// Toggle the turn
		playerTurn = !playerTurn;
	}

	return 0;
}

void displayBoard(char pawns[3][3])
{

	if (playerTurn)
	{
		cout << "Player:";
	}
	else if(!playerTurn)
	{
		cout << "AI:";
	}
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
				draw = false;
			}
			else if (pawns[0][i] == AIPawn)
			{
				AIWon = true;
				draw = false;
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
				draw = false;
			}
			else if (pawns[0][i] == AIPawn)
			{
				AIWon = true;
				draw = false;
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
			draw = false;
		}
		else if (pawns[0][0] == AIPawn)
		{
			AIWon = true;
			draw = false;
		}
		gameOver = true;
	}
	if (pawns[0][2] == 'x' && pawns[1][1] == 'x' && pawns[2][0] == 'x')
	{
		if (pawns[0][2] == playerPawn)
		{
			playerWon = true;
			draw = false;
		}
		else if (pawns[0][2] == AIPawn)
		{
			AIWon = true;
			draw = false;
		}
		gameOver = true;
	}
	// Diagonal for o pawn
	if (pawns[0][0] == 'o' && pawns[1][1] == 'o' && pawns[2][2] == 'o')
	{
		if (pawns[0][0] == playerPawn)
		{
			playerWon = true;
			draw = false;
		}
		else if (pawns[0][0] == AIPawn)
		{
			AIWon = true;
			draw = false;
		}
		gameOver = true;
	}
	if (pawns[0][2] == 'o' && pawns[1][1] == 'o' && pawns[2][0] == 'o')
	{
		if (pawns[0][2] == playerPawn)
		{
			playerWon = true;
			draw = false;
		}
		else if (pawns[0][2] == AIPawn)
		{
			AIWon = true;
			draw = false;
		}
		gameOver = true;
	}
	////////////////////////////////////////////////////////////////////////
	if (totalTurns == 9 && !playerWon && !AIWon)
	{
		cout << "The game is a draw!\n";
		gameOver = true;
	}
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
	if (!gameOver)
	{
		totalTurns++;
		// Try to win or block player from winning
		// Check for horizontal two-in-a-row condition for AI or Player
		for (int i = 0; i < 3; i++)
		{
			if (pawns[i][0] == AIPawn && pawns[i][1] == AIPawn && pawns[i][2] != playerPawn && pawns[i][2] != AIPawn)
			{
				pawns[i][2] = AIPawn;
				return;
			}
			else if (pawns[i][1] == AIPawn && pawns[i][2] == AIPawn && pawns[i][0] != playerPawn && pawns[i][0] != AIPawn)
			{
				pawns[i][0] = AIPawn;
				return;
			}
			else if (pawns[i][0] == AIPawn && pawns[i][2] == AIPawn && pawns[i][1] != playerPawn && pawns[i][1] != AIPawn)
			{
				pawns[i][1] = AIPawn;
				return;
			}
		}

		// Check for vertical two-in-a-row condition for AI or Player
		for (int i = 0; i < 3; i++)
		{
			if (pawns[0][i] == AIPawn && pawns[1][i] == AIPawn && pawns[2][i] != playerPawn && pawns[2][i] != AIPawn)
			{
				pawns[2][i] = AIPawn;
				return;
			}
			else if (pawns[1][i] == AIPawn && pawns[2][i] == AIPawn && pawns[0][i] != playerPawn && pawns[0][i] != AIPawn)
			{
				pawns[0][i] = AIPawn;
				return;
			}
			else if (pawns[0][i] == AIPawn && pawns[2][i] == AIPawn && pawns[1][i] != playerPawn && pawns[1][i] != AIPawn)
			{
				pawns[1][i] = AIPawn;
				return;
			}
		}

		// Check diagonal two-in-a-row condition for AI or Player
		if (pawns[0][0] == AIPawn && pawns[1][1] == AIPawn && pawns[2][2] != playerPawn && pawns[2][2] != AIPawn)
		{
			pawns[2][2] = AIPawn;
			return;
		}
		else if (pawns[2][2] == AIPawn && pawns[1][1] == AIPawn && pawns[0][0] != playerPawn && pawns[0][0] != AIPawn)
		{
			pawns[0][0] = AIPawn;
			return;
		}
		else if (pawns[0][2] == AIPawn && pawns[1][1] == AIPawn && pawns[2][0] != playerPawn && pawns[2][0] != AIPawn)
		{
			pawns[2][0] = AIPawn;
			return;
		}
		else if (pawns[2][0] == AIPawn && pawns[1][1] == AIPawn && pawns[0][2] != playerPawn && pawns[0][2] != AIPawn)
		{
			pawns[0][2] = AIPawn;
			return;
		}

		// Take center if available
		if (pawns[1][1] != playerPawn && pawns[1][1] != AIPawn)
		{
			pawns[1][1] = AIPawn;
			return;
		}

		// Prioritize corners
		int corners[4][2] = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
		for (int i = 0; i < 4; i++)
		{
			int row = corners[i][0];
			int col = corners[i][1];
			if (pawns[row][col] != playerPawn && pawns[row][col] != AIPawn)
			{
				pawns[row][col] = AIPawn;
				return;
			}
		}

		// If no corners, take an edge
		int edges[4][2] = { {0, 1}, {1, 0}, {1, 2}, {2, 1} };
		for (int i = 0; i < 4; i++)
		{
			int row = edges[i][0];
			int col = edges[i][1];
			if (pawns[row][col] != playerPawn && pawns[row][col] != AIPawn)
			{
				pawns[row][col] = AIPawn;
				return;
			}
		}

		// If no strategic moves left, place in a random available spot
		std::vector<int> availableSpots;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (pawns[i][j] != playerPawn && pawns[i][j] != AIPawn)
				{
					// Convert board position (i,j) to a corresponding number 1-9
					availableSpots.push_back(i * 3 + j + 1);
				}
			}
		}

		if (!availableSpots.empty())
		{
			// Randomly select one of the available spots
			int randomIndex = rand() % availableSpots.size();
			int chosenSpot = availableSpots[randomIndex];

			// Convert the chosenSpot number back to board coordinates
			int row = (chosenSpot - 1) / 3;
			int col = (chosenSpot - 1) % 3;
			pawns[row][col] = AIPawn;
		}
	}
	
}

void handlePlayerTurn(char pawns[3][3])
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
				totalTurns++;
				break;
			}
		}
	}	
}
