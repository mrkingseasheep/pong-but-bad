#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <vector>

#include "Ball.hpp"
#include "Paddle.hpp"

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

void Ball::bounceOffPaddle(std::vector<Paddle>& solidObjs,
                           sf::RenderWindow& window) {
    sf::FloatRect ballBoundBox = sprite.getGlobalBounds();
    for (Paddle solid : solidObjs) {
        sf::FloatRect paddleBoundBox = solid.sprite.getGlobalBounds();

        // debug shapes
        sf::RectangleShape hitbox(
            sf::Vector2f(paddleBoundBox.width, paddleBoundBox.height));
        hitbox.setPosition(paddleBoundBox.left, paddleBoundBox.top);
        hitbox.setOutlineThickness(10);
        hitbox.setOutlineColor(sf::Color(255, 0, 0));
        /*window.draw(hitbox);*/

        /*if (ballBoundBox.intersects(paddleBoundBox)) {*/
        if (solid.ball_touching(sprite.getPosition().x, sprite.getPosition().y,
                                radius)) {
            xVel *= -1;
            sprite.move(xVel * speed, 0);
            std::cout << "BOUNCE" << xVel << std::endl;
            return;
        }
    }
}
