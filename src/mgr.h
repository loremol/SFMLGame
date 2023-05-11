//
// Created by Lorenzo on 11/05/2023.
//

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
        inline static sf::RenderWindow window;
        inline static StateManager states;
        inline static AssetManager assets;
        inline static InputManager input;

    };
}


#endif //GAME_MGR_H
