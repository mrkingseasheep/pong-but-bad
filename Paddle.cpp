#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "Ball.hpp"
#include "Paddle.hpp"

Paddle::Paddle(double xPos, double speed) : speed(speed) {
    height = 55;
    width = 10;
    /*speed = 4;*/
    double sideLen = 32;
    setOrigin(sideLen / 2, sideLen / 2);
    setPosition(xPos, SCREEN_HEIGHT / 2);
    setScale(width / sideLen, height / sideLen);
}

void Paddle::player_move(int dir) {
    double nextMov = dir * speed;
    if (at_edge(nextMov)) {
        return;
    }
    move(0, nextMov);
}

// nextMove 0 to check if currently at edge
bool Paddle::at_edge(double nextMove) {
    double y = getPosition().y + nextMove;
    double halfHeight = height / 2;
    return y + halfHeight > SCREEN_HEIGHT || y - halfHeight < 0;
}

void Paddle::bounce_move() {
    move(0, speed);
    if (at_edge(0)) {
        std::cout << "AT EDGE" << std::endl;
        speed *= -1;
        while (at_edge(0)) {
            move(0, speed);
        }
    }
}

void Paddle::follow_move(double ballY) {
    double diff = ballY - getPosition().y;
    std::cout << diff << std::endl;
    double nextMov = std::min(std::abs(diff), std::abs(speed));
    if (diff < 0) {
        nextMov *= -1;
    }
    if (at_edge(nextMov)) {
        std::cout << "PADDLE AT EDGE" << std::endl;
        return;
    }
    move(0, nextMov);
}

void Paddle::setSpeed(double timeSecs) {
    double newSpeed = 4 + timeSecs / 10;
    (speed > 0) ? speed = newSpeed : speed = -newSpeed;
    /*std::cout << speed << std::endl;*/
}
