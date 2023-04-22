//
// Created by Lorenzo on 21/04/2023.
//

#include "InputManager.hpp"

namespace SFMLGame {
    bool SFMLGame::InputManager::IsSpriteClicked(const sf::Sprite& sprite, sf::Mouse::Button button, const sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(button)) { // has the mouse been clicked?
            /// temporary rect checking if it contains the mouse
            sf::IntRect tempRect(static_cast<int>(sprite.getPosition().x), static_cast<int>(sprite.getPosition().y), static_cast<int>(sprite.getGlobalBounds().width), static_cast<int>(sprite.getGlobalBounds().height));

            if (tempRect.contains(sf::Mouse::getPosition(window)))
                return true;
            else {
                return false;
            }
        }
        return false;
    }
}