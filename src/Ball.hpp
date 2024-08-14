#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

extern const std::string PLAYER_TEXTURE_FILE;
extern double SCR_SZ_X;
extern double SCR_SZ_Y;

class Ball {
    sf::Texture texture;
    double radius;
    double xVel;
    double yVel;
    double rotVel;
    double speed;

  public:
    sf::CircleShape sprite;

    Ball(double);

    void move();

    void set_speed(double);

    void center();
};
