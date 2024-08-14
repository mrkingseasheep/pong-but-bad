#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.hpp"

class GameManager {
  public:
    Ball ball;

    GameManager();

    void render(sf::RenderWindow&);
};
