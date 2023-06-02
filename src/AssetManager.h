#ifndef GAME_ASSETMANAGER_HPPP
#define GAME_ASSETMANAGER_HPPP

#include <map>
#include <SFML/Graphics.hpp>

namespace game {
    /**
     * Class responsible of creating std::mapSharedPtr that associates names with fonts and textures.
     * It can also return the texture associated with a certain name
     */
    class AssetManager {
    public:
        AssetManager();

        void loadStateAssets(const int &id);

        void loadTexture(const std::string &name, const std::string &fileName);

        const sf::Texture &getTexture(const std::string &name);

        void loadFont(const std::string &name, const std::string &fileName);

        sf::Font &getFont(const std::string &name);

        std::map<int, std::string> textureID;
    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
    };

}

#endif //GAME_ASSETMANAGER_HPPP
