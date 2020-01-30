#include "SDL2Renderer.h"

using namespace std;

SDL2Renderer::SDL2Renderer(int gameSize, int squareSize)
{
	this->gameSize = gameSize;
	this->squareSize = squareSize;

	int windowSize = (gameSize * squareSize);

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize, windowSize, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

SDL2Renderer::~SDL2Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void SDL2Renderer::RenderGame(vector<vector<bool>>& gameState)
{
	SDL_Color fill;
	SDL_Color outline;

	// Live cell fill is black
	fill.a = 255;
	fill.r = 0;
	fill.g = 0;
	fill.b = 0;

	// Live cell outline is white
	outline.a = 255;
	outline.r = 255;
	outline.g = 255;
	outline.b = 255;

	// Clear window
	SDL_RenderClear(renderer);

	// Draw live cells
	SDL_Rect cell;
	cell.w = squareSize;
	cell.h = squareSize;

	for (int x = 0; x < gameSize; x++)
	{
		for (int y = 0; y < gameSize; y++)
		{
			if (gameState[y][x])
			{
				cell.x = x * squareSize;
				cell.y = y * squareSize;

				// Draw fill
				SDL_SetRenderDrawColor(renderer, fill.r, fill.g, fill.b, fill.a);
				SDL_RenderFillRect(renderer, &cell);

				// Draw outline
				SDL_SetRenderDrawColor(renderer, outline.r, outline.g, outline.b, outline.a);
				SDL_RenderDrawRect(renderer, &cell);
			}
		}
	}

	SDL_RenderPresent(renderer);
}
