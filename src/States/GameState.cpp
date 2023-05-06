//
// Created by Lorenzo on 21/04/2023.
//

#include "GameState.hpp"

namespace SFMLGame {
    GameState::GameState(const GameDataRef &dataRef) : data(dataRef), player(dataRef, 64.f*8.f, 64.f*8.f),
                                                       world(dataRef, sf::Vector2f(64.f, 64.f)) {

    }

    void GameState::Init() {

    }

    void GameState::HandleInput(const float& dt) {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->data->window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                this->data->window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->player.move(0.f, -1.f, dt); // accelerate up

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->player.move(-1.f, 0.f, dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->player.move(0.f, 1.f, dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->player.move(1.f, 0.f, dt);
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
        this->player.render();
        this->data->window.display();
    }
}
