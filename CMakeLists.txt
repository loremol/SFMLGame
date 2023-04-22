cmake_minimum_required(VERSION 3.24.2)

project(SFMLGame)
IF (WIN32)
    set(CMAKE_CXX_STANDARD 17)

    # DLLs
    set(SFML_STATIC_LIBRARIES TRUE)
    # Find cmakelists from SFML
    set(SFML_DIR C:/SFML/lib/cmake/SFML)

    find_package(SFML COMPONENTS system window graphics REQUIRED)
    include_directories(C:/SFML/include)

    add_executable(SFMLGame main.cpp Tile.cpp Tile.hpp World.cpp World.hpp Entity.hpp Player.cpp Player.hpp Entity.cpp State.hpp StateMachine.cpp StateMachine.hpp AssetManager.cpp AssetManager.hpp InputManager.cpp InputManager.hpp Game.cpp Game.hpp Definitions.hpp SplashState.cpp SplashState.hpp MainMenuState.cpp MainMenuState.hpp GameState.cpp GameState.hpp)
    target_link_libraries(SFMLGame sfml-system sfml-window sfml-graphics)

ELSE()
    # set stuff for other systems
ENDIF()
