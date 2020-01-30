//#include "Game.h"
//using namespace std;
//
//uint8_t SumNeighbours(uint8_t x, uint8_t y, const vector<vector<bool>>& gameState);
//
//
//void InitialiseGame(uint8_t gameSize, vector<vector<bool>> &gameState)
//{
//	gameState = vector<vector<bool>>(gameSize, vector<bool>(gameSize, 0));
//}
//
//void ReleaseGame(vector<vector<bool>>& gameState)
//{
//	gameState.clear();
//	gameState.shrink_to_fit();
//}
//
//void UpdateGame(vector<vector<bool>> &gameState)
//{
//	// Begin with a dead game state
//	// Game rules will be applied to fill in live cells using the current state
//	uint8_t width = size(gameState);
//	uint8_t height = size(gameState[0]);
//	vector<vector<bool>> newGameState(width, vector<bool>(height, 0));
//
//	// Apply game rules
//	// Rule 1: Any live cell with two or three neighbors survives.
//	// Rule 2: Any dead cell with three live neighbors becomes a live cell.
//	// Rule 3: All other live cells die in the next generation.Similarly, all other dead cells stay dead.
//	for (uint8_t x = 0; x < width; x++)
//	{
//		for (uint8_t y = 0; y < height; y++)
//		{
//			// Count live neighbours
//			uint8_t n = SumNeighbours(x, y, gameState);
//
//			// Apply rule 1
//			if (gameState[x][y] == true && (n == 2 || n == 3))
//			{
//				newGameState[x][y] = true;
//			}
//
//			// Apply rule 2
//			if (gameState[x][y] == false && n == 3)
//			{
//				newGameState[x][y] = true;
//			}
//
//			// Rule 3 is applied implicitly by beginning with a dead game state
//		}
//	}
//
//	// Return the new game state to the caller
//	gameState = newGameState;
//
//	// Release the duplicate game state data
//	newGameState.clear();
//	newGameState.shrink_to_fit();
//}
//
//uint8_t SumNeighbours(uint8_t x, uint8_t y, const vector<vector<bool>>& gameState)
//{
//	uint8_t width = size(gameState);
//	uint8_t height = size(gameState[0]);
//
//	// Determine up, down, left, and right movement with board wrapping rules
//	uint8_t up = (y == 0) ? (height - 1) : (y - 1);
//	uint8_t down = (y == height - 1) ? 0 : (y + 1);
//	uint8_t left = (x == 0) ? (width - 1) : (x - 1);
//	uint8_t right = (x == width - 1) ? 0 : (x + 1);
//
//	// Sum the values of neighbouring cells
//	uint8_t s = 
//		gameState[left][up] + gameState[x][up] + gameState[right][up] +
//		gameState[left][y] + gameState[right][y] +
//		gameState[left][down] + gameState[x][down] + gameState[right][down];
//
//	return s;
//}
//
//void SeedBlinker(uint8_t x, uint8_t y, vector<vector<bool>> &gameState)
//{
//	gameState[x][y] = true;
//	gameState[x + 1][y] = true;
//	gameState[x + 2][y] = true;
//}
//
//void SeedBeacon(uint8_t x, uint8_t y, vector<vector<bool>>& gameState)
//{
//	gameState[x][y] = true;
//	gameState[x + 1][y] = true;
//	gameState[x][y + 1] = true;
//	gameState[x + 3][y + 2] = true;
//	gameState[x + 2][y + 3] = true;
//	gameState[x + 3][y + 3] = true;
//}
//
//void SeedGlider(uint8_t x, uint8_t y, vector<vector<bool>>& gameState)
//{
//	gameState[x][y] = true;
//	gameState[x + 2][y] = true;
//	gameState[x + 1][y + 1] = true;
//	gameState[x + 2][y + 1] = true;
//	gameState[x + 1][y + 2] = true;
//}