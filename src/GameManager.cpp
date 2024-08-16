#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Ball.hpp"
#include "GameManager.hpp"
#include "Paddle.hpp"

double lineWidth = 5;

// WHY DO YOU HAVE TO DO THIS CANT YOU DO TI IN THE HeADER
// OATHSNUTHNHOEUNTEOHUtnh its been half an hour to find this lmaooo
GameManager::GameManager()
    : ball(25), divLine(sf::Vector2f(lineWidth, SCR_SZ_Y)),
      player(SCR_SZ_X * 0.05), cpu(SCR_SZ_X * 0.95) {
    ball.set_speed(3);
    solidObjs.push_back(cpu);
    solidObjs.push_back(player);

    divLine.setOrigin(lineWidth / 2, SCR_SZ_Y / 2);
    divLine.setPosition(SCR_SZ_X / 2, SCR_SZ_Y / 2);
}

void GameManager::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(divLine);
    window.draw(ball.sprite);
    window.draw(player.sprite);
    window.draw(cpu.sprite);

    ball.bounceOffPaddle(solidObjs);
    player.move(1);
    cpu.bounce();
    ball.move();
    window.display();
}
