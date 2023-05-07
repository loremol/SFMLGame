//
// Created by Lorenzo on 21/04/2023.
//

#ifndef SFMLGAME_ASSETMANAGER_HPPP
#define SFMLGAME_ASSETMANAGER_HPPP

#include <map>
#include <SFML/Graphics.hpp>

namespace SFMLGame {
    /**
     * Class responsible of creating std::map that associate names with fonts and textures.
     * It can also return the texture associated with a certain name
     */
    class AssetManager {
    public:
        AssetManager() = default;

        ~AssetManager() = default;

        void LoadTexture(const std::string &name, const std::string &fileName);

        sf::Texture &GetTexture(const std::string &name);

        void LoadFont(const std::string &name, const std::string &fileName);

        sf::Font &GetFont(const std::string &name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
    };

}

#endif //SFMLGAME_ASSETMANAGER_HPPP
