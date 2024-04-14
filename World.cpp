#include "World.h"
#include "GLOBAL.h"

float globalPlayerPositionX;
float globalPlayerPositionY;
float globalPlayerPositionZ;
float globalPlayerSpeedX;
float globalPlayerSpeedY;
float globalPlayerSpeedZ;
bool globalPlayerInAir;
bool globalPlayerIsJump;

World::World()
    : ratship(new Map1),
      billy(new Player) {
    billy->shadowEllipse->setPosition(50, 320);
    billy->positionZ = 16;
}

/*void World::clear() {
   sounds.clear();
}*/

/*void World::add(Configuration::Sounds sound_id) {
    std::unique_ptr<sf::Sound> sound(new sf::Sound(Configuration::sounds.get(sound_id)));
    sound->setAttenuation(0);
    sound->play();
    sounds.emplace_back(std::move(sound));
}*/

void World::update(sf::Time &deltaTime) {
    ratship->update(deltaTime);
//---------------------------------------------------
    if (billy != nullptr) {
        billy->update(deltaTime);
        globalPlayerPositionX = billy->getPositionX();
        globalPlayerPositionY = billy->getPositionY();
        globalPlayerPositionZ = billy->getPositionZ();
        globalPlayerSpeedX = billy->getSpeedX();
        globalPlayerSpeedY = billy->getSpeedY();
        globalPlayerSpeedZ = billy->getSpeedZ();
        globalPlayerInAir = billy->inAir;
        globalPlayerIsJump = billy->isJump;

        ratship->physicRectPositionZ = billy->getPositionZ();

        /*        typedef boost::geometry::model::d2::point_xy<double> point_type;
                typedef boost::geometry::model::polygon<point_type> polygon_type;
                polygon_type poly1;
                boost::geometry::read_wkt("POLYGON((0 320,32 303,95 303,159 335,32 335,0 320))", poly1);

                polygon_type poly2rightUp;
                boost::geometry::read_wkt("POLYGON((95 303,103 295,167 327,159 335,95 303))", poly2rightUp);

                polygon_type poly3;
                boost::geometry::read_wkt("POLYGON((103 295,127 295,191 327,167 327,103 295))", poly3);

                polygon_type poly4rightUp;
                boost::geometry::read_wkt("POLYGON((127 295, 135 287, 199 319, 191 327, 127 295))", poly4rightUp);

                polygon_type poly5;
                boost::geometry::read_wkt("POLYGON((135 287, 223 287, 287 319, 199 319, 135 287))", poly5);

                polygon_type poly6rightUp;
                boost::geometry::read_wkt("POLYGON((223 287, 255 255, 319 287, 287 319, 223 287))", poly6rightUp);

                polygon_type poly7;
                boost::geometry::read_wkt("POLYGON((255 255, 290 255, 352 287, 319 287, 255 255))", poly7);

                polygon_type poly8rightDown;
                boost::geometry::read_wkt("POLYGON((290 255, 322 287, 384 319, 352 287, 290 255))", poly8rightDown);

                polygon_type poly9;
                boost::geometry::read_wkt("POLYGON((322 287, 447 287, 511 319, 384 319, 322 287))", poly9);

                point_type p(billy->shadowEllipse->getPosition().x, billy->shadowEllipse->getPosition().y);

        //Проверка стоит ли персонаж на поверхности
                if ((!boost::geometry::within(p, poly1))
                        && (!boost::geometry::within(p, poly2rightUp))
                        && (!boost::geometry::within(p, poly3))
                        && (!boost::geometry::within(p, poly4rightUp))
                        && (!boost::geometry::within(p, poly5))
                        && (!boost::geometry::within(p, poly6rightUp))
                        && (!boost::geometry::within(p, poly7))
                        //&& (!boost::geometry::within(p, poly8rightDown))
                        && (!boost::geometry::within(p, poly9))) {
                    billy->inAir = true;
                }

        //Движение по левым наклонным поверхностям
                if (((boost::geometry::within(p, poly2rightUp))
                        || (boost::geometry::within(p, poly4rightUp))
                        || (boost::geometry::within(p, poly6rightUp)))) {
                    billy->shadowEllipse->move(0, (-billy->getSpeedX() + billy->getSpeedZ() / 2) * deltaTime.asSeconds());
                }
        */



//Движение по правым наклонным плоскостям
       /* if (ratship->rectPoly8.getGlobalBounds().contains(billy->shadowEllipse->getPosition())) {
            ratship->rectPoly8.setFillColor(sf::Color(255, 0, 0, 150));
            billy->shadowEllipse->move(0, (billy->getSpeedX() - billy->getSpeedZ()) * deltaTime.asSeconds());
        } else ratship->rectPoly8.setFillColor(sf::Color(255, 255, 255, 150));*/
    }
}

void World::processEvents(sf::Event event) {
    if (billy != nullptr)
        billy->processEvents(event);
}

bool World::collisionWithMap() {
    return true;
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*ratship);

    if (billy != nullptr)
        target.draw(*billy);
}







