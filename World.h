#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map1.h"
#include "Player.h"
//#include <boost/geometry.hpp>

class World : public sf::Drawable  {
public:
    World(const World&) = delete;
    World &operator=(const World &) = delete;
    World();

    void update(sf::Time &deltaTime);
    void processEvents(sf::Event event);
    //void add(Entity *entity);
    //void clear();
    //void add(Configuration::Sounds sound_id);
    //bool isCollide(const Entity &other);

private:
    bool collisionWithMap();

    //float physicsUpdatePeriod{0};
    //std::list<std::unique_ptr<sf::Sound>> sounds;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Map1 *ratship = nullptr;
    Player *billy = nullptr;
};

#endif // WORLD_H



