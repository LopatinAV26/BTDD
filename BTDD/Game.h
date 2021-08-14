#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "ForDeveloper.h"

/**
 * @todo write docs
 */
class Game {
public:
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;
	Game(sf::ContextSettings settings);

	void run(int minimumFramePerSeconds = 30);
	static const int windowWidth {640};
	static const int windowHeight {360};

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	sf::RenderWindow window;
	sf::Clock clock;
	World* world = new World;
	ForDeveloper* debugInfo = new ForDeveloper;
};

#endif // GAME_H
