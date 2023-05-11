//
// Created by Lorenzo on 23/04/2023.
//

#include "MovementComponent.h"
#include "../mgr.h"


namespace game {
    MovementComponent::MovementComponent(const std::string &sprite, const float &maxVelocity, const float &acc,
                                         const float &dec) : maxVelocity(maxVelocity), acceleration(acc),
                                                             deceleration(dec) {
        this->sprite.setTexture(mgr::assets.GetTexture(sprite));
    }

    void MovementComponent::update(const float &dt, sf::Vector2f &entityPosVector) {
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
        entityPosVector.x += velocity.x * dt;
        entityPosVector.y += velocity.y * dt;
        sprite.move(velocity * dt); // uses velocity
    }

    void MovementComponent::move(const float &dir_x, const float &dir_y) {
        // Acceleration
        velocity.x += acceleration * dir_x;
        velocity.y += acceleration * dir_y;
    }
}