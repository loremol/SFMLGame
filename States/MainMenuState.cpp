//
// Created by Lorenzo on 21/04/2023.
//

#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace SFMLGame {
    MainMenuState::MainMenuState(GameDataRef data) : data(std::move(data)),
                                                     playButton(this->data,
                                                                static_cast<float>(this->data->window.getSize().x / 2) -
                                                                256.f / 2.f, this->data->window.getSize().y / 2, 256.f,
                                                                50.f, "Play",
                                                                "MainMenuFont"),
                                                     exitButton(this->data,
                                                                static_cast<float>(this->data->window.getSize().x / 2) -
                                                                256.f / 2.f, this->data->window.getSize().y / 1.5f, 256.f,
                                                                50.f, "Exit",
                                                                "MainMenuFont") {
        this->title = sf::Text("SFMLGame", this->data->assets.GetFont("MainMenuFont"), 30);
        this->title.setPosition((static_cast<float>(SCREEN_WIDTH) / 2.f) - (this->title.getGlobalBounds().width / 2),
                                this->title.getGlobalBounds().height * 0.1f);
    }

    void MainMenuState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->data->window.close();
            }

            if (this->playButton.isPressed()) {
                this->data->machine.AddState(StateRef(new GameState(this->data)), true);
            }

            if(this->exitButton.isPressed()) {
                this->data->window.close();
            }
        }
    }

    void MainMenuState::Update(float dt) {
        this->playButton.update();
        this->exitButton.update();
    }

    void MainMenuState::Draw(float dt) {
        this->data->window.clear(sf::Color(149, 125, 173));
        this->playButton.render();
        this->exitButton.render();
        this->data->window.draw(this->title);
        this->data->window.display();
    }
}