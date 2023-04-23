//
// Created by Lorenzo on 21/04/2023.
//

#include "GameState.hpp"

namespace SFMLGame {
    void GameState::Init() {
    }

    void GameState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->data->window.close();
        }
    }

    void GameState::Update(float dt) {
        player.update(dt);
    }

    void GameState::Draw(float dt) {
        this->data->window.clear();

        for (int i = 0; i < world.getGridLength(); i++) {
            for (int j = 0; j < world.getGridLength(); j++) {
                this->data->window.draw(world.tiles[i][j]->sprite);
            }
        }
        this->player.draw();
        this->data->window.display();
    }
}
