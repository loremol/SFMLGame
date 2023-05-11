#ifndef GAME_SPLASHSTATE_HPP
#define GAME_SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.h"
#include "../Init.h"
#include "../Definitions.h"

namespace game {
    class SplashState : public State {
    public:
        SplashState();

        void HandleInput(const float &dt) override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        sf::Clock clock;
        sf::Sprite background;
    };
}


#endif //GAME_SPLASHSTATE_HPP
