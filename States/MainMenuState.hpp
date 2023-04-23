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

namespace SFMLGame {
    class MainMenuState : public State {
    public:
        explicit MainMenuState(GameDataRef data);

        void Init() override {};
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;

    private:
        GameDataRef data;
        FilePaths filePaths;
        // For now using tint color
        // sf::Sprite backgroundSprite;
        sf::Sprite playButtonSprite;
        sf::Text playButtonText;
        sf::Text title;
        sf::Font titleFont;
    };
}


#endif //SFMLGAME_MAINMENUSTATE_HPP
