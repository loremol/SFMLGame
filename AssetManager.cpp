//
// Created by Lorenzo on 21/04/2023.
//

#include <iostream>
#include "AssetManager.hpp"

namespace SFMLGame {
    /**
     * Loads a texture and stores it in the textures map
     * @param name Key value to be paired with the texture
     * @param fileName File path of the texture
     */
    void SFMLGame::AssetManager::LoadTexture(const std::string &name, const std::string &fileName) {
        sf::Texture texture;

        if (texture.loadFromFile(fileName)) {
            this->textures[name] = texture;
        } else {
            std::cout << "Error loading texture." << std::endl << fileName << std::endl;
        }
    }

    /**
     *
     * @param name Name that is paired to a certain texture
     * @return Texture returned by textures map
     */
    sf::Texture &SFMLGame::AssetManager::GetTexture(const std::string &name) {
        return this->textures.at(name);
    }

    /**
     * Loads a texture and stores it in the _fonts map
     * @param name Key value to be paired with the font
     * @param fileName File path of the font
     */
    void SFMLGame::AssetManager::LoadFont(const std::string &name, const std::string &fileName) {
        sf::Font font;

        if (font.loadFromFile(fileName)) {
            this->fonts[name] = font;
        }
    }

    /**
     *
     * @param name Name is paired to a certain font
     * @return Font returned by fonts map
     */
    sf::Font &SFMLGame::AssetManager::GetFont(const std::string &name) {
        return this->fonts.at(name);
    }
}