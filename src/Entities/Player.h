#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"
#include "Entity.h"
#include "../Definitions.h"

namespace game {
    class Player : public Entity {
    public:
        Player(float x, float y);
    };
}

#endif //GAME_PLAYER_HPP
