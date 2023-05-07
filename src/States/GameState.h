//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_GAMESTATE_HPP
#define SFMLGAME_GAMESTATE_HPP

#include "State.h"
#include <utility>
#include "../Game.h"
#include "../Entities/Player.h"
#include "../Definitions.h"
#include "../Map/World.h"

namespace SFMLGame {
    class GameState : public State {
    public:
        explicit GameState(const GameDataRef &dataRef);

        void Init() override;

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        GameDataRef data;
        sf::Clock clock;
        FilePaths filePaths;
        World world;
        Player player;
    };
}

#endif //SFMLGAME_GAMESTATE_HPP
