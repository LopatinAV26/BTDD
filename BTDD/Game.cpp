#include "Game.h"

Game::Game(sf::ContextSettings settings)
	: window(sf::VideoMode(windowWidth, windowHeight, 32), "Battle Toads & Double Dragon", sf::Style::Default, settings) {
	//window.setFramerateLimit(60);
}
////////////////////////////////////////////
void Game::run(int minimumFramePerSeconds) {
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

	while (window.isOpen()) {
		processEvents();
		timeSinceLastUpdate = clock.restart();

		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		update(timeSinceLastUpdate);
		render();
	}
}
//Обработка событий---------
void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if ((event.type == sf::Event::Closed)
			or ((event.type == sf::Event::KeyPressed)
				and (event.key.code == sf::Keyboard::Escape))) {
			window.close();
		}
	}
	world->processEvents(event);
}
////////////////////////////////////////
void Game::update(sf::Time deltaTime) {
	world->update(deltaTime);
	debugInfo->Update(deltaTime, window);
}
///////////////////////
void Game::render() {
	//window.setView(world->view);
	window.setView(debugInfo->debugView);
	window.clear();
	window.draw(*world);
	window.draw(*debugInfo);
	window.display();
}

