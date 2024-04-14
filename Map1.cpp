#include "Map1.h"
#include <stdexcept>

Map1::Map1() {
    physicRectPositionZ = 0;

    map1PhysicRect1->setSize(sf::Vector2f(128, 1));
    map1PhysicRect1->setOutlineThickness(0.2);
    map1PhysicRect1->setOutlineColor(sf::Color::Red);
    map1PhysicRect1->setFillColor(sf::Color::Transparent);

    map1PhysicRect2Up->setSize(sf::Vector2f(9, 9));
    map1PhysicRect2Up->setOutlineThickness(0.2);
    map1PhysicRect2Up->setOutlineColor(sf::Color::Red);
    map1PhysicRect2Up->setFillColor(sf::Color::Transparent);

    map1PhysicRect3->setSize(sf::Vector2f(25, 1));
    map1PhysicRect3->setOutlineThickness(0.2);
    map1PhysicRect3->setOutlineColor(sf::Color::Red);
    map1PhysicRect3->setFillColor(sf::Color::Transparent);

    map1PhysicRect4Up->setSize(sf::Vector2f(9, 9));
    map1PhysicRect4Up->setOutlineThickness(0.2);
    map1PhysicRect4Up->setOutlineColor(sf::Color::Red);
    map1PhysicRect4Up->setFillColor(sf::Color::Transparent);

    map1PhysicRect5->setSize(sf::Vector2f(89, 1));
    map1PhysicRect5->setOutlineThickness(0.2);
    map1PhysicRect5->setOutlineColor(sf::Color::Red);
    map1PhysicRect5->setFillColor(sf::Color::Transparent);

    if (!textureSpace->loadFromFile("Resources/Textures/Space.png"))
        throw std::runtime_error("Impossible to load file");
    textureSpace->setSmooth(false);
    textureSpace->setRepeated(true);
    spriteSpace->setTexture(*textureSpace);
    spriteSpace->setTextureRect(sf::IntRect(0, 0, 2174, 600));
    spriteSpace->setPosition(0, 0);

    spriteSpace2->setTexture(*textureSpace);
    spriteSpace2->setTextureRect(spriteSpace->getTextureRect());
    spriteSpace2->setPosition(spriteSpace->getPosition().x + spriteSpace->getTextureRect().width, 0);

    textureShip->loadFromFile("Resources/Textures/Ship.png");
    textureShip->setSmooth(false);
    spriteShip->setTexture(*textureShip);
    spriteShip->setTextureRect(sf::IntRect(0, 0, 2174, 423));
    spriteShip->setPosition(0, 0);

    spriteDoor->setTexture(*textureShip);
    spriteDoor->setTextureRect(sf::IntRect(6, 546, 153, 119));
    spriteDoor->setPosition(spriteShip->getPosition().x + 2016, spriteShip->getPosition().y + 167);

    spriteFan->setTexture(*textureShip);
    spriteFan->setTextureRect(sf::IntRect(1025, 600, 31, 32));
    vectorFan.reserve(14);
    for (uint index = 0; index < vectorFan.capacity(); ++index) {
        vectorFan.push_back(*spriteFan);
    }
    vectorFan[0].setPosition(spriteShip->getPosition().x + 481, spriteShip->getPosition().y + 271);
    vectorFan[1].setPosition(spriteShip->getPosition().x + 673, spriteShip->getPosition().y + 239);
    vectorFan[2].setPosition(spriteShip->getPosition().x + 1185, spriteShip->getPosition().y + 271);
    vectorFan[3].setPosition(spriteShip->getPosition().x + 1249, spriteShip->getPosition().y + 303);
    vectorFan[4].setPosition(spriteShip->getPosition().x + 1697, spriteShip->getPosition().y + 239);
    vectorFan[5].setPosition(spriteShip->getPosition().x + 1729, spriteShip->getPosition().y + 255);
    vectorFan[6].setPosition(spriteShip->getPosition().x + 1761, spriteShip->getPosition().y + 271);
    vectorFan[7].setPosition(spriteShip->getPosition().x + 1793, spriteShip->getPosition().y + 287);
    vectorFan[8].setPosition(spriteShip->getPosition().x + 1825, spriteShip->getPosition().y + 303);
    vectorFan[9].setPosition(spriteShip->getPosition().x + 1986, spriteShip->getPosition().y + 207);
    vectorFan[10].setPosition(spriteShip->getPosition().x + 2017, spriteShip->getPosition().y + 175);
    vectorFan[11].setPosition(spriteShip->getPosition().x + 2049, spriteShip->getPosition().y + 143);
    vectorFan[12].setPosition(spriteShip->getPosition().x + 2113, spriteShip->getPosition().y + 271);
    vectorFan[13].setPosition(spriteShip->getPosition().x + 2146, spriteShip->getPosition().y + 239);

    /*
        polygon1.setPrimitiveType(sf::LineStrip);
        polygon1.resize(6);
        polygon1[0].position = sf::Vector2f(0, 319);
        polygon1[1].position = sf::Vector2f(32, 303);
        polygon1[2].position = sf::Vector2f(95, 303);
        polygon1[3].position = sf::Vector2f(159, 335);
        polygon1[4].position = sf::Vector2f(32, 335);
        polygon1[5].position = sf::Vector2f(0, 319);

        polygon2rightUp.setPrimitiveType(sf::LineStrip);
        polygon2rightUp.resize(5);
        polygon2rightUp[0].position = sf::Vector2f(95, 303);
        polygon2rightUp[1].position = sf::Vector2f(103, 295);
        polygon2rightUp[2].position = sf::Vector2f(167, 327);
        polygon2rightUp[3].position = sf::Vector2f(159, 335);
        polygon2rightUp[4].position = sf::Vector2f(95, 303);

        polygon3.setPrimitiveType(sf::LineStrip);
        polygon3.resize(5);
        polygon3[0].position = sf::Vector2f(103, 295);
        polygon3[1].position = sf::Vector2f(127, 295);
        polygon3[2].position = sf::Vector2f(191, 327);
        polygon3[3].position = sf::Vector2f(167, 327);
        polygon3[4].position = sf::Vector2f(103, 295);

        polygon4rightUp.setPrimitiveType(sf::LineStrip);
        polygon4rightUp.resize(5);
        polygon4rightUp[0].position = sf::Vector2f(127, 295);
        polygon4rightUp[1].position = sf::Vector2f(135, 287);
        polygon4rightUp[2].position = sf::Vector2f(199, 319);
        polygon4rightUp[3].position = sf::Vector2f(191, 327);
        polygon4rightUp[4].position = sf::Vector2f(127, 295);

        polygon5.setPrimitiveType(sf::LineStrip);
        polygon5.resize(5);
        polygon5[0].position = sf::Vector2f(135, 287);
        polygon5[1].position = sf::Vector2f(223, 287);
        polygon5[2].position = sf::Vector2f(287, 319);
        polygon5[3].position = sf::Vector2f(199, 319);
        polygon5[4].position = sf::Vector2f(135, 287);

        polygon6rightUp.setPrimitiveType(sf::LineStrip);
        polygon6rightUp.resize(5);
        polygon6rightUp[0].position = sf::Vector2f(223, 287);
        polygon6rightUp[1].position = sf::Vector2f(255, 255);
        polygon6rightUp[2].position = sf::Vector2f(319, 287);
        polygon6rightUp[3].position = sf::Vector2f(287, 319);
        polygon6rightUp[4].position = sf::Vector2f(223, 287);

        polygon7.setPrimitiveType(sf::LineStrip);
        polygon7.resize(5);
        polygon7[0].position = sf::Vector2f(255, 255);
        polygon7[1].position = sf::Vector2f(290, 255);
        polygon7[2].position = sf::Vector2f(352, 287);
        polygon7[3].position = sf::Vector2f(319, 287);
        polygon7[4].position = sf::Vector2f(255, 255);

        polygon8rightDown.setPrimitiveType(sf::LineStrip);
        polygon8rightDown.resize(5);
        polygon8rightDown[0].position = sf::Vector2f(290, 255);
        polygon8rightDown[1].position = sf::Vector2f(322, 287);
        polygon8rightDown[2].position = sf::Vector2f(384, 319);
        polygon8rightDown[3].position = sf::Vector2f(352, 287);
        polygon8rightDown[4].position = sf::Vector2f(290, 255);

        polygon9.setPrimitiveType(sf::LineStrip);
        polygon9.resize(5);
        polygon9[0].position = sf::Vector2f(322, 287);
        polygon9[1].position = sf::Vector2f(447, 287);
        polygon9[2].position = sf::Vector2f(511, 319);
        polygon9[3].position = sf::Vector2f(384, 319);
        polygon9[4].position = sf::Vector2f(322, 287);
    */
}

