//
// Created by Lorenzo on 23/04/2023.
//

#ifndef SFMLGAME_PLAYBUTTON_HPP
#define SFMLGAME_PLAYBUTTON_HPP

#include "Button.hpp"

namespace SFMLGame {
    class PlayButton : Button {
    public:
        PlayButton(GameDataRef dataRef, float x, float y, float width, float height, const std::string &text,
                   const std::string &font);

        ~PlayButton() override = default;

        bool isPressed();

        void update() override;

        void render() override;
    };
}

#endif //SFMLGAME_PLAYBUTTON_HPP
