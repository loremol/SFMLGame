#ifndef GAME_DEFINITIONS_H
#define GAME_DEFINITIONS_H

#include <filesystem>

// Splash screen
#define SPLASH_STATE_SHOWTIME 0.2

namespace game {
    class FilePaths { // use make_preferred().string() to convert them
    public:
        inline static std::filesystem::path DefaultTexture{"./res/error_texture.png"};
        inline static std::filesystem::path SplashScreenBackgroundPath{"./res/splashscreen/splashscreen.png"};
        // Main menu
        inline static std::filesystem::path MainMenuFontPath{"./res/font/main_menu.ttf"};
        // Game
        inline static std::filesystem::path floor{"./res/sprite/tile/floor_1.png"};
        inline static std::filesystem::path wall{"./res/sprite/tile/wall_corner_front_left.png"};
        inline static std::filesystem::path PlayerIdle0{"./res/sprite/player/skelet_idle_anim_f0.png"};
        inline static std::filesystem::path PlayerIdle1{"./res/sprite/player/skelet_idle_anim_f1.png"};

        inline static std::filesystem::path PlayerMoving0{"./res/sprite/player/skelet_run_anim_f0.png"};
        inline static std::filesystem::path PlayerMoving1{"./res/sprite/player/skelet_run_anim_f1.png"};
        inline static std::filesystem::path PlayerMoving2{"./res/sprite/player/skelet_run_anim_f2.png"};
        inline static std::filesystem::path PlayerMoving3{"./res/sprite/player/skelet_run_anim_f3.png"};
        inline static std::filesystem::path PlayerMoving4{"./res/sprite/player/skelet_run_anim_f4.png"};
        inline static std::filesystem::path PlayerMoving5{"./res/sprite/player/skelet_run_anim_f5.png"};

    };
}

#endif //GAME_DEFINITIONS_H
