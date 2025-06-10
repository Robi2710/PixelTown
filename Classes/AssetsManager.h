#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AssetsManager {
public:
  static AssetsManager &getInstance();
  static sf::Texture &getTexture(const std::string &filename);
  void cleanup();

private:
  static AssetsManager *instance;
  static std::map<std::string, sf::Texture> textures;

  AssetsManager() = default;

  AssetsManager(const AssetsManager &) = delete;
  AssetsManager &operator=(const AssetsManager &) = delete;
};

#endif // ASSETSMANAGER_H
