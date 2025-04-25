#include "UI.h"
#include "Buildings.h"
#include "Factory.h"
#include "City.h"
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
    } else if (mouseX >= 120 && mouseX <= 220 && mouseY >= 10 && mouseY <= 60) {
        selectedTileType = TileType::House;
        //std::cout << "House button clicked" << std::endl;
    }
}

TileType UI::getSelectedTileType() {
    return selectedTileType;
}

std::string UI::getCityName() {
    sf::RenderWindow inputWindow(sf::VideoMode(800,600), "Enter city name");
    sf::Font font;
    font.loadFromFile("../assets/fonts/PixelifySans-Regular.ttf");

    sf::Text prompt("Enter City Name: ", font, 30);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(20, 20);

    sf::Text cityText("", font, 30);
    cityText.setFillColor(sf::Color::White);
    cityText.setPosition(20, 80);

    std::string cityName;
    while (inputWindow.isOpen()) {
        sf::Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                inputWindow.close();
                return "";
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                    inputWindow.close();
                } else if (event.text.unicode == 8) { // Backspace
                    if (!cityName.empty()) {
                        cityName.pop_back();
                    }
                } else if (event.text.unicode < 128) {
                    cityName.push_back(static_cast<char>(event.text.unicode));
                }
                cityText.setString(cityName);
            }
        }
        inputWindow.clear(sf::Color::Black);
        inputWindow.draw(prompt);
        inputWindow.draw(cityText);
        inputWindow.display();
    }
    return cityName;
}