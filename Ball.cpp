#include "Ball.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

Ball::Ball() {
    xDir = 1;
    yDir = 1;
    speed = 5;
    rad = 225;
    setOrigin(rad, rad);
    scale = 0.15;
    setScale(scale, scale);
    rad *= scale;
    rotSpeed = 5;
    center();
}

void Ball::follow_trajectory() {
    double x = getPosition().x;
    double y = getPosition().y;

    if (x - rad < 0 || x + rad > SCREEN_WIDTH) {
        xDir *= -1;
    }
    if (y - rad < 0 || y + rad > SCREEN_HEIGHT) {
        yDir *= -1;
    }

    move(xDir * speed, yDir * speed);
    rotate(rotSpeed);
}

void Ball::center() { setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); }
