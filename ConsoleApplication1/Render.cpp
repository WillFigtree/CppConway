#include "Render.h"
#include <iostream>
using namespace std;

constexpr auto BOX_CHAR = (char)254u;


void RenderGame(vector<vector<bool>> &gameState)
{
	// magic clear console command
	system("cls");

	uint8_t height = size(gameState);
	uint8_t width = size(gameState[0]);

	for (uint8_t y = 0; y < height; y++)
	{
		for (uint8_t x = 0; x < width; x++)
		{
			if (gameState[y][x] == true)
			{
				cout << BOX_CHAR;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}
}
