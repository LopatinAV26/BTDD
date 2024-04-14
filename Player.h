#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable {
public:
    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;
    Player();
    ~Player();

    void processEvents(sf::Event event);
    void update(sf::Time &deltaTime);

    float getPositionX()const;
    float getPositionY()const;
    float getPositionZ()const;

    void setSpeedX(float speed);
    void setSpeedY(float speed);
    void setSpeedZ(float speed);

    float getSpeedX()const;
    float getSpeedY()const;
    float getSpeedZ()const;

    float positionZ;
    bool inAir {false};
    bool isJump {false};
    bool isWalk {false};
    sf::RectangleShape *physicRectPlayer = new sf::RectangleShape;
    sf::CircleShape *shadowEllipse = new sf::CircleShape;

private:
    void movePlayer(sf::Time &deltaTime);
    void stay();
    void walk();
    void jump();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

    sf::Texture *texturePlayer = new sf::Texture;
    sf::Sprite *spritePlayer = new sf::Sprite;

    uint8_t speedAnimation;
    uint8_t frameCount;
    uint8_t frameStep {0};
    float currentFrame;
    
    float speedX;
    float speedY;
    float speedZ;
    int8_t dirX {1};
    int8_t dirY {0};
};

#endif // PLAYER_H
