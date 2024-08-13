#pragma once
#include <SFML/Graphics/CircleShape.hpp>

class Ball {
  public:
    sf::CircleShape shape;
    Ball();
    void center();
    void move();
};
