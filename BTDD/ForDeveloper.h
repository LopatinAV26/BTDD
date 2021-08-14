#ifndef FORDEVELOPER_H
#define FORDEVELOPER_H

#include <SFML/Graphics.hpp>

/**
 * @todo write docs
 */
class ForDeveloper : public sf::Drawable, public sf::Transformable {
public:
	ForDeveloper(const ForDeveloper&) = delete;
	ForDeveloper& operator=(const ForDeveloper&) = delete;
	ForDeveloper();

	void Update(sf::Time deltaTime, sf::RenderWindow& window);
	sf::View debugView;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::String string;
	sf::Font font;
	sf::Text text;
	float timePeriod;
};

#endif // FORDEVELOPER_H
