#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class Ball {
  private:
    double xVel = 1;
    double yVel = 1;
    double speed = 5;
    double rotSpeed = 5;
    double radius = 25;
    sf::Texture playerTexture;

  public:
    sf::CircleShape shape;

    Ball();
    void center();
    void move();
};
