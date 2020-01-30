#pragma once
#include <vector>

class Game
{
public:
	Game(int gameSize);
	~Game();

	void Update();
	void SeedBlinker(int x, int y);
	void SeedBeacon(int x, int y);
	void SeedGlider(int x, int y);
	
	// Property accessors
	int getGameSize();
	std::vector<std::vector<bool>> getGameState();

private:
	int SumNeighbours(int x, int y);

	std::vector<std::vector<bool>> gameState;
	int gameSize;
};

