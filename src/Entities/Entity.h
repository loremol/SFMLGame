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

        virtual void flipSpriteLeft();

        virtual void flipSpriteRight();

        virtual void update(const float &dt);

        virtual void render();

        sf::Vector2f positionVector;

    protected:
        unsigned int id;
        unsigned short int numberOfIdleFrames;
        unsigned short int numberOfMovingFrames;
        unsigned short int currentIdleFrame = 0;
        unsigned short int currentMovingFrame = 0;
        bool direction_r = true;
        bool direction_l = false;
        bool isMoving = false;
        sf::Sprite sprite;

        class MovementComponent {
        public:
            explicit MovementComponent(Entity *entity);

            ~MovementComponent() = default;

            void move(const float &dir_x, const float &dir_y);

            void update(const float &dt);

            void setMaxVelocity(float x) { maxVelocity = x; }

            void setAcceleration(float x) { acceleration = x; }

            void setDeceleration(float x) { deceleration = x; }

        private:
            float maxVelocity;
            float acceleration;
            float deceleration;
            sf::Vector2f velocity;
            Entity *const entityPtr;
            sf::Clock clock;
        };

        MovementComponent movement;
    private:
        enum entityIds : unsigned int {
            player = 1
        };
        struct entityTextures {
            inline static std::string playerIdle[4] = {"PlayerIdle0", "PlayerIdle1", "PlayerIdle2", "PlayerIdle3"};
            inline static std::string playerMoving[5] = {"PlayerMoving0", "PlayerMoving1", "PlayerMoving2",
                                                         "PlayerMoving3", "PlayerMoving4"};
        };
    };
}

#endif //GAME_ENTITY_HPP
