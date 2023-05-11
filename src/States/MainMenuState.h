#ifndef GAME_MAINMENUSTATE_HPP
#define GAME_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include "State.h"
#include "../Init.h"
#include "../Definitions.h"
#include "Button.h"
#include "PlayButton.h"
#include "ExitButton.h"

namespace game {
    class MainMenuState : public State {
    public:
        MainMenuState();

        ~MainMenuState() override = default;

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        sf::Text title;
        sf::Font titleFont;
        PlayButton playButton;
        ExitButton exitButton;
    };
}


#endif //GAME_MAINMENUSTATE_HPP
