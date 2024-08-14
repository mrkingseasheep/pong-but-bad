#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ball.hpp"
#include "game.hpp"

Game::Game() {}

void Game::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(ball.shape);
    ball.move();
    window.display();
}
