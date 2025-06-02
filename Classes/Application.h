#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "City.h"
#include "UI.h"
#include "Factory.h"
#include "Exceptions.h"
#include "Map.h"
#include <string>

#include "City.h"
#include "Resources.h"

class Application {
private:
    void processEvents();
    void update();
    void render();

    UI ui_;
    Resources resources_;
    City city_;
    sf::RenderWindow window_;
    Map map_;
    sf::Texture grassTexture_;
    sf::Sprite grassSprite_;
    sf::View view_;
    Factory factory_;
public:
    Application();
    int run();

};



#endif //APPLICATION_H
