#include "GameLoop.h"
#include "mgr.h"


namespace game {
    void GameLoop::Run() {
        float currentTime = clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;
        while (mgr::window.isOpen()) {
            float newTime, frameTime, interpolation;
            mgr::states.ProcessStateChanges();
            newTime = clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime; // total of all frame times
            while (accumulator >= dt) {
                mgr::states.GetActiveState()->HandleInput(dt);
                mgr::states.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            mgr::states.GetActiveState()->Draw(interpolation);
        }
    }
}