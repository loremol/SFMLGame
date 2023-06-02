#include <iostream>
#include "AssetManager.h"
#include "Init.h"
#include "Definitions.h"

namespace game {
    AssetManager::AssetManager() {
        textureID.insert(std::pair<int, std::string>(0, "floor"));
        textureID.insert(std::pair<int, std::string>(1, "wall"));
    }

    void AssetManager::loadTexture(const std::string &name, const std::string &fileName) {
        sf::Texture texture;

        if (texture.loadFromFile(fileName)) {
            textures[name] = texture;
        } else {
            std::cout << "Error loading texture." << std::endl << fileName << std::endl;
        }
    }

    const sf::Texture &AssetManager::getTexture(const std::string &name) {
        try {
            const sf::Texture &texture = textures.at(name);
            return texture;
        } catch (const std::out_of_range &E) {
            std::cout << E.what() << std::endl << "Texture \"" << name
                      << "\" not found in AssetManager::textures; out of range." << std::endl;
            return textures.at("DefaultTexture");
        }

    }

    void AssetManager::loadFont(const std::string &name, const std::string &fileName) {
        sf::Font font;

        if (font.loadFromFile(fileName)) {
            fonts[name] = font;
        }
    }

    sf::Font &AssetManager::getFont(const std::string &name) {
        return fonts.at(name);
    }

    void AssetManager::loadStateAssets(const int &id) {
        // 0 SplashState
        // 1 MainMenuState
        // 2 GameState
        switch (id) {
            case 0:
                loadTexture("SplashStateBackground",
                            FilePaths::SplashScreenBackgroundPath.make_preferred().string());
                loadTexture("DefaultTexture", FilePaths::DefaultTexture.make_preferred().string());
                break;
            case 1:
                loadFont("MainMenuFont", FilePaths::MainMenuFontPath.make_preferred().string());
                break;
            case 2:
                loadTexture("floor", FilePaths::floor.make_preferred().string());
                loadTexture("wall", FilePaths::wall.make_preferred().string());
                loadTexture("PlayerIdle0", FilePaths::PlayerIdle0.make_preferred().string());
                loadTexture("PlayerIdle1", FilePaths::PlayerIdle1.make_preferred().string());
                loadTexture("PlayerMoving0", FilePaths::PlayerMoving0.make_preferred().string());
                loadTexture("PlayerMoving1", FilePaths::PlayerMoving1.make_preferred().string());
                loadTexture("PlayerMoving2", FilePaths::PlayerMoving2.make_preferred().string());
                loadTexture("PlayerMoving3", FilePaths::PlayerMoving3.make_preferred().string());
                loadTexture("PlayerMoving4", FilePaths::PlayerMoving4.make_preferred().string());
                loadTexture("PlayerMoving5", FilePaths::PlayerMoving5.make_preferred().string());
                break;
            default:
                std::cout << "Not a valid ID" << std::endl;
        }
    }
}