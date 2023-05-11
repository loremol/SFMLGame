#include <fstream>
#include "mgr.h"
#include "States/SplashState.h"
#include "GameLoop.h"

namespace game {
    Init::Init() {
        sf::ContextSettings contextSettings;
        std::ifstream fileInputStream("settings.txt", std::ios::in);
        if (fileInputStream.is_open()) {
            std::getline(fileInputStream, windowTitle);
            fileInputStream >> resolution.width >> resolution.height;
            fileInputStream >> fullscreen;
            fileInputStream >> framerateLimit;
            fileInputStream >> vsyncEnabled;
            fileInputStream >> antialiasingLevel;
            fileInputStream.close();
        }
        contextSettings.antialiasingLevel = antialiasingLevel;
        if (fullscreen) {
            mgr::window.create(resolution, windowTitle, sf::Style::Fullscreen, contextSettings);
        } else {
            mgr::window.create(resolution, windowTitle, sf::Style::Titlebar | sf::Style::Close,
                               contextSettings);
        }
        mgr::assets.LoadStateAssets(0);
        mgr::states.AddState(StateRef(new SplashState()));

        GameLoop::Run();
    }


}
