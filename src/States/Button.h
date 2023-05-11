#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "../mgr.h"


namespace game {
    enum buttonStates {
        BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED
    };

    class Button {
    public:
        Button(float x, float y, float width, float height, const std::string &text,
               const std::string &font);

        virtual ~Button() = default;

        virtual void update() = 0;

        virtual void render() {
            mgr::window.draw(shape);
            mgr::window.draw(text);
        };

        virtual bool isPressed();

    protected:
        sf::RectangleShape shape;
        sf::Font font;
        sf::Text text;
        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color clickColor;
        short unsigned buttonState;
    };

}

#endif //GAME_BUTTON_HPP
