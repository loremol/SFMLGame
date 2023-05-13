#include "Entity.h"
#include "../mgr.h"

namespace game {
    Entity::Entity(unsigned int entityId) : id(entityId), movement(this) {
        switch (entityId) {
            case player:
                sprite.setTexture(mgr::assets.GetTexture(entityTextures::playerIdle[0]));
                sprite.scale(4.f, 4.f);
                numberOfIdleFrames = 2;
                numberOfMovingFrames = 5;
                movement.setMaxVelocity(110.f);
                movement.setAcceleration(12.f);
                movement.setDeceleration(4.f);
                break;
        }

    }

    void Entity::update(const float &dt) {
        movement.update(dt);
    }

    void Entity::render() {
        mgr::window.draw(sprite);
    }

    void Entity::move(const float dir_x, const float dir_y) {
        movement.move(dir_x, dir_y); // sets velocity
    }

    void Entity::flipSpriteLeft() {
        if (direction_r) {
            sprite.setTextureRect(sf::IntRect(static_cast<int>(sprite.getLocalBounds().width), 0,
                                              static_cast<int>(-sprite.getLocalBounds().width),
                                              static_cast<int>(sprite.getLocalBounds().height)));

            direction_r = false;
            direction_l = true;
        }
    }

    void Entity::flipSpriteRight() {
        if (direction_l) {
            sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(sprite.getLocalBounds().width),
                                              static_cast<int>(sprite.getLocalBounds().height)));

            direction_r = true;
            direction_l = false;
        }
    }


    Entity::MovementComponent::MovementComponent(Entity *const entity) : entityPtr(entity) {
        switch (entityPtr->id) {
            case 1:
                maxVelocity = 250.f;
                acceleration = 15.f;
                deceleration = 7.5f;
                break;
        }
    }

    void Entity::MovementComponent::update(const float &dt) {
        // Deceleration
        if (velocity.x > 0.f) {
            // Checking if going over maxVelocity
            if (velocity.x > maxVelocity) {
                velocity.x = maxVelocity;
            }

            velocity.x -= deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.x < 0.f) {
                velocity.x = 0.f;
            }
        } else if (velocity.x < 0.f) {
            // Checking if going over maxVelocity
            if (velocity.x < -maxVelocity)
                velocity.x = -maxVelocity;

            velocity.x += deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.x > 0.f) {
                velocity.x = 0.f;
            }
        }

        if (velocity.y > 0.f) {
            // Checking if going over maxVelocity
            if (velocity.y > maxVelocity) {
                velocity.y = maxVelocity;
            }

            velocity.y -= deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.y < 0.f) {
                velocity.y = 0.f;
            }
        } else if (velocity.y < 0.f) {
            // Checking if going over maxVelocity
            if (velocity.y < -maxVelocity)
                velocity.y = -maxVelocity;

            velocity.y += deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.y > 0.f) {
                velocity.y = 0.f;
            }
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
            (std::abs(velocity.x) > maxVelocity * 0.1 || std::abs(velocity.y) > maxVelocity * 0.1 ||
             entityPtr->currentMovingFrame != 0))
            entityPtr->isMoving = true;
        else if (velocity.x == 0 && velocity.y == 0)
            entityPtr->isMoving = false;

        if (clock.getElapsedTime().asSeconds() >= 0.2) {
            // Moving animation
            if (entityPtr->isMoving) {
                entityPtr->sprite.setTexture(
                        mgr::assets.GetTexture(entityTextures::playerMoving[entityPtr->currentMovingFrame]));
                entityPtr->currentMovingFrame++;
                if (entityPtr->currentMovingFrame == entityPtr->numberOfMovingFrames)
                    entityPtr->currentMovingFrame = 0;

                entityPtr->currentIdleFrame = 0;
                clock.restart();
            }
            // Idle animation
            if (!entityPtr->isMoving && clock.getElapsedTime().asSeconds() >= 0.3) {
                entityPtr->sprite.setTexture(
                        mgr::assets.GetTexture(entityTextures::playerIdle[entityPtr->currentIdleFrame]));
                entityPtr->currentIdleFrame++;
                if (entityPtr->currentIdleFrame == entityPtr->numberOfIdleFrames)
                    entityPtr->currentIdleFrame = 0;

                entityPtr->currentMovingFrame = 0;
                clock.restart();
            }
        }

        // Update positionVector
        entityPtr->positionVector.x += velocity.x * dt;
        entityPtr->positionVector.y += velocity.y * dt;

        entityPtr->sprite.move(velocity * dt); // uses velocity
    }

    void Entity::MovementComponent::move(const float &dir_x, const float &dir_y) {
        // Acceleration
        velocity.x += acceleration * dir_x;
        velocity.y += acceleration * dir_y;
    }
}

