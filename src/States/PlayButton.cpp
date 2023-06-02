#include "PlayButton.h"

namespace game {
    PlayButton::PlayButton(float x, float y, float width, float height,
                           const std::string &text, const std::string &font) : Button(x, y, width, height, text,
                                                                                      font) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        this->font = mgr::assets.getFont(font);
        this->text.setFont(this->font);
        this->text.setString(text);
        this->text.setFillColor(sf::Color::White);
        this->text.setCharacterSize(25);
        this->text.setPosition(shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) -
                               this->text.getGlobalBounds().width / 2.f,
                               shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) -
                               this->text.getGlobalBounds().height);

        idleColor = sf::Color(70, 70, 70, 200);
        hoverColor = sf::Color(150, 150, 150, 255);
        clickColor = sf::Color(20, 20, 20, 200);

        shape.setFillColor(idleColor);
    }

    void PlayButton::update() {
        buttonState = BTN_IDLE;
        if (InputManager::isShapeHovered(shape, mgr::window)) {
            buttonState = BTN_HOVER;
        }
        if (InputManager::isShapeClicked(shape, sf::Mouse::Button::Left, mgr::window)) {
            buttonState = BTN_PRESSED;
        }

        switch (buttonState) {
            case BTN_IDLE:
                shape.setFillColor(idleColor);
                break;
            case BTN_HOVER:
                shape.setFillColor(hoverColor);
                break;
            case BTN_PRESSED:
                shape.setFillColor(clickColor);
                break;
        }
    }

}
