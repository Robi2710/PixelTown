//
// Created by Roberto Baciu on 22.04.2025.
//

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
    void setType(TileType newType);
    TileType getType() const;
    void render(sf::RenderWindow& window);
};



#endif //TILE_H
