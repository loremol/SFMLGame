#ifndef GAME_GAMELOOP_H
#define GAME_GAMELOOP_H

#include <SFML/System/Clock.hpp>

namespace game {
    class GameLoop {
    public:
        static void Run();

    private:
        constexpr static const float dt = 1.0f / 60.0f; // times to update per second
        inline static const sf::Clock clock; // required for handling framerate
    };
}

#endif //GAME_GAMELOOP_H
