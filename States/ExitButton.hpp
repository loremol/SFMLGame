//
// Created by Lorenzo on 23/04/2023.
//

#ifndef SFMLGAME_EXITBUTTON_HPP
#define SFMLGAME_EXITBUTTON_HPP
#include "Button.hpp"

namespace SFMLGame {
    class ExitButton : public Button{
    public:
        ExitButton(GameDataRef dataRef, float x, float y, float width, float height, const std::string &text,
        const std::string &font);

        ~ExitButton() override = default;

        bool isPressed() override;

        void update() override;

    };
}


#endif //SFMLGAME_EXITBUTTON_HPP
