#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AssetsManager {
public:
    static sf::Texture& getTexture(const std::string& filename);

private:
    static std::map<std::string, sf::Texture> textures;
};



#endif //ASSETSMANAGER_H
