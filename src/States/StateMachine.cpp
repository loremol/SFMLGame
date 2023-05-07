//
// Created by Lorenzo on 21/04/2023.
//

#include "StateMachine.h"

namespace SFMLGame {
    void StateMachine::AddState(StateRef newState, bool isAskingToReplace) {
        this->isAdding = true;
        this->isReplacing = isAskingToReplace;
        this->addedState = std::move(newState);
    }

    void StateMachine::RemoveState() {
        this->isRemoving = true;
    }

    void StateMachine::ProcessStateChanges() {
        if (this->isRemoving && !this->states.empty()) { // if there is something to pop
            this->states.pop();
            if (!this->states.empty()) {
                this->states.top()->Resume(); // resume the previous state
            }
            this->isRemoving = false;
        }
        if (this->isAdding) {
            if (!this->states.empty()) { // if there is something to replace
                if (this->isReplacing) {
                    this->states.pop(); // if replacing, pop the previous state
                } else {
                    this->states.top()->Pause(); // if adding but not replacing, pause the previous state
                }
            }
            this->states.push(std::move(this->addedState));
            this->states.top()->Init();
            this->isAdding = false;
        }
    }

    StateRef &StateMachine::GetActiveState() {
        return this->states.top();
    }
}