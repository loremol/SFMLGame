//
// Created by Lorenzo on 21/04/2023.
//

#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace SFMLGame {
    MainMenuState::MainMenuState(GameDataRef data) : data(std::move(data)) {
        this->data->assets.LoadTexture("MainMenuPlayButton",
                                       filePaths.MainMenuPlayButtonPath.make_preferred().string());
        this->data->assets.LoadFont("MainMenuFont", filePaths.MainMenuFontPath.make_preferred().string());

        this->title = sf::Text("SFMLGame", this->data->assets.GetFont("MainMenuFont"), 30);
        this->title.setPosition((static_cast<float>(SCREEN_WIDTH) / 2.f) - (this->title.getGlobalBounds().width / 2),
                                this->title.getGlobalBounds().height * 0.1f);
        this->playButtonSprite.setTexture(this->data->assets.GetTexture("MainMenuPlayButton"));
        this->playButtonSprite.setPosition(
                (static_cast<float>(SCREEN_WIDTH) / 2.f) - (this->playButtonSprite.getGlobalBounds().width / 2),
                (static_cast<float>(SCREEN_HEIGHT) / 2.f) - (this->playButtonSprite.getGlobalBounds().height / 2));
        this->playButtonText = sf::Text("Play", this->data->assets.GetFont("MainMenuFont"));
        this->playButtonText.setPosition(
                static_cast<float>(SCREEN_WIDTH) / 2.f - this->playButtonText.getGlobalBounds().width / 2,
                (static_cast<float>(SCREEN_HEIGHT) / 2.f - this->playButtonText.getGlobalBounds().height) * 0.99f);
    }

    void MainMenuState::HandleInput() {
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->data->window.close();
            }

            if (this->data->input.IsSpriteClicked(this->playButtonSprite, sf::Mouse::Left, this->data->window)) {
                this->data->machine.AddState(StateRef(new GameState(this->data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt) {

    }

    void MainMenuState::Draw(float dt) {
        this->data->window.clear(sf::Color(149, 125, 173));
        this->data->window.draw(this->playButtonSprite);
        this->data->window.draw(this->playButtonText);
        this->data->window.draw(this->title);
        this->data->window.display();
    }
}