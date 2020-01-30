#include "Game.h"
#include "Renderer.h"
#include "SDL2Renderer.h"
#include "ConsoleRenderer.h"

#include <thread>
#include <chrono>

using namespace std;

constexpr uint8_t GAME_SIZE = 20;
constexpr uint32_t GAME_LENGTH = 100;
constexpr auto GAME_FREQUENCY = 10;

int main(int argc, char *argv[])
{
	// Select and instantiate a renderer
	Renderer *renderer = new SDL2Renderer(GAME_SIZE, 10);
	//Renderer* renderer = new ConsoleRenderer(GAME_SIZE);

	// Initialise the game
	Game* game = new Game(GAME_SIZE);
	game->SeedBlinker(15, 2);
	game->SeedBeacon(0, 5);
	game->SeedGlider(11, 10);

	// Run the game
	for (uint32_t i = 0; i < GAME_LENGTH; i++)
	{
		game->Update();
		auto state = game->getGameState();
		renderer->RenderGame(state);
		this_thread::sleep_for(chrono::milliseconds(1000 / GAME_FREQUENCY));
	}

	return 0;
}