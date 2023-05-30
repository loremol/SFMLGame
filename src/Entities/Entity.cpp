#include "Entity.h"
#include "../mgr.h"

namespace game {
    Entity::Entity(unsigned int entityId) : id(entityId), movement(*this), animation(*this) {
        switch (entityId) {
            case player:
                sprite.setTexture(mgr::assets.GetTexture(entityTextures::playerIdle[0]));
                sprite.scale(4.f, 4.f);
                numberOfIdleFrames = 2;
                numberOfMovingFrames = 6;
                movement.setMaxVelocity(110.f);
                movement.setAcceleration(12.f);
                movement.setDeceleration(4.f);
                break;
        }

    }

    void Entity::update(const float &dt) {
        movement.update(dt);
        animation.updateSprite();
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


    Entity::MovementComponent::MovementComponent(Entity &entity) : entity(entity) {
        switch (entity.id) {
            case 1:
                maxVelocity = 250.f;
                acceleration = 15.f;
                deceleration = 7.5f;
                break;
        }
    }

    void Entity::MovementComponent::update(const float &dt) {
        decelerate();
        // update positionVector
        entity.positionVector.x += velocity.x * dt;
        entity.positionVector.y += velocity.y * dt;

        // update sprite's position
        entity.sprite.move(velocity * dt);
    }

    void Entity::MovementComponent::decelerate() {// Deceleration
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
    }

    void Entity::MovementComponent::move(const float &dir_x, const float &dir_y) {
        // Acceleration
        velocity.x += acceleration * dir_x;
        velocity.y += acceleration * dir_y;
    }

    void Entity::AnimationComponent::updateSprite() {
        entity.isMoving = checkIfMoving();

        if (clock.getElapsedTime().asSeconds() >= 0.2) {
            // Moving animation
            if (entity.isMoving || entity.currentMovingFrame != 0) {
                entity.sprite.setTexture(
                        mgr::assets.GetTexture(entityTextures::playerMoving[entity.currentMovingFrame]));
                entity.currentMovingFrame = (entity.currentMovingFrame + 1) % entity.numberOfMovingFrames;

                entity.currentIdleFrame = 0;
                clock.restart();
            }
                // Idle animation
            else if (!entity.isMoving) {
                entity.sprite.setTexture(
                        mgr::assets.GetTexture(entityTextures::playerIdle[entity.currentIdleFrame]));
                entity.currentIdleFrame = (entity.currentIdleFrame + 1) % entity.numberOfIdleFrames;

                entity.currentMovingFrame = 0;
                clock.restart();
            }
        }
    }

    bool Entity::AnimationComponent::checkIfMoving() const {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ||
            (entity.movement.velocity.x != 0))
            return true;
        else if (entity.movement.velocity.x == 0 && entity.movement.velocity.y == 0)
            return false;
        return false;
    }
}

