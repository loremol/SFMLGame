//
// Created by Lorenzo on 21/04/2023.
//

#include <sstream>
#include <iostream>
#include <utility>
#include "SplashState.hpp"
#include "Definitions.hpp"
#include "MainMenuState.hpp"

namespace SFMLGame {
    SplashState::SplashState(GameDataRef data) : data(std::move(data)) {
        this->data->assets.LoadTexture("SplashStateBackground", filePaths.SplashScreenBackgroundPath.make_preferred().string());
        background.setTexture(this->data->assets.GetTexture("SplashStateBackground"));
    }

    void SplashState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->data->window.close();
            }
        }
    }

    void SplashState::Update(float dt) {
        if (this->clock.getElapsedTime().asSeconds() >= SPLASH_STATE_SHOWTIME) {
            // Switch to Main menu
            this->data->machine.AddState(StateRef(new MainMenuState(this->data)), true);
        }
    }
    void SplashState::Draw(float dt) {
        this->data->window.clear();
        this->data->window.draw(this->background);
        this->data->window.display();
    }

    void SplashState::Init() {

    }
}