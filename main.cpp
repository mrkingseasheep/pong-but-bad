#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <string>

#include "Ball.hpp"

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

    Ball ball(obama);

    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        window.clear();
        ball.follow_trajectory();
        ball.draw_ball(window);
        window.display();
    }
}
