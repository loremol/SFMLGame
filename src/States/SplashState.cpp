#include <iostream>
#include "../mgr.h"
#include "SplashState.h"
#include "MainMenuState.h"

namespace game {
    SplashState::SplashState() {
        background.setTexture(mgr::assets.getTexture("SplashStateBackground"));
    }

    void SplashState::HandleInput(const float &dt) {
        sf::Event event{};
        while (mgr::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mgr::window.close();
            }
        }
    }

    void SplashState::Update(float dt) {
        if (clock.getElapsedTime().asSeconds() >= SPLASH_STATE_SHOWTIME) {
            try {
                mgr::assets.loadStateAssets(1);
            } catch (std::out_of_range &out_of_range) {
                std::cout << out_of_range.what() << std::endl << "Failed to load Main Menu State Assets." << std::endl;
            }
            mgr::states.AddState(StateRef(new MainMenuState), true);
        }
    }

    void SplashState::Draw(float dt) {
        mgr::window.clear();
        mgr::window.draw(background);
        mgr::window.display();
    }
}