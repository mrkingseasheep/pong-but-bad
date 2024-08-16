#include "Ball.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

Ball::Ball() {
    xDir = 1;
    yDir = 1;
    speed = 5;
    sprite.setTexture(texture);
    rad = 225;
    sprite.setOrigin(rad, rad);
    scale = 0.15;
    sprite.setScale(scale, scale);
    rad *= scale;
    rotSpeed = 5;
    center();
}

void Ball::follow_trajectory() {
    double x = sprite.getPosition().x;
    double y = sprite.getPosition().y;

    if (x - rad < 0 || x + rad > SCREEN_WIDTH) {
        xDir *= -1;
    }
    if (y - rad < 0 || y + rad > SCREEN_HEIGHT) {
        yDir *= -1;
    }

    sprite.move(xDir * speed, yDir * speed);
    sprite.rotate(rotSpeed);
}

void Ball::draw_ball(sf::RenderWindow& window) { window.draw(sprite); }

void Ball::center() { sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); }
