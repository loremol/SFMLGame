//
// Created by Lorenzo on 23/04/2023.
//

#include "ExitButton.h"

#include <utility>

namespace SFMLGame {
    ExitButton::ExitButton(GameDataRef dataRef, float x, float y, float width, float height,
                           const std::string &text, const std::string &font) : Button(std::move(dataRef), x,
                                                                                      y, width, height, text,
                                                                                      font) {
        this->shape.setPosition(sf::Vector2f(x, y));
        this->shape.setSize(sf::Vector2f(width, height));
        this->font = this->data->assets.GetFont(font);
        this->text.setFont(this->font);
        this->text.setString(text);
        this->text.setFillColor(sf::Color::White);
        this->text.setCharacterSize(25);
        this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) -
                               this->text.getGlobalBounds().width / 2.f,
                               this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) -
                               this->text.getGlobalBounds().height);

        this->idleColor = sf::Color(70, 70, 70, 200);
        this->hoverColor = sf::Color(150, 150, 150, 255);
        this->clickColor = sf::Color(20, 20, 20, 200);

        this->shape.setFillColor(this->idleColor);
    }

    void ExitButton::update() {
        this->buttonState = BTN_IDLE;
        if (this->data->input.isShapeHovered(this->shape, this->data->window)) {
            this->buttonState = BTN_HOVER;
        }
        if (this->data->input.isShapeClicked(this->shape, sf::Mouse::Button::Left, this->data->window)) {
            this->buttonState = BTN_PRESSED;
        }

        switch (this->buttonState) {
            case BTN_IDLE:
                this->shape.setFillColor(this->idleColor);
                break;
            case BTN_HOVER:
                this->shape.setFillColor(this->hoverColor);
                break;
            case BTN_PRESSED:
                this->shape.setFillColor(this->clickColor);
                break;
        }
    }

    bool ExitButton::isPressed() {
        return Button::isPressed();
    }
}
