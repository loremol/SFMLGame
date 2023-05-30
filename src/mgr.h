#ifndef GAME_MGR_H
#define GAME_MGR_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "States/StateManager.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace game {
    class mgr {
    public:
        mgr() {
            view.setViewport(sf::FloatRect(0, 0, 1, 1));
        }

        inline static sf::RenderWindow window;
        inline static sf::View view;
        inline static StateManager states;
        inline static AssetManager assets;
    };
}

#endif //GAME_MGR_H
