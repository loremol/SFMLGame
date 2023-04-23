//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_MAINMENUSTATE_HPP
#define SFMLGAME_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include "State.hpp"
#include "../Game.hpp"
#include "../Definitions.hpp"
#include "Button.hpp"
#include "PlayButton.hpp"
#include "ExitButton.hpp"

namespace SFMLGame {
    class MainMenuState : public State {
    public:
        explicit MainMenuState(GameDataRef data);

        ~MainMenuState() override = default;

        void Init() override {};

        void HandleInput() override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        GameDataRef data;
        FilePaths filePaths;
        sf::Text title;
        sf::Font titleFont;
        PlayButton playButton;
        ExitButton exitButton;
    };
}


#endif //SFMLGAME_MAINMENUSTATE_HPP
