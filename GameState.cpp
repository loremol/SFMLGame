//
// Created by Lorenzo on 21/04/2023.
//

#include "GameState.hpp"

namespace SFMLGame {
    void SFMLGame::GameState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->data->window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                printf("%d\n%d\n", sf::Mouse::getPosition(this->data->window).x, sf::Mouse::getPosition(this->data->window).y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                player.setPressedKey(sf::Keyboard::D);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                player.setPressedKey(sf::Keyboard::A);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                player.setPressedKey(sf::Keyboard::S);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                player.setPressedKey(sf::Keyboard::W);
        }
    }

    void GameState::Update(float dt) {
        player.checkPressedKeys();
        player.resetPressedKeys();
    }

    void GameState::Draw(float dt) {
        this->data->window.clear();

        for (int i = 0; i < world.getGridLength(); i++) {
            for (int j = 0; j < world.getGridLength(); j++) {
                this->data->window.draw(world.tiles[i][j]->sprite);
            }
        }
        this->data->window.draw(player.getSprite());
        this->data->window.display();
    }

}