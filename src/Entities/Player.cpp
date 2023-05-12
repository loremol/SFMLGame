#include "Player.h"

namespace game {
    Player::Player(float x, float y) : Entity(1) {
        sprite.setPosition(x, y);
        positionVector.x = x;
        positionVector.y = y;
    }
}
