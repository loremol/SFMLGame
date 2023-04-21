//
// Created by Lorenzo on 19/04/2023.
//
#include "GameEntity.hpp"

GameEntity::GameEntity(const std::string& texturePath, const sf::Vector2i spriteResolution) {
    setUpSprite(texturePath, spriteResolution);
}

bool GameEntity::setUpSprite(const std::string& texturePath, const sf::Vector2i spriteResolution) {
    if (!texture.loadFromFile(texturePath)) {
        printf("Error in loading texture.\n");
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,spriteResolution.x,spriteResolution.y));
    return true;
}