#include <iostream>
#include "AssetManager.h"
#include "Init.h"
#include "Definitions.h"

namespace game {
    void AssetManager::LoadTexture(const std::string &name, const std::string &fileName) {
        sf::Texture texture;

        if (texture.loadFromFile(fileName)) {
            textures[name] = texture;
        } else {
            std::cout << "Error loading texture." << std::endl << fileName << std::endl;
        }
    }

    const sf::Texture &AssetManager::GetTexture(const std::string &name) {
        try {
            const sf::Texture &texture = textures.at(name);
            return texture;
        } catch (const std::out_of_range &E) {
            std::cout << E.what() << std::endl << "Texture \"" << name
                      << "\" not found in AssetManager::textures; out of range." << std::endl;
            return textures.at("DefaultTexture");
        }

    }

    void AssetManager::LoadFont(const std::string &name, const std::string &fileName) {
        sf::Font font;

        if (font.loadFromFile(fileName)) {
            fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(const std::string &name) {
        return fonts.at(name);
    }

    void AssetManager::LoadStateAssets(const int &id) {
        // 0 SplashState
        // 1 MainMenuState
        // 2 GameState
        switch (id) {
            case 0:
                LoadTexture("SplashStateBackground", FilePaths::SplashScreenBackgroundPath.make_preferred().string());
                LoadTexture("DefaultTexture", FilePaths::DefaultTexture.make_preferred().string());
                break;
            case 1:
                LoadFont("MainMenuFont", FilePaths::MainMenuFontPath.make_preferred().string());
                break;
            case 2:
                LoadTexture("Floor", FilePaths::GameFloorSpritePath.make_preferred().string());
                LoadTexture("PlayerIdle0", FilePaths::PlayerIdle0.make_preferred().string());
                LoadTexture("PlayerIdle1", FilePaths::PlayerIdle1.make_preferred().string());
                LoadTexture("PlayerIdle2", FilePaths::PlayerIdle2.make_preferred().string());
                LoadTexture("PlayerIdle3", FilePaths::PlayerIdle3.make_preferred().string());
                LoadTexture("PlayerMoving0", FilePaths::PlayerMoving0.make_preferred().string());
                LoadTexture("PlayerMoving1", FilePaths::PlayerMoving1.make_preferred().string());
                LoadTexture("PlayerMoving2", FilePaths::PlayerMoving2.make_preferred().string());
                LoadTexture("PlayerMoving3", FilePaths::PlayerMoving3.make_preferred().string());
                LoadTexture("PlayerMoving4", FilePaths::PlayerMoving4.make_preferred().string());
                break;
            default:
                std::cout << "Not a valid ID" << std::endl;
        }
    }

}