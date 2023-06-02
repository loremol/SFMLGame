#include "GameState.h"

#include <memory>
#include "../mgr.h"


namespace game {
    GameState::GameState() : mapSharedPtr(std::make_shared<Map>(".\\res\\map.txt")) {
        if (mapSharedPtr->getPlayerPtr() != nullptr) {
            mgr::view = sf::View(sf::FloatRect(mapSharedPtr->getPlayerPtr()->sprite.getPosition().x -
                                               static_cast<float>(mgr::window.getSize().x) / 2.f +
                                               mapSharedPtr->getPlayerPtr()->sprite.getLocalBounds().width * 2,
                                               mapSharedPtr->getPlayerPtr()->sprite.getPosition().y -
                                               static_cast<float>(mgr::window.getSize().y) / 2.f +
                                               mapSharedPtr->getPlayerPtr()->sprite.getLocalBounds().height * 2,
                                               static_cast<float>(mgr::window.getSize().x),
                                               static_cast<float>(mgr::window.getSize().y)));
        }
    }

    void GameState::HandleInput(const float &dt) {
        sf::Event event{};
        while (mgr::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                mgr::window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            mapSharedPtr->getPlayerPtr()->movement.calcVelocity(0.f, -1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            mapSharedPtr->getPlayerPtr()->movement.calcVelocity(-1.f, 0.f);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                mapSharedPtr->getPlayerPtr()->flipSpriteLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            mapSharedPtr->getPlayerPtr()->movement.calcVelocity(0.f, 1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            mapSharedPtr->getPlayerPtr()->movement.calcVelocity(1.f, 0.f);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                mapSharedPtr->getPlayerPtr()->flipSpriteRight();
        }
    }


    void GameState::Update(float dt) {
        mapSharedPtr->checkCollisions(dt);
        mapSharedPtr->getPlayerPtr()->update(dt);
    }

    void GameState::Draw(float dt) {
        mgr::window.clear();
        drawMap();

        renderEntities();

        mgr::window.setView(mgr::view);
        mgr::window.display();
    }

    void GameState::renderEntities() const {
        for (const auto &entity: mapSharedPtr->getEntities()) {
            entity->render();
        }
    }

    void GameState::drawMap() {
        for (auto &it: mapSharedPtr->getTileMatrix()) {
            for (auto &singleTile: it) {
                mgr::window.draw(singleTile->sprite);
            }
        }
    }
}
