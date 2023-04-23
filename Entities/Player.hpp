//
// Created by Lorenzo on 19/04/2023.
//

#ifndef SFMLGAME_PLAYER_HPP
#define SFMLGAME_PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include "../Entities/Entity.hpp"
#include "../Definitions.hpp"

namespace SFMLGame {
    class Player : public Entity {
    public:
        explicit Player(const GameDataRef& data);

        void move(float x_dir,float y_dir, float dt);
        void update(float dt);
        void draw();

    private:
        GameDataRef data;
        std::filesystem::path texturePath;
        float velocity;
    };

}

#endif //SFMLGAME_PLAYER_HPP
