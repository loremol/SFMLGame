#include "Entity.h"
#include "../mgr.h"

namespace game {
    Entity::Entity(unsigned int entityId) : id(entityId), movement(this) {
        switch (entityId) {
            case player:
                sprite.setTexture(mgr::assets.GetTexture("Player"));
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

        // Final move
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

