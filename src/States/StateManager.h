#ifndef GAME_STATEMACHINE_HPP
#define GAME_STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "State.h"

namespace game {
    typedef std::unique_ptr<State> StateRef;

    class StateManager {
    public:
        StateManager() : isReplacing(false), isAdding(false), isRemoving(false) {};

        ~StateManager() = default;

        void AddState(StateRef newState, bool isReplacing = true);

        void RemoveState();

        void ProcessStateChanges(); // runs at start of game loop

        StateRef &GetActiveState();

    private:
        std::stack<StateRef> states;
        StateRef addedState;

        bool isRemoving;
        bool isAdding;
        bool isReplacing;
    };
}

#endif //GAME_STATEMACHINE_HPP
