//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_SPLASHSTATE_HPP
#define SFMLGAME_SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.h"
#include "../Game.h"
#include "../Definitions.h"

namespace SFMLGame {
    class SplashState : public SFMLGame::State {
    public:
        explicit SplashState(GameDataRef data);

        void Init() override;

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        SFMLGame::GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
        FilePaths filePaths;
    };
}


#endif //SFMLGAME_SPLASHSTATE_HPP
