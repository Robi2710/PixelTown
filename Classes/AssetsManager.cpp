#include "AssetsManager.h"
#include "Exceptions.h""
std::map<std::string, sf::Texture> AssetsManager::textures;

sf::Texture& AssetsManager::getTexture(const std::string& filename) {
    auto it = textures.find(filename);
    if (it == textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(filename)) {
            throw textureError(filename);
        }
        textures[filename] = std::move(texture);
    }
    return textures[filename];
}