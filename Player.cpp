#include "Player.h"
#include <cmath>

Player::Player()
{
    // positionZ = 320;//установить в классе World
    texturePlayer->loadFromFile("Resources/Textures/Billy.png");
    texturePlayer->setSmooth(false);
    spritePlayer->setTexture(*texturePlayer);
    spritePlayer->setTextureRect(sf::IntRect(0, 15, 40, 49));
    spritePlayer->setOrigin(20, 47);
    // spritePlayer->setPosition(100, positionZ);  //Усьановить в World

    physicRectPlayer->setSize(sf::Vector2f(12, 46));
    physicRectPlayer->setOrigin(6, 46);
    physicRectPlayer->setOutlineThickness(0.2);
    physicRectPlayer->setOutlineColor(sf::Color::Green);
    physicRectPlayer->setFillColor(sf::Color::Transparent);

    shadowEllipse->setFillColor(sf::Color::Black);
    shadowEllipse->setRadius(10);
    shadowEllipse->setOrigin(10, 10);
    shadowEllipse->setScale(1, 0.5);
    // shadowEllipse->setPosition(spritePlayer->getPosition().x, positionZ);
}

Player::~Player()
{
    delete shadowEllipse;
    delete spritePlayer;
    delete texturePlayer;
}

void Player::processEvents(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dirX = 1;
        speedX = 100;
    }
    else
        speedX = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dirX = -1;
        speedX = -100;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        speedZ = -100;
    }
    else
        speedZ = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        speedZ = 100;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!inAir)
        {
            speedY = -350;
            inAir = true;
            isJump = true;
        }
    }
}

void Player::update(sf::Time &deltaTime)
{
    currentFrame += speedAnimation * deltaTime.asSeconds();
    if (currentFrame > frameCount)
        currentFrame -= frameCount;

    physicRectPlayer->setPosition(spritePlayer->getPosition());

    positionZ += speedZ / 2 * deltaTime.asSeconds();

    if (inAir)
    {
        speedY += 981 * deltaTime.asSeconds();
    }
    else
    {
        spritePlayer->setPosition(shadowEllipse->getPosition());
        speedY = 0;
        isJump = false;
    }

    if (spritePlayer->getPosition().y < shadowEllipse->getPosition().y)
        inAir = true;
    else
        inAir = false;

    if (speedX != 0 || speedY != 0 || speedZ != 0)
        movePlayer(deltaTime);

    if (speedX == 0 && speedY == 0 && speedZ == 0 && !inAir)
    {
        stay();
    }

    if ((!inAir) && (speedX != 0 || speedZ != 0))
        walk();

    if (isJump)
        jump();
}

float Player::getPositionX() const
{
    return spritePlayer->getPosition().x;
}

float Player::getPositionY() const
{
    return spritePlayer->getPosition().y;
}

float Player::getPositionZ() const
{
    return positionZ;
}

void Player::setSpeedX(float speed)
{
    speedX = speed;
}

void Player::setSpeedY(float speed)
{
    speedY = speed;
}

void Player::setSpeedZ(float speed)
{
    speedZ = speed;
}

float Player::getSpeedX() const
{
    return speedX;
}

float Player::getSpeedY() const
{
    return speedY;
}

float Player::getSpeedZ() const
{
    return speedZ;
}

void Player::movePlayer(sf::Time &deltaTime)
{
    // spritePlayer->move(speedX * deltaTime.asSeconds(), (speedY + speedZ / 2) * deltaTime.asSeconds());
    shadowEllipse->move(speedX * deltaTime.asSeconds(), (speedZ / 2) * deltaTime.asSeconds());
    spritePlayer->move(speedX * deltaTime.asSeconds(), speedY * deltaTime.asSeconds());
}

void Player::stay()
{
    if (!inAir)
    {
        spritePlayer->setTextureRect(sf::IntRect(0, 15, 40, 49));
        if (dirX == 1)
            spritePlayer->setScale(1, 1);
        if (dirX == -1)
            spritePlayer->setScale(-1, 1);
    }
}

void Player::walk()
{
    if (!inAir)
    {
        frameCount = 8;
        frameStep = 40;
        speedAnimation = 12;
        spritePlayer->setTextureRect(sf::IntRect(frameStep * static_cast<int>(currentFrame), 76, 40, 49));
        if (dirX == 1)
            spritePlayer->setScale(1, 1);
        if (dirX == -1)
            spritePlayer->setScale(-1, 1);
    }
}

void Player::jump()
{
    if (inAir && speedY < 0) //Если в воздухе и движется вверх
        spritePlayer->setTextureRect(sf::IntRect(0, 197, 40, 51));
    else if (inAir && speedY >= 0) //Если в воздухе и движется вниз
        spritePlayer->setTextureRect(sf::IntRect(40, 197, 40, 51));

    if (dirX == 1)
        spritePlayer->setScale(1, 1);
    if (dirX == -1)
        spritePlayer->setScale(-1, 1);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*shadowEllipse, states);
    target.draw(*spritePlayer, states);
    target.draw(*physicRectPlayer, states);
}
