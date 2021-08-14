#include "ForDeveloper.h"
#include "Game.h"
#include "GLOBAL.h"

ForDeveloper::ForDeveloper()
	: timePeriod(0) {
	debugView.reset(sf::FloatRect(0, 0, Game::windowWidth, Game::windowHeight));
	font.loadFromFile("Resources/Fonts/Droid Sans Mono Slashed.ttf");
	text.setFont(font);
	text.setCharacterSize(12);
}

void ForDeveloper::Update(sf::Time deltaTime, sf::RenderWindow& window) {
	//Отладочная информация
	timePeriod += deltaTime.asSeconds();
	if (timePeriod >= 0.2) {
		string = "FPS.......... " + std::to_string(static_cast<int>(round(1.f / deltaTime.asSeconds())));
		string += "\nframeTime(ms) " + std::to_string(deltaTime.asMilliseconds());
		string += "\nmouseX....... " + std::to_string(int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x));
		string += "\nmouseY....... " + std::to_string(int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y));
		string += "\npositionX.... " + std::to_string(static_cast<int>(globalPlayerPositionX));
		string += "\npositionY.... " + std::to_string(static_cast<int>(globalPlayerPositionY));
		string += "\npositionZ.... " + std::to_string(static_cast<int>(globalPlayerPositionZ));
		string += "\nspeedX....... " + std::to_string(static_cast<int>(globalPlayerSpeedX));
		string += "\nspeedY....... " + std::to_string(static_cast<int>(globalPlayerSpeedY));
		string += "\nspeedZ....... " + std::to_string(static_cast<int>(globalPlayerSpeedZ));
		string += "\ninAir........ " + std::to_string(globalPlayerInAir);
		string += "\nisJump....... " + std::to_string(globalPlayerIsJump);
		text.setString(string);
		timePeriod = 0;
	}
	text.setPosition(debugView.getCenter().x - Game::windowWidth / 2, debugView.getCenter().y - Game::windowHeight / 2);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		debugView.move(400 * deltaTime.asSeconds(), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		debugView.move(-400 * deltaTime.asSeconds(), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		debugView.move(0, -400 * deltaTime.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		debugView.move(0, 400 * deltaTime.asSeconds());
}

void ForDeveloper::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(text, states);
}




