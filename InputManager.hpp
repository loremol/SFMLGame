//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_INPUTMANAGER_HPP
#define SFMLGAME_INPUTMANAGER_HPP
#include <SFML/Graphics.hpp>

namespace SFMLGame {
    class InputManager {
    public:
        InputManager() = default;
        ~InputManager() = default;

        bool IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, const sf::RenderWindow& window);
    };
}

#endif //SFMLGAME_INPUTMANAGER_HPP
