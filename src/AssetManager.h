#ifndef GAME_ASSETMANAGER_HPPP
#define GAME_ASSETMANAGER_HPPP

#include <map>
#include <SFML/Graphics.hpp>

namespace game {
    /**
     * Class responsible of creating std::map that associates names with fonts and textures.
     * It can also return the texture associated with a certain name
     */
    class AssetManager {
    public:
        AssetManager() = default;

        ~AssetManager() = default;

        void LoadStateAssets(const int &id);

        void LoadTexture(const std::string &name, const std::string &fileName);

        const sf::Texture &GetTexture(const std::string &name);

        void LoadFont(const std::string &name, const std::string &fileName);

        sf::Font &GetFont(const std::string &name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
    };

}

#endif //GAME_ASSETMANAGER_HPPP
