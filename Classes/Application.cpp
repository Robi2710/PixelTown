#include "Application.h"
#include "AssetsManager.h"
#include <iostream>
#include <stdexcept>

Application::Application()
    : ui_(), resources_(1000, 500), city_("", 0, resources_),
      window_(sf::VideoMode(800, 600), ""), map_(),
      view_(window_.getDefaultView()),
      factory_("factory", 100, 200, 100, "product", 10, 50, 30) {
  std::string name = ui_.getCityName();
  if (name.empty()) {
    throw std::runtime_error("No city name provided. Exiting.");
  }
  city_ = City(name, 0, resources_);
  window_.setTitle(name);

  ui_.initialize();

  sf::Font &mainFont = fontManager_.getResource(
      "main", "../assets/fonts/PixelifySans-Regular.ttf");
  ui_.setFont(mainFont);

  sf::SoundBuffer &buildBuffer = soundBufferManager_.getResource(
      "build", "../assets/sounds/placeSound.mp3");
  buildSound_.setBuffer(buildBuffer);
  buildSound_.setVolume(100);

  sf::Texture &grassTexture =
      AssetsManager::getInstance().getTexture("../assets/textures/grass.png");
  grassSprite_.setTexture(grassTexture);

  map_.setApplication(this);
}

sf::Sound &Application::getBuildSound() { return buildSound_; }

int Application::run() {
  while (window_.isOpen()) {
    processEvents();
    update();
    render();
  }

  // clean up
  AssetsManager::getInstance().cleanup();
  fontManager_.clear();
  // soundManager_.clear();
  return 0;
}

void Application::processEvents() {
  sf::Event event;
  const float panSpeed = 10.f;
  while (window_.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      window_.close();
      break;
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::Left)
        view_.move(-panSpeed, 0);
      else if (event.key.code == sf::Keyboard::Right)
        view_.move(panSpeed, 0);
      else if (event.key.code == sf::Keyboard::Up)
        view_.move(0, -panSpeed);
      else if (event.key.code == sf::Keyboard::Down)
        view_.move(0, panSpeed);
      window_.setView(view_);
      break;
    case sf::Event::MouseButtonPressed:
      if (event.mouseButton.button == sf::Mouse::Left) {
        float x = static_cast<float>(event.mouseButton.x);
        float y = static_cast<float>(event.mouseButton.y);
        if (y >= 500 && y <= 550 && x >= 200 && x <= 665) {
          ui_.handleMouseClick(x, y);
        } else {
          map_.handleClick(x, y, ui_.getSelectedTileType(), &city_);
        }
      }
      break;
    default:
      break;
    }
  }
}

void Application::update() {
  city_.updateFactoriesHouse();
  ui_.update(city_.getResources().getMoney(),
             city_.getResources().getMaterials());
}

void Application::render() {
  window_.clear();
  window_.draw(grassSprite_);

  window_.setView(view_);
  map_.render(window_);

  window_.setView(window_.getDefaultView());
  ui_.render(window_);

  window_.display();
}
