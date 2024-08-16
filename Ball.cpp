#include "Ball.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <random>

Ball::Ball() {
    xDir = 1;
    yDir = 1;
    speed = 5;
    rad = 225;
    setOrigin(rad, rad);
    scale = 0.10;
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

void Ball::center() {
    setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.5, 1.5);
    std::cout << distribution(generator) << std::endl;
    xDir = distribution(generator);
    std::cout << xDir << std::endl;
    yDir = distribution(generator);
    std::cout << yDir << std::endl;
}

void Ball::bounce(sf::FloatRect& badBox) {
    xDir *= -1;
    while (getGlobalBounds().intersects(badBox)) {
        move(xDir * speed * 0.2, 0);
    }
    /*yDir *= -1;*/
}

void Ball::setSpeed(double timeSecs) {
    if (timeSecs < 1) {
        speed = 0;
        return;
    }
    if (timeSecs < 2) {
        speed = 5.0f / 2.0f * timeSecs;
        return;
    }
    speed = 5 + timeSecs / 5;
    rotSpeed = 5 + timeSecs / 10;
}

void Ball::setSize(double timeSecs) {
    double newScale = scale - timeSecs / 1000 / 2;
    setScale(newScale, newScale);
}
