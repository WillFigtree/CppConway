#pragma once
#include <vector>

// Abstract base class for different renderer implementations
class Renderer
{
public:
	virtual void RenderGame(std::vector<std::vector<bool>>& gameState) = 0;
	virtual ~Renderer() = default;
};

