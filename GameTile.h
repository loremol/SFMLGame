//
// Created by Lorenzo on 18/04/2023.
//

#include <SFML/Graphics.hpp>

#ifndef SFMLTEST_GAMETILE_H
#define SFMLTEST_GAMETILE_H

class GameTile {
public:
    GameTile(const std::string& texturePath, sf::Vector2i positionVector, sf::Vector2i spriteResolution)
    : pos(positionVector)
    {
        if (!setUpSprite(texturePath,spriteResolution)) {
            printf("Error in setting up sprite.\n");
            return;
        }
        sprite.setPosition(pos);
    };
    bool setUpSprite(const std::string&,sf::Vector2i);

public:
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //SFMLTEST_GAMETILE_H
