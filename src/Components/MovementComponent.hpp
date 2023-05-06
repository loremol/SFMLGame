//
// Created by Lorenzo on 23/04/2023.
//

#ifndef SFMLGAME_MOVEMENTCOMPONENT_HPP
#define SFMLGAME_MOVEMENTCOMPONENT_HPP

#include <SFML/Graphics.hpp>

namespace SFMLGame {
    class MovementComponent {
    public:
        MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);

        ~MovementComponent() = default;

        void move(const float& dir_x, const float& dir_y, const float& dt);

        void update(const float &dt);

        sf::Vector2f &getVelocity();

    private:
        sf::Sprite& sprite; // for working with the entity's sprite
        float maxVelocity;
        float acceleration;
        float deceleration;
        sf::Vector2f velocity;
    };
}


#endif //SFMLGAME_MOVEMENTCOMPONENT_HPP
