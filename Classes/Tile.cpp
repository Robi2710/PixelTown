#include "Tile.h"

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
            shape.setFillColor(sf::Color::Red);
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

