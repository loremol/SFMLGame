//
// Created by Lorenzo on 23/04/2023.
//

#include "Button.hpp"
#include "GameState.hpp"

#include <utility>

namespace SFMLGame {
    Button::Button(GameDataRef dataRef, float x, float y, float width, float height, const std::string &text,
                   const std::string &font) : data(std::move(dataRef)), buttonState(BTN_IDLE) {
        this->shape.setPosition(sf::Vector2f(x, y));
        this->shape.setSize(sf::Vector2f(width, height));

        this->font = this->data->assets.GetFont(font);

        this->text.setFont(this->font);
        this->text.setString(text);
        this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) -
                               this->text.getGlobalBounds().width / 2.f,
                               this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) -
                               this->text.getGlobalBounds().height);
    }

    bool Button::isPressed() {
        if (this->buttonState == BTN_PRESSED) {
            this->buttonState = BTN_IDLE;
            return true;
        }
        return false;
    }
}