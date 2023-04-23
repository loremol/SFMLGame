//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_GAMESTATE_HPP
#define SFMLGAME_GAMESTATE_HPP

#include "State.hpp"
#include <utility>
#include "../Game.hpp"
#include "../Entities/Player.hpp"
#include "../Definitions.hpp"
#include "../Map/World.hpp"

namespace SFMLGame {
    class GameState : public State {
    public:
        explicit GameState(const GameDataRef &data) : data(data), player(data), world(sf::Vector2i(64, 64),
                                                                                      sf::Vector2i(SCREEN_WIDTH,
                                                                                                   SCREEN_HEIGHT)) {};

        void Init() override;

        void HandleInput() override;

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
