#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "GameManager.hpp"

double lineWidth = 5;

// WHY DO YOU HAVE TO DO THIS CANT YOU DO TI IN THE HeADER
// OATHSNUTHNHOEUNTEOHUtnh its been half an hour to find this lmaooo
GameManager::GameManager()
    : ball(25), divLine(sf::Vector2f(lineWidth, SCR_SZ_Y)) {
    ball.set_speed(3);

    divLine.setOrigin(lineWidth / 2, SCR_SZ_Y / 2);
    divLine.setPosition(SCR_SZ_X / 2, SCR_SZ_Y / 2);
}

void GameManager::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(divLine);
    window.draw(ball.sprite);
    ball.move();
    window.display();
}
