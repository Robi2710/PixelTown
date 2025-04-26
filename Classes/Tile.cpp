#include "Tile.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"

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
                    std::cerr << "Failed to load factory image" << std::endl;
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
                    std::cerr << "Failed to load factory image" << std::endl;
                }
                houseLoaded = true;
            }
            shape.setTexture(&houseTexture);
            break;
    }
}

TileType Tile::getType() const {
    return type;
}
void Tile::render(sf::RenderWindow& window) {
    window.draw(shape);
}

