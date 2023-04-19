cmake_minimum_required(VERSION 3.24.2)

project(SFMLGame)
IF (WIN32)
    set(CMAKE_CXX_STANDARD 17)

    # DLLs
    set(SFML_STATIC_LIBRARIES TRUE)
    # Find cmakes from SFML
    set(SFML_DIR C:/SFML/lib/cmake/SFML)

    find_package(SFML COMPONENTS system window graphics REQUIRED)
    include_directories(C:/SFML/include)

    add_executable(SFMLGame main.cpp GameTile.cpp GameTile.h GameWorld.cpp GameWorld.h GameEntity.h Player.cpp Player.h GameEntity.cpp)
    target_link_libraries(SFMLGame sfml-system sfml-window sfml-graphics)

ELSE()
    # set stuff for other systems
ENDIF()
