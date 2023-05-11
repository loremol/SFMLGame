#include "Entity.h"
#include "../mgr.h"

namespace game {
    Entity::Entity(const float &maxVel, const float &acc, const float &dec, const std::string &sprite) : spriteName(
            sprite),
                                                                                                         movementComponent(
                                                                                                                 sprite,
                                                                                                                 maxVel,
                                                                                                                 acc,
                                                                                                                 dec) {
    }

    void Entity::update(const float &dt) {
        movementComponent.update(dt, positionVector);
    }

    void Entity::render() {
        mgr::window.draw(movementComponent.sprite);
    }

    void Entity::move(const float dir_x, const float dir_y) {
        movementComponent.move(dir_x, dir_y); // sets velocity
    }
}

