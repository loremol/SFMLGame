//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLGAME_PLAYER_H
#define SFMLGAME_PLAYER_H
#include <SFML/Graphics.hpp>
#include "GameEntity.h"

struct keys {
    bool up     = false;
    bool down   = false;
    bool left   = false;
    bool right  = false;
};

class Player : public GameEntity {
public:
    Player(const std::string &texturePath, sf::Vector2i spriteResolution) : GameEntity(texturePath, spriteResolution) {
        positionVector.x = 0;
        positionVector.y = 0;
    };

    sf::Sprite getSprite() {
        return sprite;
    }

    void move(float,float);

    void checkPressedKeys();
    void setPressedKey(sf::Keyboard::Key Key);
    void resetPressedKeys();

private:
    keys    pressedKeys;
};


#endif //SFMLGAME_PLAYER_H
