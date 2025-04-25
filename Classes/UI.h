#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "TileType.h"
#include "City.h"
class UI {
private:
  sf::Font font;
  sf::Text moneyText, materialText;
  std::vector<sf::RectangleShape> buttons;
  TileType selectedTileType;
public:
    UI();
    void update(sf::RenderWindow& window, int money, int materials);
    void render(sf::RenderWindow& window);
    void initialize();
    void handleMouseClick(int mouseX, int mouseY);
    TileType getSelectedTileType();
    std::string getCityName();
};



#endif //UI_H
