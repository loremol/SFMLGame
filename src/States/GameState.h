#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "State.h"
#include <utility>
#include "../Init.h"
#include "../Entities/Player.h"
#include "../Definitions.h"
#include "../Map/Map.h"

namespace game {
    class GameState : public State {
    public:
        explicit GameState();

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        sf::Clock clock;
        Map map;
        Player player;
    };
}

#endif //GAME_GAMESTATE_HPP
