//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLTEST_GAMEENTITY_H
#define SFMLTEST_GAMEENTITY_H
#include <SFML/Graphics.hpp>

class GameEntity {
public:
    GameEntity(const std::string& texturePath, sf::Vector2i spriteResolution);
protected:
    sf::Vector2f positionVector;
    sf::Texture texture;
    sf::Sprite sprite;
    bool setUpSprite(const std::string& texturePath, sf::Vector2i spriteResolution);
};


#endif //SFMLTEST_GAMEENTITY_H
