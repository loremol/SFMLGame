//
// Created by Lorenzo on 21/04/2023.
//

#include "GameState.hpp"

namespace SFMLGame {
    GameState::GameState(const GameDataRef &dataRef) : data(dataRef), player(dataRef),
                                                       world(dataRef, sf::Vector2f(64.f, 64.f)) {

    }

    void GameState::Init() {

    }

    void GameState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->data->window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                this->data->window.close();
        }
    }

    void GameState::Update(float dt) {
        player.update(dt);
    }

    void GameState::Draw(float dt) {
        this->data->window.clear();

        for (int i = 0; i < this->world.gridLength; i++) {
            for (int j = 0; j < this->world.gridLength; j++) {
                this->data->window.draw(this->world.tiles[i][j]->sprite);
            }
        }
        this->player.draw();
        this->data->window.display();
    }
}
