#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "States/StateManager.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace game {
    class Init {
    public:
        Init();

        ~Init() = default;

    private:
        // used by different states to access GameData
        sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
        std::string windowTitle = "Game";
        bool fullscreen = false;
        unsigned framerateLimit = 120;
        bool vsyncEnabled = false;
        unsigned antialiasingLevel = 0;
    };
}


#endif //GAME_GAME_HPP
