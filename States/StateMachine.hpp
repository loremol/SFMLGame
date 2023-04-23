//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_STATEMACHINE_HPP
#define SFMLGAME_STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "State.hpp"

namespace SFMLGame {
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
    public:
        StateMachine() : isReplacing(false), isAdding(false), isRemoving(false) {};

        ~StateMachine() = default;

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

#endif //SFMLGAME_STATEMACHINE_HPP
