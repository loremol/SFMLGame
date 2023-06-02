#include <iostream>
#include "MainMenuState.h"
#include "GameState.h"

namespace game {
    MainMenuState::MainMenuState() : playButton(static_cast<float>(mgr::window.getSize().x) / 2.f -
                                                256.f / 2.f, static_cast<float>(mgr::window.getSize().y) / 2.f, 256.f,
                                                50.f, "Play",
                                                "MainMenuFont"),
                                     exitButton(static_cast<float>(mgr::window.getSize().x) / 2.f -
                                                256.f / 2.f, static_cast<float>(mgr::window.getSize().y) / 1.5f,
                                                256.f,
                                                50.f, "Exit",
                                                "MainMenuFont") {
    }

    void MainMenuState::HandleInput(const float &dt) {
        sf::Event event{};
        while (mgr::window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                mgr::window.close();
            }

            if (playButton.isPressed()) {
                try {
                    mgr::assets.loadStateAssets(2);
                } catch (std::out_of_range &out_of_range) {
                    std::cout << out_of_range.what() << std::endl << "Failed to load Game State Assets." << std::endl;
                }
                mgr::states.AddState(StateRef(new GameState()), true);
            }

            if (exitButton.isPressed()) {
                mgr::window.close();
            }
        }
    }

    void MainMenuState::Update(float dt) {
        playButton.update();
        exitButton.update();
    }

    void MainMenuState::Draw(float dt) {
        mgr::window.clear(sf::Color(149, 125, 173));
        playButton.render();
        exitButton.render();
        mgr::window.draw(title);
        mgr::window.display();
    }
}