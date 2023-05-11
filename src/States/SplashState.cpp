#include <iostream>
#include "../mgr.h"
#include "SplashState.h"
#include "MainMenuState.h"

namespace game {
    SplashState::SplashState() {
        background.setTexture(mgr::assets.GetTexture("SplashStateBackground"));
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
            mgr::assets.LoadStateAssets(1);
            mgr::states.AddState(StateRef(new MainMenuState), true);
        }
    }

    void SplashState::Draw(float dt) {
        mgr::window.clear();
        mgr::window.draw(background);
        mgr::window.display();
    }
}