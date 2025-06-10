#include "Map.h"
#include "Application.h"
#include "BuildingFactory.h"
#include "Buildings.h"
#include "City.h"
#include "Tile.h"
Map::Map(int rows, int cols, float tileSize)
    : rows(rows), cols(cols), tileSize(tileSize), app(nullptr) {
  for (int i = 0; i < rows; ++i) {
    std::vector<Tile> row;
    for (int j = 0; j < cols; ++j) {
      row.emplace_back(j * tileSize, i * tileSize, tileSize);
    }
    grid.push_back(row);
  }
}

void Map::render(sf::RenderWindow &window) {
  for (auto &row : grid) {
    for (auto &tile : row) {
      tile.render(window);
    }
  }
}

void Map::handleClick(float x, float y, TileType selectedTileType, City *city) {
  // std::cout << "handleClick called at x=" << x << ", y=" << y << std::endl;
  int row = static_cast<int>(y / tileSize);
  int col = static_cast<int>(x / tileSize);

  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    TileType current = grid[row][col].getType();
    if (current == TileType::Empty && selectedTileType != TileType::Empty) {
      std::unique_ptr<Buildings> newBuilding(BuildingFactory::createBuilding(selectedTileType));

      if (newBuilding) {
        std::string buildingType = newBuilding->getType();

        if (city->addBuilding(std::move(newBuilding))) {
          grid[row][col].setType(selectedTileType);

          if (app) {
            app->getBuildSound().play();
          }
          std::cout << "A " << buildingType << " was built" << std::endl;
        }
      }
    }
  }
}
