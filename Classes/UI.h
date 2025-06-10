#ifndef UI_H
#define UI_H

#include "City.h"
#include "TileType.h"
#include <SFML/Graphics.hpp>
class UI {
private:
  sf::Font font;
  sf::Text moneyText, materialText;
  std::vector<sf::RectangleShape> buttons;
  TileType selectedTileType;
  std::vector<sf::Text> buttonTexts;

public:
  UI();
  void update(int money, int materials);
  void render(sf::RenderWindow &window);
  void initialize();
  void handleMouseClick(int mouseX, int mouseY);
  TileType getSelectedTileType();
  static std::string getCityName();
  void setFont(const sf::Font &font);
};

#endif // UI_H
