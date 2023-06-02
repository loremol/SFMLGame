#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "State.h"
#include <utility>
#include "../Init.h"
#include "../Definitions.h"
#include "../Map/Map.h"

namespace game {
    class GameState : public State {
    public:
        GameState();

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        sf::Clock clock;
        std::shared_ptr<Map> mapSharedPtr;

        void drawMap();

        void renderEntities() const;
    };
}

#endif //GAME_GAMESTATE_HPP
