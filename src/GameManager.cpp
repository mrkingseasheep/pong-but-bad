#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.hpp"
#include "GameManager.hpp"

// WHY DO YOU HAVE TO DO THIS CANT YOU DO TI IN THE HeADER
// OATHSNUTHNHOEUNTEOHUtnh its been half an hour to find this lmaooo
GameManager::GameManager() : ball(25) { ball = Ball(24); }

void draw(sf::RenderWindow& window) {
    window.clear();
    window.draw(ball.sprite);
    ball.move();
    window.display();
}
