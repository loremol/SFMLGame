//
// Created by Lorenzo on 23/04/2023.
//

#ifndef SFMLGAME_PLAYBUTTON_HPP
#define SFMLGAME_PLAYBUTTON_HPP

#include "Button.h"

namespace SFMLGame {
    class PlayButton : public Button {
    public:
        PlayButton(GameDataRef dataRef, float x, float y, float width, float height, const std::string &text,
                   const std::string &font);

        ~PlayButton() override = default;

        void update() override;
    };
}

#endif //SFMLGAME_PLAYBUTTON_HPP
