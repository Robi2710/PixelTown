#include "Map.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
#include "House.h"
#include "Road.h"

Map::Map() {
    for (int i = 0; i < rows; ++i) {
        std::vector<Tile> row;
        for (int j = 0; j < cols; ++j) {
            row.emplace_back(j * tileSize, i * tileSize, tileSize);
        }
        grid.push_back(row);
    }
}

void Map::render(sf::RenderWindow& window) {
   for (auto& row : grid) {
        for (auto& tile : row) {
            tile.render(window);
        }
   }
}

void Map::handleClick(float x, float y, TileType selectedTileType, City* city) {
    int row = static_cast<int>(y / tileSize);
    int col = static_cast<int>(x / tileSize);

    if (row >= 0 && row < rows && col >= 0 && col < cols) {
      TileType current = grid[row][col].getType();
      if (current == TileType::Empty) {
        if (selectedTileType == TileType::Factory) {
            Buildings* newBuilding = new Factory("factory", 100, 200, 100, "product", 10,50, 30);
            if (city->addBuilding(newBuilding)) {
                grid[row][col].setType(selectedTileType);
                std::cout<<"A factory was built";
            }
        } else if (selectedTileType == TileType::House) {
            Buildings* newBuilding = new House("house", 10, 100, 50, 20);
            if (city->addBuilding(newBuilding)) {
                grid[row][col].setType(selectedTileType);
                std::cout<<"A house was built";
            }
        } else if (selectedTileType == TileType::Road) {
            Buildings* newBuilding = new Road("road", 0, 50, 25);
            if (city->addBuilding(newBuilding)) {
                grid[row][col].setType(selectedTileType);
                std::cout<<"A road was built";
            }
        }
      }
    }
}
