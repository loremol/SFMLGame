#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include "GameTile.h"
#include "Player.h"


// 1. User interaction
// 2. Update game state
// 3. Draw to the screen

int main() {
    sf::Vector2i        windowResolution(512,512);
    sf::Vector2i        backgroundTileResolution(64,64);
    sf::Vector2i        playerSpriteResolution(64,64);
    std::string         windowName("Game");
    std::string         resourcesPath(R"(C:\Users\Lorenzo\Codice\C++\SFMLTest\res\)");

    sf::RenderWindow    win(sf::VideoMode(windowResolution.x,windowResolution.y), windowName);
    GameWorld           gameWorld = GameWorld(backgroundTileResolution, windowResolution);
    Player              player(resourcesPath + R"(sprites\tile\frames\skelet_idle_anim_f0.png)", playerSpriteResolution);

    // Start game loop
    while (win.isOpen())
    {
        // 1. Polling for events (closed window)
        sf::Event event{};
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                printf("%d\n%d\n", sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                player.setPressedKey(sf::Keyboard::D);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                player.setPressedKey(sf::Keyboard::A);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                player.setPressedKey(sf::Keyboard::S);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                player.setPressedKey(sf::Keyboard::W);
        }

        // 2. Update game state
        player.checkPressedKeys();
        player.resetPressedKeys();

        // 3. Draw shapes/sprites

        win.clear();

        for (int i = 0; i < gameWorld.getGridLength(); i++) {
            for (int j = 0; j < gameWorld.getGridLength(); j++) {
                win.draw(gameWorld.tiles[i][j]->sprite);
            }
        }
        win.draw(player.getSprite());

        win.display();
    }

    return 0;
}