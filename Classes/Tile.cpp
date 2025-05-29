#include "Tile.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
#include "Exceptions.h"

Tile::Tile(float x, float y, float size) {
    shape.setSize(sf::Vector2f(size , size ));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    //setType(TileType::Empty);
}

void Tile::setType(TileType newType) {
    type = newType;
    switch (type) {

        case TileType::Empty: {
            static sf::Texture emptyTexture;
            static bool emptyLoaded = false;
            if (!emptyLoaded) {
                if (!emptyTexture.loadFromFile("../assets/textures/grass.png")) {
                    throw textureError("../assets/textures/grass.png");
                }
                emptyLoaded = true;
            }
            shape.setTexture(&emptyTexture);
            break;
        }

        case TileType::Factory: {
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
        }

        case TileType::House: {
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
        }

        case TileType::Road: {
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
        case TileType::PoliceDepartment: {
            static sf::Texture policeDepartmentTexture;
            static bool policeDepartmentLoaded = false;
            if (!policeDepartmentLoaded) {
                if (!policeDepartmentTexture.loadFromFile("../assets/textures/policeDepartmentTexture.png")) {
                    throw textureError("../assets/textures/policeDepartmentTexture.png");
                }
                policeDepartmentLoaded = true;
            }
            shape.setTexture(&policeDepartmentTexture);
            break;
        }
    }
}

TileType Tile::getType() const {
    return type;
}
void Tile::render(sf::RenderWindow& window) {
    window.draw(shape);
}

