#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "ball.hpp"

extern const std::string PLAYER_TEXTURE_FILE;
extern const double SCR_SZ_X;
extern const double SCR_SZ_Y;

Ball::Ball() {
    if (!playerTexture.loadFromFile(PLAYER_TEXTURE_FILE)) {
        std::cerr << "unable to load texture" << std::endl;
    }
    playerTexture.setSmooth(true);
    shape.setOrigin(radius, radius);
    shape.setRadius(radius);
    shape.setTexture(&playerTexture);
    center();
}

void Ball::center() { shape.setPosition(SCR_SZ_X / 2, SCR_SZ_Y / 2); }

void Ball::move() {
    double curX = shape.getPosition().x;
    double curY = shape.getPosition().y;

    if (curY - radius < 0 || curY + radius > SCR_SZ_Y) {
        yVel *= -1;
    }
    if (curX - radius < 0 || curX + radius > SCR_SZ_X) {
        xVel *= -1;
    }

    shape.move(xVel * speed, yVel * speed);
    shape.rotate(rotSpeed);
}
