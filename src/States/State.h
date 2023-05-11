#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

namespace game {
    class State {
    public:
        virtual ~State() = default;

        virtual void HandleInput(const float &dt) = 0;

        virtual void Update(float dt) = 0;

        virtual void Draw(float dt) = 0;

        virtual void Pause() {};

        virtual void Resume() {};
    };
}


#endif //GAME_STATE_HPP
