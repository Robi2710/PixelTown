#ifndef TILE_H
#define TILE_H

#include "TileType.h"
#include <SFML/Graphics.hpp>

class Tile {
private:
  TileType type;
  sf::RectangleShape shape;
  // static sf::Texture backgroundTexture;
  // static bool textureLoaded;
public:
  Tile(float x, float y, float size);
  Tile(TileType type, float x, float y, float size,
       const sf::Texture &textureAtlas);

  void setType(TileType newType);
  TileType getType() const;
  void render(sf::RenderWindow &window);
};

#endif // TILE_H
