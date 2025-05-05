#include "Tile.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
#include "Exceptions.h"

Tile::Tile(float x, float y, float size) {
    type = TileType::Empty;
    shape.setSize(sf::Vector2f(size - 1, size - 1));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Tile::setType(TileType newType) {
    type = newType;
    switch (type) {
        case TileType::Empty:
            shape.setFillColor(sf::Color::White);
            break;
        case TileType::Factory:
            static sf::Texture factoryTexture;
            static bool factoryLoaded = false;
            if (!factoryLoaded) {
                if (!factoryTexture.loadFromFile("../assets/textures/factoryTexture2.png")) {
                    throw textureError("../assets/textures/factoryTexture2.png");
                }
                factoryLoaded = true;
            }
            shape.setTexture(&factoryTexture);
            break;
        case TileType::House:
            static sf::Texture houseTexture;
            static bool houseLoaded = false;
            if (!houseLoaded) {
                if (!houseTexture.loadFromFile("../assets/textures/houseTexture.png")) {
                    throw textureError("../assets/textures/houseTexture.png");
                }
                houseLoaded = true;
            }
            shape.setTexture(&houseTexture);
            break;
        case TileType::Road:
            static sf::Texture roadTexture;
            static bool roadLoaded = false;
            if (!roadLoaded) {
                if (!roadTexture.loadFromFile("../assets/textures/roadTexture.png")) {
                    throw textureError("../assets/textures/roadTexture.png");
                }
                roadLoaded = true;
            }
            shape.setTexture(&roadTexture);
            break;
    }
}

TileType Tile::getType() const {
    return type;
}
void Tile::render(sf::RenderWindow& window) {
    window.draw(shape);
}

