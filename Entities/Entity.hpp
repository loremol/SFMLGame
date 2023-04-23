//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLGAME_ENTITY_HPP
#define SFMLGAME_ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity() = default;

    ~Entity() = default;

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f positionVector;
};


#endif //SFMLGAME_ENTITY_HPP
