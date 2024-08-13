#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ball.hpp"

class Game {
  public:
    Ball ball;

    Game() {}

    void render(sf::RenderWindow& window) {
        window.clear();
        window.draw(ball.shape);
        ball.move();
        window.display();
    }
};
