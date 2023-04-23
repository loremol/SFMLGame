//
// Created by Lorenzo on 21/04/2023.
//

#include "Game.hpp"
#include "States/SplashState.hpp"

namespace SFMLGame {
    Game::Game(int width, int height, const std::string& title) {
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        data->machine.AddState(StateRef(new SplashState(this->data)));
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
            if(frameTime > 0.25f) {
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime; // total of all frame times
            while(accumulator >= dt) {
                this->data->machine.GetActiveState()->HandleInput();
                this->data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
