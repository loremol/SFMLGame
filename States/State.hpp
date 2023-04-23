//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_STATE_HPP
#define SFMLGAME_STATE_HPP

namespace SFMLGame {
    class State {
    public:
        virtual ~State() = default;

        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;
        virtual void Pause() {};
        virtual void Resume() {};
    };
}


#endif //SFMLGAME_STATE_HPP
