#ifndef GAME_INPUTMANAGER_HPP
#define GAME_INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace game {
    class InputManager {
    public:
        InputManager() = default;

        ~InputManager() = default;

        bool isSpriteClicked(const sf::Sprite &object, sf::Mouse::Button button, const sf::RenderWindow &window);

        bool isShapeClicked(const sf::Shape &object, sf::Mouse::Button button, const sf::RenderWindow &window);

        bool isShapeHovered(const sf::Shape &shape, const sf::RenderWindow &window);
    };
}

#endif //GAME_INPUTMANAGER_HPP
