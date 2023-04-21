//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_GAMESTATE_HPP
#define SFMLGAME_GAMESTATE_HPP
#include "State.hpp"
#include <utility>
#include "Game.hpp"
#include "Player.hpp"
#include "Definitions.hpp"
#include "World.hpp"

namespace SFMLGame {
    class GameState : public State {
    public:
        explicit GameState(GameDataRef data) :  data(std::move(data)), player(filePaths.PlayerSpritePath.make_preferred().string(), sf::Vector2i(64,64)),
                                                world(sf::Vector2i(64,64), sf::Vector2i(SCREEN_WIDTH,SCREEN_HEIGHT)){};

        void Init() override {};
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
