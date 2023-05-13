#include <string>
#include "StateManager.h"

namespace game {
    void StateManager::AddState(StateRef newState, bool isAskingToReplace) {
        addedState = std::move(newState);
        isAdding = true;
        isReplacing = isAskingToReplace;
    }

//    void StateManager::RemoveState() {
//        isRemoving = true;
//    }

    void StateManager::ProcessStateChanges() {
        if (isAdding) {
            if (!states.empty()) { // if there is something to replace
                if (isReplacing) {
                    states.pop(); // if replacing, pop the previous state
                } else {
                    states.top()->Pause(); // if adding but not replacing, pause the previous state
                }
            }
            states.push(std::move(addedState));
//            states.top()->Init();

            isAdding = false;
        }
        if (isRemoving && !states.empty()) { // if there is something to pop
            states.pop();
            if (!states.empty()) {
                states.top()->Resume(); // resume the previous state
            }
            isRemoving = false;
        }
    }

    StateRef &StateManager::GetActiveState() {
        return states.top();
    }
}