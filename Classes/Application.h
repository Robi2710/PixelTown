#ifndef APPLICATION_H
#define APPLICATION_H

#include "City.h"
#include "Exceptions.h"
#include "Factory.h"
#include "Map.h"
#include "ResourceManager.h"
#include "Resources.h"
#include "UI.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class Application {
private:
  void processEvents();
  void update();
  void render();

  UI ui_;
  Resources resources_;
  City city_;
  sf::RenderWindow window_;
  Map map_;
  sf::Texture grassTexture_;
  sf::Sprite grassSprite_;
  sf::View view_;
  Factory factory_;

  ResourceManager<sf::Font> fontManager_;
  ResourceManager<sf::SoundBuffer> soundBufferManager_;
  sf::Sound buildSound_;

public:
  Application();
  int run();
  sf::Sound &getBuildSound();
};

#endif // APPLICATION_H
