#include "Button.h"

namespace game {
    Button::Button(float x, float y, float width, float height, const std::string &text,
                   const std::string &font) : buttonState(BTN_IDLE) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));

        this->font = mgr::assets.getFont(font);

        this->text.setFont(this->font);
        this->text.setString(text);
        this->text.setPosition(shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) -
                               this->text.getGlobalBounds().width / 2.f,
                               shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) -
                               this->text.getGlobalBounds().height);
    }

    bool Button::isPressed() {
        if (buttonState == BTN_PRESSED) {
            buttonState = BTN_IDLE;
            return true;
        }
        return false;
    }
}