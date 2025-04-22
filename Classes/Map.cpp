#include "Map.h"

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

void Map::handleClick(float x, float y, TileType selectedTileType) {
    int row = static_cast<int>(y / tileSize);
    int col = static_cast<int>(x / tileSize);

    if (row >= 0 && row < rows && col >= 0 && col < cols) {
      TileType current = grid[row][col].getType();
      if (current == TileType::Empty) {
        grid[row][col].setType(selectedTileType);
      }
    }
}
