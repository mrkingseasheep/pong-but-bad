#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"

class GameManager {
  private:
    Ball ball;
    sf::RectangleShape divLine;
    Paddle player;
    Paddle cpu;

  public:
    GameManager();

    void render(sf::RenderWindow&);
};
