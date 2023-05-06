//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_GAME_HPP
#define SFMLGAME_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "States/StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace SFMLGame {
    struct GameData {
        sf::RenderWindow window;
        StateMachine machine;
        AssetManager assets;
        InputManager input;
    };
    /// Shared pointer for Game's GameData struct
    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    public:
        Game();

        ~Game() = default;

    private:
        const float dt = 1.0f / 60.0f; // times to update per second
        const sf::Clock clock; // required for handling framerate
        const GameDataRef data = std::make_shared<GameData>(); // used by different states to access GameData
        sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
        std::string windowTitle = "Game";
        bool fullscreen = false;
        unsigned framerateLimit = 120;
        bool vsyncEnabled = false;
        unsigned antialiasingLevel = 0;

        void Run();
    };
}

#endif //SFMLGAME_GAME_HPP