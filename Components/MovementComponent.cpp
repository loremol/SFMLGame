//
// Created by Lorenzo on 23/04/2023.
//

#include "MovementComponent.hpp"

namespace SFMLGame {
    SFMLGame::MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acc, float dec) : maxVelocity(maxVelocity), sprite(sprite),acceleration(acc),deceleration(dec) {

    }
    void SFMLGame::MovementComponent::update(const float &dt) {
        // Deceleration
        if(this->velocity.x > 0.f) {
            // Checking if going over maxVelocity
            if(this->velocity.x > this->maxVelocity) {
                this->velocity.x = this->maxVelocity;
            }

            this->velocity.x -= deceleration;
            // Stopping the friction before it becomes acceleration
            if(this->velocity.x < 0.f) {
                this->velocity.x = 0.f;
            }
        } else if (this->velocity.x < 0.f) {
            // Checking if going over maxVelocity
            if(this->velocity.x < -this->maxVelocity)
                this->velocity.x = -this->maxVelocity;

            this->velocity.x += deceleration;
            // Stopping the friction before it becomes acceleration
            if(this->velocity.x > 0.f) {
                this->velocity.x = 0.f;
            }
        }

        if(this->velocity.y > 0.f) {
            // Checking if going over maxVelocity
            if(this->velocity.y > this->maxVelocity) {
                this->velocity.y = this->maxVelocity;
            }

            this->velocity.y -= deceleration;
            // Stopping the friction before it becomes acceleration
            if(this->velocity.y < 0.f) {
                this->velocity.y = 0.f;
            }
        } else if (this->velocity.y < 0.f) {
            // Checking if going over maxVelocity
            if(this->velocity.y < -this->maxVelocity)
                this->velocity.y = -this->maxVelocity;

            this->velocity.y += deceleration;
            // Stopping the friction before it becomes acceleration
            if(this->velocity.y > 0.f) {
                this->velocity.y = 0.f;
            }
        }

        // Final move
        this->sprite.move(this->velocity * dt); // uses velocity
    }

    sf::Vector2f &MovementComponent::getVelocity() {
        return this->velocity;
    }

    void MovementComponent::move(const float& dir_x, const float& dir_y, const float &dt) {
        // Acceleration
        this->velocity.x += this->acceleration * dir_x;
        this->velocity.y += this->acceleration * dir_y;
    }
}