Map1::~Map1() {
    delete spriteDoor;
    delete spriteFan;
    delete spriteShip;
    delete textureShip;
    delete spriteSpace2;
    delete spriteSpace;
    delete textureSpace;
}

void Map1::update(sf::Time deltaTime) {
    map1PhysicRect1->setPosition(-32 + physicRectPositionZ * 2, 303 + physicRectPositionZ);
    map1PhysicRect2Up->setPosition(95 + physicRectPositionZ * 2, 295 + physicRectPositionZ);
    map1PhysicRect3->setPosition(103 + physicRectPositionZ * 2, 295 + physicRectPositionZ);
    map1PhysicRect4Up->setPosition(127 + physicRectPositionZ * 2, 287 + physicRectPositionZ);
    map1PhysicRect5->setPosition(135 + physicRectPositionZ * 2, 287 + physicRectPositionZ);

//Анимация вентиляторов
    currentFrameFan += speedFan * deltaTime.asSeconds();
    if (currentFrameFan > 4)
        currentFrameFan -= 4;

    for (auto &index : vectorFan) {
        index.setTextureRect(sf::IntRect(33 * static_cast<int>(currentFrameFan) + 1025, 600, 31, 32));
    }

//Зацикленное движение звёзд
    spriteSpace->move(-20 * deltaTime.asSeconds(), 0);
    spriteSpace2->move(-20 * deltaTime.asSeconds(), 0);

    if ((spriteSpace->getPosition().x + spriteSpace->getTextureRect().width) < spriteShip->getPosition().x)
        spriteSpace->setPosition(spriteShip->getGlobalBounds().width, 0);

    if ((spriteSpace2->getPosition().x + spriteSpace2->getTextureRect().width) < spriteShip->getPosition().x)
        spriteSpace2->setPosition(spriteShip->getGlobalBounds().width, 0);

}

void Map1::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*spriteSpace, states);
    target.draw(*spriteSpace2, states);
    target.draw(*spriteShip, states);
    target.draw(*spriteDoor, states);

    //Отрисовка всех вентиляторов
    for (auto &index : vectorFan) {
        target.draw(index, states);
    }

    /*
        target.draw(polygon1);
        target.draw(polygon2rightUp);
        target.draw(polygon3);
        target.draw(polygon4rightUp);
        target.draw(polygon5);
        target.draw(polygon6rightUp);
        target.draw(polygon7);
        target.draw(polygon8rightDown);
        target.draw(polygon9);
    */
    target.draw(*map1PhysicRect1);
    target.draw(*map1PhysicRect2Up);
    target.draw(*map1PhysicRect3);
    target.draw(*map1PhysicRect4Up);
    target.draw(*map1PhysicRect5);

}




