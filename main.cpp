#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Classes/Buildings.h"
#include "Classes/Resources.h"
#include "Classes/City.h"
#include "Classes/UI.h"
#include "Classes/Map.h"
#include "Classes/TileType.h"
int main() {
    /*std::string cityName;
    std::cout<<"Introduce your city name: ";
    std::getline(std::cin,cityName);
    City myCity(cityName);
    std::cout<<"Welcome in "<<cityName<<" town"<<std::endl;
    std::cout<<"Your budget is currently "<<myCity.getResources().getMoney()<<"$"<<std::endl;
    std::cout<<"You have "<<myCity.getResources().getMaterials()<<" materials"<<std::endl;

    bool firstBuilding = true;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\n=== MENU ===" << std::endl;
        if (firstBuilding) {
             std::cout<<"In order to do that you'll have to buy some materials"<<std::endl;
        }

        std::cout << "1. Buy materials" << std::endl;
        std::cout << "2. Build" << std::endl;
        std::cout << "3. Show city info" << std::endl;
        std::cout << "4. Show maintenace"<<std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;

        switch (choice) {
            case 1:
                //std::cout<<"In order to buy materials you need 100$"<<std::endl;
                    //std::cout<<"You have "<<myCity.getResources().getMoney()<<"$"<<std::endl;
                        if (myCity.getResources().getMoney() >= 100) {
                            myCity.getResources().consumeResources(100,0);
                            myCity.getResources().setMaterials(myCity.getResources().getMaterials()+100);
                            std::cout<<"You bought 100 materials";
                        }
                        else {
                            std::cout<<"You don't have enough money";
                        }
                break;
            case 2: {
                std::cout << "1. House ($100, 50 materials)\n"
                          << "2. Factory ($200, 100 materials)\n"
                          << "0. Back\n"
                          << "Enter your choice: ";
                int buildingChoice;
                std::cin >> buildingChoice;
                if (buildingChoice == 1 || buildingChoice == 2) {
                        Buildings* newBuilding = (buildingChoice == 1)
                                                ? new Buildings("house", 10, 100, 50)
                                                : new Buildings("factory", 200, 200, 100);

                    bool success = myCity.addBuilding(newBuilding);
                    if (success && firstBuilding && buildingChoice == 1) {
                        firstBuilding = false;
                        std::cout << "Congratulations! You built your first house.\n";
                    }
                } else if (buildingChoice != 0) {
                    std::cout << "Invalid option.\n";
                }
                break;
            }
            case 3:
                myCity.displayCityInfo();
                break;
            case 4:
                std::cout << "Building Maintenance Costs:" << std::endl;
                for (const auto* building : myCity.getBuildings()) {
                    building->showMaintenance();
                }
                break;
            case 0:
                std::cout<<"Goodbye! Thank you for playing the game"<<std::endl;
                gameRunning = false;
                break;
            default:
                std::cout<<"Invalid choice"<<std::endl;
                }
            }*/
    sf::RenderWindow window(sf::VideoMode(800,600), "PixelTown");
    UI ui;
    Map map;
    Resources rm(1000, 500);
    ui.initialize();
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
                if (y >= 10 && y <= 60 && x >= 10 && x <= 220) {
                    ui.handleMouseClick(x, y);
                }
                else {
                    // When clicking on a tile, use the currently selected tile type.
                    map.handleClick(x, y, ui.getSelectedTileType());
                }
                }
        }
        ui.update(window,rm.getMoney(), rm.getMaterials());
        window.clear();
        map.render(window);
        ui.render(window);
        window.display();
    }
    return 0;
}
