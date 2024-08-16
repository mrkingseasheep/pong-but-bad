#include "Paddle.hpp"
#include "Ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Paddle::Paddle(double startingX) {
    movSpeed = 3;
    x = startingX;
    y = SCR_SZ_Y / 2;
    width = 10;
    height = 50;
    sprite.setSize(sf::Vector2f(width, height));
    /*sprite.setFillColor(sf::Color(255, 255, 255));*/
    sprite.setPosition(x, y);
    /*sprite.setOrigin(x, y);*/
}

// dir has to be 1 or -1
void Paddle::move(int dir) {
    movSpeed *= dir;
    double nxtY = y + movSpeed;
    if (at_edge(nxtY)) {
        return;
    }

    y = nxtY;
    sprite.setPosition(x, y);
}

void Paddle::bounce() {
    double nxtY = y + movSpeed;
    if (at_edge(nxtY)) {
        movSpeed *= -1;
        nxtY = y + movSpeed;
    }

    y = nxtY;
    sprite.setPosition(x, y);
}

bool Paddle::at_edge(int nxtY) {
    if (nxtY - height / 2 < 0 || nxtY + height / 2 > SCR_SZ_Y) {
        return true;
    }
    return false;
}

bool Paddle::ball_touching(double ballX, double ballY, double radius) {
    bool overMidLine = ballX > SCR_SZ_X / 2;
    bool forwardPaddle = (ballX + radius > x) == overMidLine;
    bool behindPaddle = (ballX - radius < x) == !overMidLine;
    bool goodSpot = forwardPaddle != behindPaddle;
    double halfBoard = height / 2;
    bool withinPaddle = ballY < y + halfBoard && ballY > y - halfBoard;

    if (goodSpot) {
        std::cout << "behind paddle" << std::endl;
        std::cout << SCR_SZ_X / 2 << ":" << ballX << ":" << x << std::endl;
    }
    /*if (withinPaddle) {*/
    /*    std::cout << "in paddle" << std::endl;*/
    /*}*/
    return (goodSpot && withinPaddle);
}
