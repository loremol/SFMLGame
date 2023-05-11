#include "InputManager.h"

namespace game {
    bool InputManager::isSpriteClicked(const sf::Sprite &sprite, sf::Mouse::Button button,
                                       const sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            if (sprite.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                  static_cast<float>(sf::Mouse::getPosition().y))) {
                return true;
            }
            return false;
        }
        return false;
    }

    bool InputManager::isShapeClicked(const sf::Shape &shape, sf::Mouse::Button button,
                                      const sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            if (shape.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                 static_cast<float>(sf::Mouse::getPosition(window).y))) {
                return true;
            }
            return false;
        }
        return false;
    }

    bool InputManager::isShapeHovered(const sf::Shape &shape,
                                      const sf::RenderWindow &window) {
        if (shape.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                             static_cast<float>(sf::Mouse::getPosition(window).y))) {
            return true;
        }
        return false;
    }
}