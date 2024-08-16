#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"

Paddle::Paddle(double xPos) {
    height = 55;
    width = 10;
    speed = 4;
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

    if (y + halfHeight > SCREEN_HEIGHT || y - halfHeight < 0) {
        return true;
    }
    return false;
}

void Paddle::bounce_move() {
    if (at_edge(speed)) {
        speed *= -1;
    }
    move(0, speed);
}

void Paddle::follow_move(double ballY) {
    double diff = ballY - getPosition().y;
    double nextMov = std::min(diff, speed);
    if (at_edge(nextMov)) {
        return;
    }
    move(0, nextMov);
}
