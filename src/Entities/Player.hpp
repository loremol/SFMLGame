//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLGAME_PLAYER_HPP
#define SFMLGAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include "Entity.hpp"
#include "../Definitions.hpp"

namespace SFMLGame {
    class Player : public Entity {
    public:
        Player(GameDataRef data, float x, float y);

    private:
        std::filesystem::path texturePath;
        sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
        float acceleration = 5.f;
        float deceleration = 3.f;
    };

}

#endif //SFMLGAME_PLAYER_HPP
