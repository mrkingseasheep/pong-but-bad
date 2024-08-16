#pragma once

#include "Paddle.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

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

    void bounceOffPaddle(std::vector<Paddle>&, sf::RenderWindow&);
};
