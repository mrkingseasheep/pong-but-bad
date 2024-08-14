#include "Paddle.hpp"
#include "Ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

Paddle::Paddle(double startingX) {
    movSpeed = 3;
    x = startingX;
    y = SCR_SZ_Y / 2;
    sprite.setSize(sf::Vector2f(width, height));
    sprite.setFillColor(sf::Color(0, 0, 0));
    sprite.setPosition(x, y);
}

// dir has to be 1 or -1
void Paddle::move(int dir) {
    double nxtY = y + movSpeed * dir;
    if (nxtY - height / 2 < 0 || nxtY + height / 2 > SCR_SZ_Y) {
        return;
    }

    y = nxtY;

    sprite.setPosition(x, y);
}
