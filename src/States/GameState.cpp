#include <iostream>
#include "GameState.h"
#include "../mgr.h"


namespace game {
    GameState::GameState() : player(64.f * 8.f, 64.f * 8.f), world(sf::Vector2f(64.f, 64.f)) {

    }

    void GameState::HandleInput(const float &dt) {
        sf::Event event{};
        while (mgr::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                mgr::window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player.move(0.f, -1.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-1.f, 0.f);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                player.flipSpriteLeft();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player.move(0.f, 1.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(1.f, 0.f);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                player.flipSpriteRight();
        }
    }

    void GameState::Update(float dt) {
        player.update(dt);
    }

    void GameState::Draw(float dt) {
        mgr::window.clear();
        std::cout << player.positionVector.x << " " << player.positionVector.y << std::endl;

        for (int i = 0; i < world.gridLength; i++) {
            for (int j = 0; j < world.gridLength; j++) {
                mgr::window.draw(world.tiles[i][j]->sprite);
            }
        }
        player.render();
        mgr::window.display();
    }
}
