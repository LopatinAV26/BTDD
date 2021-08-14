#include "Game.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Game game(settings);
	game.run();

	return EXIT_SUCCESS;
}
