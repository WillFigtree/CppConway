#pragma once
#include "Renderer.h"
#include <SDL.h>

class SDL2Renderer : public Renderer
{
public:
	SDL2Renderer(int gameSize, int squareSize);
	~SDL2Renderer();

	void RenderGame(std::vector<std::vector<bool>>& gameState);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int gameSize;
	int squareSize;
};

