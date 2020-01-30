#include "Game.h"
#include <vector>

using namespace std;

Game::Game(int gameSize)
{
	this->gameSize = gameSize;
	this->gameState = vector<vector<bool>>(gameSize, vector<bool>(gameSize, 0));
}

Game::~Game()
{
	gameState.clear();
	gameState.shrink_to_fit();
}

int Game::getGameSize()
{
	return gameSize;
}

vector<vector<bool>> Game::getGameState()
{
	return vector<vector<bool>>(gameState);
}

void Game::Update()
{
	// Begin with a dead game state
	// Game rules will be applied to fill in live cells using the current state
	vector<vector<bool>> newGameState(gameSize, vector<bool>(gameSize, 0));

	// Apply game rules
	// Rule 1: Any live cell with two or three neighbors survives.
	// Rule 2: Any dead cell with three live neighbors becomes a live cell.
	// Rule 3: All other live cells die in the next generation.Similarly, all other dead cells stay dead.
	for (int x = 0; x < gameSize; x++)
	{
		for (int y = 0; y < gameSize; y++)
		{
			// Count live neighbours
			int n = SumNeighbours(x, y);

			// Apply rule 1
			if (gameState[x][y] == true && (n == 2 || n == 3))
			{
				newGameState[x][y] = true;
			}

			// Apply rule 2
			if (gameState[x][y] == false && n == 3)
			{
				newGameState[x][y] = true;
			}

			// Rule 3 is applied implicitly by beginning with a dead game state
		}
	}

	// Return the new game state to the caller
	gameState = newGameState;

	// Release the duplicate game state data
	newGameState.clear();
	newGameState.shrink_to_fit();
}

int Game::SumNeighbours(int x, int y)
{
	int width = size(gameState);
	int height = size(gameState[0]);

	// Determine up, down, left, and right movement with board wrapping rules
	int up = (y == 0) ? (height - 1) : (y - 1);
	int down = (y == height - 1) ? 0 : (y + 1);
	int left = (x == 0) ? (width - 1) : (x - 1);
	int right = (x == width - 1) ? 0 : (x + 1);

	// Sum the values of neighbouring cells
	int s =
		gameState[left][up] + gameState[x][up] + gameState[right][up] +
		gameState[left][y] + gameState[right][y] +
		gameState[left][down] + gameState[x][down] + gameState[right][down];

	return s;
}

void Game::SeedBlinker(int x, int y)
{
	gameState[x][y] = true;
	gameState[x + 1][y] = true;
	gameState[x + 2][y] = true;
}

void Game::SeedBeacon(int x, int y)
{
	gameState[x][y] = true;
	gameState[x + 1][y] = true;
	gameState[x][y + 1] = true;
	gameState[x + 3][y + 2] = true;
	gameState[x + 2][y + 3] = true;
	gameState[x + 3][y + 3] = true;
}

void Game::SeedGlider(int x, int y)
{
	gameState[x][y] = true;
	gameState[x + 2][y] = true;
	gameState[x + 1][y + 1] = true;
	gameState[x + 2][y + 1] = true;
	gameState[x + 1][y + 2] = true;
}

