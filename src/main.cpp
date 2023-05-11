#include "Definitions.h"
#include "Init.h"
#include "mgr.h"
#include "States/SplashState.h"
#include "GameLoop.h"

using namespace game;

int main() {
    Init::window();
    mgr::assets.LoadStateAssets(0);
    mgr::states.AddState(StateRef(new SplashState()));
    GameLoop::Run();

    return EXIT_SUCCESS;
}

