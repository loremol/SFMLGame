cmake_minimum_required(VERSION 3.24.2)

project(SFMLGame)
IF (WIN32)
    set(CMAKE_CXX_STANDARD 17)

    # DLLs
    set(SFML_STATIC_LIBRARIES TRUE)
    # Find cmakelists from SFML
    set(SFML_DIR C:/SFML/lib/cmake/SFML)

    find_package(SFML COMPONENTS graphics REQUIRED)
    include_directories(C:/SFML/include)

    add_executable(SFMLGame main.cpp Map/Tile.cpp Map/Tile.hpp Map/World.cpp Map/World.hpp Entities/Entity.hpp Entities/Player.cpp Entities/Player.hpp Entities/Entity.cpp States/State.hpp States/StateMachine.cpp States/StateMachine.hpp AssetManager.cpp AssetManager.hpp InputManager.cpp InputManager.hpp Game.cpp Game.hpp Definitions.hpp States/SplashState.cpp States/SplashState.hpp States/MainMenuState.cpp States/MainMenuState.hpp States/GameState.cpp States/GameState.hpp States/Button.cpp States/Button.hpp States/PlayButton.cpp States/PlayButton.hpp States/ExitButton.cpp States/ExitButton.hpp)

    target_link_libraries(SFMLGame sfml-graphics)

ELSE ()
    # set stuff for other systems
ENDIF ()
