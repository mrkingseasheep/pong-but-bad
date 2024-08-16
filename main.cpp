#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <string>

#include "Ball.hpp"
#include "Paddle.hpp"

int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 400;

int main() {
    const std::string OBAMA_IMG_FILEPATH = "img/obama.png";
    const std::string MONKEY_IMG_FILEPATH = "img/monkey.jpg";

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    window.setFramerateLimit(60);

    sf::Texture obama;
    if (!obama.loadFromFile(OBAMA_IMG_FILEPATH)) {
        std::cerr << "Obama not loaded" << std::endl;
    }
    obama.setSmooth(true);

    sf::Texture monkey;
    if (!monkey.loadFromFile(MONKEY_IMG_FILEPATH)) {
        std::cerr << "Monky not loaded" << std::endl;
    }
    monkey.setSmooth(true);

    Ball ball;
    ball.setTexture(obama);

    Paddle player(25);
    player.setTexture(monkey);

    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        // uses sprite inheritence now instead of custom func
        // much easier to read
        window.clear();
        ball.follow_trajectory();
        window.draw(ball);
        window.display();
    }
}
