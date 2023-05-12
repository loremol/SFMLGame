//
// Created by Lorenzo on 19/04/2023.
//

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"
#include "../Definitions.h"

namespace game {

    class Entity {
    public:
        explicit Entity(unsigned int entityId);

        virtual ~Entity() = default;

        virtual void move(float dir_x, float dir_y);

        virtual void update(const float &dt);

        virtual void render();

        sf::Vector2f positionVector;

    protected:
        unsigned int id;
        sf::Sprite sprite;

        class MovementComponent {
        public:
            explicit MovementComponent(Entity *entity);

            ~MovementComponent() = default;

            void move(const float &dir_x, const float &dir_y);

            void update(const float &dt);

        private:
            float maxVelocity;
            float acceleration;
            float deceleration;
            sf::Vector2f velocity;
            Entity *const entityPtr;
        };

        MovementComponent movement;
    private:
        enum entityIds : unsigned int {
            player = 1
        };
    };
}

#endif //GAME_ENTITY_HPP
