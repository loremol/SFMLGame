//
// Created by Lorenzo on 21/04/2023.
//

#include <fstream>
#include "Game.hpp"
#include "States/SplashState.hpp"

namespace SFMLGame {
    Game::Game() {
        sf::ContextSettings contextSettings;
        std::ifstream ifs("settings.txt", std::ios::in);
        if (ifs.is_open()) {
            std::getline(ifs, this->windowTitle);
            ifs >> this->resolution.width >> this->resolution.height;
            ifs >> this->fullscreen;
            ifs >> this->framerateLimit;
            ifs >> this->vsyncEnabled;
            ifs >> this->antialiasingLevel;
        }
        contextSettings.antialiasingLevel = this->antialiasingLevel;
        if (fullscreen) {
            data->window.create(this->resolution, this->windowTitle, sf::Style::Fullscreen, contextSettings);
        } else {
            data->window.create(this->resolution, this->windowTitle, sf::Style::Titlebar | sf::Style::Close,
                                contextSettings);
        }
        data->machine.AddState(StateRef(new SplashState(this->data)));
        ifs.close();
        this->Run();
    }

    void Game::Run() {
        float currentTime = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;
        while (this->data->window.isOpen()) {
            float newTime, frameTime, interpolation;
            this->data->machine.ProcessStateChanges();
            newTime = this->clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime; // total of all frame times
            while (accumulator >= dt) {
                this->data->machine.GetActiveState()->HandleInput(dt);
                this->data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
