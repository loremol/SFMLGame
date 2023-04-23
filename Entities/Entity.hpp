//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLGAME_ENTITY_HPP
#define SFMLGAME_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "../Components/MovementComponent.hpp"
#include "../Game.hpp"

namespace SFMLGame {
    class Entity {
    public:
        Entity(GameDataRef dataRef, const float &maxVel, const float &acc, const float &dec, std::string spriteName);

        virtual ~Entity() = default;

        virtual void setPosition(const float &x, const float &y);

        virtual void setSprite(const std::string &name);

        virtual void move(float dir_x, float dir_y, const float &dt);

        virtual void update(const float& dt);

        virtual void render();

    protected:
        GameDataRef data;
        sf::Texture texture;
        sf::Sprite sprite;
        std::string spriteName;
        sf::Vector2f positionVector;
        MovementComponent movementComponent;
        float maxVelocity;
    };

}

#endif //SFMLGAME_ENTITY_HPP
