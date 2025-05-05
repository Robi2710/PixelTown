#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Classes/Resources.h"
#include "Classes/City.h"
#include "Classes/UI.h"
#include "Classes/Map.h"
#include "Classes/Exceptions.h"


int main() {
    UI ui;
    std::string name;
    try {
        name = ui.getCityName();
    } catch (const windowClosed& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    if(name.empty()){
        std::cout << "No city name provided. Exiting." << std::endl;
        return 0;
    }

    Resources rm(1000, 500);
    City myCity(name, 0, rm);
    sf::RenderWindow window(sf::VideoMode(800,600), name);
    Map map;
    try {
        ui.initialize();
    } catch (const fontError& e) {
        std::cerr << "Font loading error: " << e.what() << std::endl;
        return 1;
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;
                if (y >= 10 && y <= 60 && x >= 10 && x <= 330) {
                    ui.handleMouseClick(x, y);
                }
                else {
                    map.handleClick(x, y, ui.getSelectedTileType(), &myCity);
                }
                }
        }
        myCity.updateFactoriesHouse();
        ui.update(window,myCity.getResources().getMoney(), myCity.getResources().getMaterials());
        window.clear();
        map.render(window);
        ui.render(window);
        window.display();
    }
    return 0;
}
