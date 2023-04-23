//
// Created by Lorenzo on 23/04/2023.
//

#ifndef SFMLGAME_BUTTON_HPP
#define SFMLGAME_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "../Game.hpp"

namespace SFMLGame {
    enum buttonStates {
        BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED
    };

    class Button {
    public:
        Button(GameDataRef dataRef, float x, float y, float width, float height, const std::string &text,
               const std::string &font);

        virtual ~Button() = default;

        virtual void update() = 0;

        virtual void render() = 0;

        virtual bool isPressed();

    protected:
        GameDataRef data;
        sf::RectangleShape shape;
        sf::Font font;
        sf::Text text;
        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color clickColor;
        short unsigned buttonState;
    };

}

#endif //SFMLGAME_BUTTON_HPP
