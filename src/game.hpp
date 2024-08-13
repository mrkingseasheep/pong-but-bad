#pragma once

#include "ball.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
  public:
    Ball ball;
    /*Game();*/
    void render(sf::RenderWindow&);
};
