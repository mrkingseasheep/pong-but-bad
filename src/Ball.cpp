#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "Ball.hpp"

Ball::Ball(double rad) {
    xVel = 1;
    yVel = 1;
    rotVel = 5;
    speed = 5;
    radius = rad;
    if (!texture.loadFromFile(PLAYER_TEXTURE_FILE)) {
        std::cerr << "Image file not found" << std::endl;
    }
    texture.setSmooth(true);
    sprite.setRadius(radius);
    sprite.setOrigin(radius, radius);
    sprite.setTexture(&texture);
    center();
}

void Ball::set_speed(double sp) { speed = sp; }

void Ball::center() {
    sprite.setPosition(SCR_SZ_X / 2, SCR_SZ_Y / 2);
    std::cout << "Centered Ball" << std::endl;
}

void Ball::move() {
    double x = sprite.getPosition().x;
    double y = sprite.getPosition().y;
    if (x - radius < 0 || x + radius > SCR_SZ_X) {
        xVel *= -1;
    }
    if (y - radius < 0 || y + radius > SCR_SZ_Y) {
        yVel *= -1;
    }

    sprite.move(xVel * speed, yVel * speed);
    sprite.rotate(rotVel);
}
