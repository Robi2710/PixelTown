#include "Map.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
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
        grid[row][col].setType(selectedTileType);
        if (selectedTileType == TileType::Factory) {
            Buildings* newBuilding = new Factory("factory", 100, 200, 100, "product", 10);
            if (city->addBuilding(newBuilding)) {
                grid[row][col].setType(selectedTileType);
                std::cout<<"A factory was built";
            }
        } else if (selectedTileType == TileType::House) {
            std::cout << "House built at (" << row << ", " << col << ")" << std::endl;
        }
      }
    }
}
