#include "Map.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
#include "House.h"
#include "PoliceDepartment.h"
#include "Road.h"
#include "Tile.h"
#include "BuildingFactory.h"
#include "Application.h"
Map::Map(int rows, int cols, float tileSize) : rows(rows), cols(cols), tileSize(tileSize) {
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
        if (current == TileType::Empty && selectedTileType != TileType::Empty) {
            Buildings* newBuilding = BuildingFactory::createBuilding(selectedTileType);

            if (newBuilding && city->addBuilding(newBuilding)) {
                grid[row][col].setType(selectedTileType);

                if (app) {
                    app->getBuildSound().play();
                }
                std::cout << "A " << newBuilding->getType() << " was built" << std::endl;
            }
        }
    }
}