#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.hpp"

class GameManager {
  public:
    Ball ball;
    sf::RectangleShape divLine;

    GameManager();

    void render(sf::RenderWindow&);
};
