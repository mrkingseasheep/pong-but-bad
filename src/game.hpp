#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "ball.hpp"

class Game {
  public:
    Ball ball;
    Game();

    void render(sf::RenderWindow& window);
};
