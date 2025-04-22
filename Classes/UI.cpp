#include "UI.h"
#include <iostream>
UI::UI() {
    font.loadFromFile("../assets/fonts/PixelifySans-Regular.ttf");

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::Green);
    moneyText.setPosition(10, 520);

    materialText.setFont(font);
    materialText.setCharacterSize(24);
    materialText.setFillColor(sf::Color::Yellow);
    materialText.setPosition(10, 500);
}

void UI::update(sf::RenderWindow& window, int money, int materials) {
    moneyText.setString("Money: " + std::to_string(money));
    materialText.setString("Materials: " + std::to_string(materials));

    // window.draw(moneyText);
    // window.draw(materialText);
    // window.display();
}

void UI::render(sf::RenderWindow& window) {
    for (auto& button : buttons) {
        window.draw(button);
    }
    window.draw(moneyText);
    window.draw(materialText);
}

void UI::initialize() {
    sf::RectangleShape factoryButton(sf::Vector2f(100,50));
    factoryButton.setPosition(10, 10);
    factoryButton.setFillColor(sf::Color::Red);

    sf::RectangleShape houseButton(sf::Vector2f(100,50));
    houseButton.setPosition(120, 10);
    houseButton.setFillColor(sf::Color::Blue);

    buttons.push_back(factoryButton);
    buttons.push_back(houseButton);
}

void UI::handleMouseClick(int mouseX, int mouseY) {
    if (mouseX >= 10 && mouseX <= 110 && mouseY >= 10 && mouseY <= 60) {
        selectedTileType = TileType::Factory;
        //std::cout << "Factory button clicked" << std::endl;
    } else if (mouseX >= 120 && mouseX <= 220 && mouseY >= 10 && mouseY <= 60) {
        selectedTileType = TileType::House;
        //std::cout << "House button clicked" << std::endl;
    }
}

TileType UI::getSelectedTileType() {
    return selectedTileType;
}