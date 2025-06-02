#include "AssetsManager.h"
#include "Exceptions.h"

AssetsManager* AssetsManager::instance = nullptr;
std::map<std::string, sf::Texture> AssetsManager::textures;

AssetsManager& AssetsManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetsManager();
    }
    return *instance;
}

sf::Texture& AssetsManager::getTexture(const std::string& filename) {
    auto it = textures.find(filename);
    if (it == textures.end()) {
        sf::Texture& texture = textures[filename];
        if (!texture.loadFromFile(filename)) {
            textures.erase(filename);
            throw textureError(filename);
        }
        return texture;
    }
    return it->second;
}

void AssetsManager::cleanup() {
    textures.clear();
    delete instance;
    instance = nullptr;
}