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
            static bool loaded = false;
            if (!loaded) {
                if (!factoryTexture.loadFromFile("../assets/textures/factoryTexture2.png")) {
                    std::cerr << "Failed to load factory image" << std::endl;
                }
                loaded = true;
            }
            shape.setTexture(&factoryTexture);
            break;
        case TileType::House:
            shape.setFillColor(sf::Color::Blue);
            break;
    }
}

TileType Tile::getType() const {
    return type;
}
void Tile::render(sf::RenderWindow& window) {
    window.draw(shape);
}

