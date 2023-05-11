//
// Created by Lorenzo on 23/04/2023.
//

#ifndef GAME_MOVEMENTCOMPONENT_HPP
#define GAME_MOVEMENTCOMPONENT_HPP

#include <SFML/Graphics.hpp>

namespace game {
    class MovementComponent {
    public:
        MovementComponent(const std::string &sprite, const float &maxVelocity, const float &acceleration,
                          const float &deceleration);

        ~MovementComponent() = default;

        void move(const float &dir_x, const float &dir_y);

        void update(const float &dt, sf::Vector2f &entityPosVector);

        sf::Sprite sprite; // for working with the entity's sprite

    private:
        float maxVelocity;
        float acceleration;
        float deceleration;
        sf::Vector2f velocity;
    };
}


#endif //GAME_MOVEMENTCOMPONENT_HPP
