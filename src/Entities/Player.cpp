#include "Player.h"

namespace game {
    // 150, 15, 10
    Player::Player(float x, float y) : Entity(1) {
        positionVector.x = x;
        positionVector.y = y;
    }
}
