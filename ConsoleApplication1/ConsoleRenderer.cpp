#include "ConsoleRenderer.h"
#include <iostream>
using namespace std;

ConsoleRenderer::ConsoleRenderer(int gameSize)
{
	this->gameSize = gameSize;
}

void ConsoleRenderer::RenderGame(vector<vector<bool>>& gameState)
{
	char liveChar = (char)254u;	// console character for a live cell
	char deadChar = ' ';		// console character for a dead cell

	// Clear the console
	system("cls");

	// Draw game board including live and dead cells
	for (uint8_t y = 0; y < gameSize; y++)
	{
		for (uint8_t x = 0; x < gameSize; x++)
		{
			if (gameState[y][x] == true)
			{
				cout << liveChar;
			}
			else
			{
				cout << deadChar;
			}
		}
		cout << '\n';
	}
}

