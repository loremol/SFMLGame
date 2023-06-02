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
        static void window();

    private:
        inline static sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
        inline static std::string windowTitle = "Game";
        inline static bool fullscreen = false;
        inline static unsigned framerateLimit = 120;
        inline static bool vsyncEnabled = false;
        inline static unsigned antialiasingLevel = 0;
    };
}


#endif //GAME_GAME_HPP
