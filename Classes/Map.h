#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TileType.h"
#include "City.h"

class Map {
private:
  std::vector<std::vector<Tile>> grid;
  const int rows = 10;
  const int cols = 16;
  const float tileSize = 50.f;
public:
  Map(int rows = 50, int cols = 50, float tileSize = 32.f);
  void render(sf::RenderWindow& window);
  void handleClick(float x, float y, TileType selectedTileType,City* city);
};



#endif //MAP_H
