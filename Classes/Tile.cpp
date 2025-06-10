#include "Tile.h"
#include "AssetsManager.h"
#include "Buildings.h"
#include "City.h"
#include "Exceptions.h"
#include "Factory.h"

Tile::Tile(float x, float y, float size) {
  shape.setSize(sf::Vector2f(size, size));
  shape.setPosition(x, y);
  shape.setFillColor(sf::Color::White);
  type = TileType::Empty;
  sf::Texture &texture =
      AssetsManager::getTexture("../assets/textures/grass.png");
  shape.setTexture(&texture);
}

void Tile::setType(TileType newType) {
  if (type != newType) {
    type = newType;

    std::string texturePath;

    switch (type) {
    case TileType::Empty:
      texturePath = "../assets/textures/grass.png";
      break;

    case TileType::Factory:
      texturePath = "../assets/textures/factoryTexture2.png";
      break;

    case TileType::House:
      texturePath = "../assets/textures/houseTexture.png";
      break;

    case TileType::Road:
      texturePath = "../assets/textures/roadTexture.png";
      break;

    case TileType::PoliceDepartment:
      texturePath = "../assets/textures/policeDepartmentTexture.png";
      break;
    }

    sf::Texture &texture = AssetsManager::getInstance().getTexture(texturePath);
    shape.setTexture(&texture);

    sf::Vector2u texSize = texture.getSize();
    // sf::Vector2f shapeSize = shape.getSize();

    shape.setTextureRect(sf::IntRect(0, 0, texSize.x, texSize.y));
  }
}

TileType Tile::getType() const { return type; }
void Tile::render(sf::RenderWindow &window) { window.draw(shape); }
