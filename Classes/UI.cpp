#include "UI.h"
#include "Factory.h"
#include "City.h"
#include <iostream>
#include "Exceptions.h"
UI::UI() : selectedTileType(TileType::Empty) {
    if (!font.loadFromFile("../assets/fonts/PixelifySans-Regular.ttf")) {
        throw fontError("../assets/fonts/PixelifySans-Regular.ttf");
    }

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::Green);
    moneyText.setPosition(10, 520);

    materialText.setFont(font);
    materialText.setCharacterSize(24);
    materialText.setFillColor(sf::Color::Yellow);
    materialText.setPosition(10, 500);
}

void UI::update( int money, int materials) {
    moneyText.setString("Money: " + std::to_string(money));
    materialText.setString("Materials: " + std::to_string(materials));

    // window.draw(moneyText);
    // window.draw(materialText);
    // window.display();
}

void UI::render(sf::RenderWindow& window) {
    sf::RectangleShape menuBackground;
    sf::Vector2f viewSize = window.getDefaultView().getSize();
    menuBackground.setSize(sf::Vector2f(viewSize.x, 100.f));
    menuBackground.setFillColor(sf::Color(50, 50, 50));
    menuBackground.setPosition(0, viewSize.y - 100.f);
    window.draw(menuBackground);

    for (auto& button : buttons) {
        window.draw(button);
    }
    for (auto& text : buttonTexts) {
        window.draw(text);
    }

    window.draw(moneyText);
    window.draw(materialText);
}

void UI::initialize() {
    sf::RectangleShape factoryButton(sf::Vector2f(100,50));
    factoryButton.setPosition(200, 500);
    factoryButton.setFillColor(sf::Color(218, 160, 109));

    sf::RectangleShape houseButton(sf::Vector2f(100,50));
    houseButton.setPosition(320, 500);
    houseButton.setFillColor(sf::Color(218, 160, 109));

    sf::RectangleShape roadButton(sf::Vector2f(100,50));
    roadButton.setPosition(440, 500);
    roadButton.setFillColor(sf::Color(218, 160, 109));

    sf::RectangleShape policeButton(sf::Vector2f(100,50));
    policeButton.setPosition(550, 500);
    policeButton.setFillColor(sf::Color(218, 160, 109));

    sf::Text factoryText;
    factoryText.setFont(font);
    factoryText.setString("Factory");
    factoryText.setCharacterSize(20);
    factoryText.setFillColor(sf::Color::Yellow);
    factoryText.setPosition(210, 500);

    sf::Text houseText;
    houseText.setFont(font);
    houseText.setString("House");
    houseText.setCharacterSize(20);
    houseText.setFillColor(sf::Color::Yellow);
    houseText.setPosition(340, 500);

    sf::Text roadText;
    roadText.setFont(font);
    roadText.setString("Road");
    roadText.setCharacterSize(20);
    roadText.setFillColor(sf::Color::Yellow);
    roadText.setPosition(465, 500);

    sf::Text policeText;
    policeText.setFont(font);
    policeText.setString("Police");
    policeText.setCharacterSize(20);
    policeText.setFillColor(sf::Color::Yellow);
    policeText.setPosition(565, 500);

    buttonTexts.push_back(factoryText);
    buttonTexts.push_back(roadText);
    buttonTexts.push_back(houseText);
    buttonTexts.push_back(policeText);

    buttons.push_back(factoryButton);
    buttons.push_back(houseButton);
    buttons.push_back(roadButton);
    buttons.push_back(policeButton);
}

void UI::handleMouseClick(int mouseX, int mouseY) {
    if (mouseX >= 200 && mouseX <= 300 && mouseY >= 500 && mouseY <= 550) {
        selectedTileType = TileType::Factory;
    } else if (mouseX >= 320 && mouseX <= 420 && mouseY >= 500 && mouseY <= 550) {
        selectedTileType = TileType::House;
        //std::cout << "House button clicked" << std::endl;
    }
    else if (mouseX >= 440 && mouseX <= 540 && mouseY >= 500 && mouseY <= 550) {
        selectedTileType = TileType::Road;
    }

    else if (mouseX >= 550 && mouseX <= 650 && mouseY >= 500 && mouseY <= 550) {
        selectedTileType = TileType::PoliceDepartment;
    }
}

TileType UI::getSelectedTileType() {
    return selectedTileType;
}

std::string UI::getCityName() {
    sf::RenderWindow inputWindow(sf::VideoMode(800,600), "Enter city name");
    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/PixelifySans-Regular.ttf")) {
        throw fontError("../assets/fonts/PixelifySans-Regular.ttf");
    }

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
                throw windowClosed();
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
void UI::setFont(const sf::Font& newFont) {
    this->font = newFont;

    moneyText.setFont(font);
    materialText.setFont(font);

    for (auto& text : buttonTexts) {
        text.setFont(font);
    }
}