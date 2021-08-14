#ifndef MAP1_H
#define MAP1_H

#include <SFML/Graphics.hpp>
/**
 * @todo write docs
 */
class Map1 : public sf::Drawable {
public:
	Map1(const Map1&) = delete;
	Map1& operator=(const Map1&) = delete;
	Map1();
	~Map1();

	void update(sf::Time deltaTime);

	/*
		sf::VertexArray polygon1;
		sf::VertexArray polygon2rightUp;
		sf::VertexArray polygon3;
		sf::VertexArray polygon4rightUp;
		sf::VertexArray polygon5;
		sf::VertexArray polygon6rightUp;
		sf::VertexArray polygon7;
		sf::VertexArray polygon8rightDown;
		sf::VertexArray polygon9;
	*/
	sf::RectangleShape* map1PhysicRect1 = new sf::RectangleShape;
	sf::RectangleShape* map1PhysicRect2Up = new sf::RectangleShape;
	sf::RectangleShape* map1PhysicRect3 = new sf::RectangleShape;
	sf::RectangleShape* map1PhysicRect4Up = new sf::RectangleShape;
	sf::RectangleShape* map1PhysicRect5 = new sf::RectangleShape;

	int physicRectPositionZ;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Texture* textureSpace = new sf::Texture;
	sf::Sprite* spriteSpace = new sf::Sprite;
	sf::Sprite* spriteSpace2 = new sf::Sprite;
	sf::Texture* textureShip = new sf::Texture;
	sf::Sprite* spriteShip = new sf::Sprite;
	sf::Sprite* spriteFan = new sf::Sprite;
	sf::Sprite* spriteDoor = new sf::Sprite;
	std::vector<sf::Sprite>vectorFan;
	float currentFrameFan{0};
	unsigned int speedFan{20};
};

#endif // MAP1_H
