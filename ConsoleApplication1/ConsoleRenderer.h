#pragma once
#include "Renderer.h"

class ConsoleRenderer : public Renderer
{
public:
	ConsoleRenderer(int gameSize);
	void RenderGame(std::vector<std::vector<bool>>& gameState);

private:
	int gameSize;
};

