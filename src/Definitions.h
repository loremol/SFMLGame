//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_DEFINITIONS_H
#define SFMLGAME_DEFINITIONS_H

#include <filesystem>

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

// Splash screen
#define SPLASH_STATE_SHOWTIME 0.2

// Filepaths
namespace SFMLGame {
    struct FilePaths { // use make_preferred().string() to convert them
        std::filesystem::path SplashScreenBackgroundPath{"./res/splashscreen/splashscreen.png"};
        // Main menu
        std::filesystem::path MainMenuFontPath{"./res/font/main_menu.ttf"};
        std::filesystem::path MainMenuPlayButtonPath{"./res/ui/green_button00.png"};
        // Game
        std::filesystem::path GameFloorSpritePath{"./res/sprite/tile/floor_1_64px.png"};
        std::filesystem::path PlayerSpritePath{"./res/sprite/enemy/skelet_idle_anim_f0.png"};
    };
}


#endif //SFMLGAME_DEFINITIONS_H
