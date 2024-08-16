#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <string>

#include "Ball.hpp"
#include "Paddle.hpp"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

void textureLoad(sf::Texture& texture, const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << filepath << " : NOT LOADED" << std::endl;
    }
    texture.setSmooth(true);
}

int main() {
#define Key sf::Keyboard

    const std::string OBAMA_IMG_FILEPATH = "img/obama.png";
    const std::string MONKEY_IMG_FILEPATH = "img/monkey.jpg";
    const std::string SOLID_IMG_FILEPATH = "img/solidColor.jpg";
    const int DIST_FROM_SIDE = 25;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    window.setFramerateLimit(60);

    sf::Texture obama;
    textureLoad(obama, OBAMA_IMG_FILEPATH);
    sf::Texture monkey;
    textureLoad(monkey, MONKEY_IMG_FILEPATH);
    sf::Texture pureColor;
    textureLoad(pureColor, SOLID_IMG_FILEPATH);

    sf::RectangleShape bg(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    bg.setFillColor(sf::Color(100, 0, 100));
    Ball ball;
    ball.setTexture(obama);
    Paddle player(DIST_FROM_SIDE);
    player.setTexture(pureColor);
    Paddle cpu(SCREEN_WIDTH - DIST_FROM_SIDE);
    cpu.setTexture(pureColor);

    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        sf::FloatRect ballBox = ball.getGlobalBounds();
        sf::FloatRect playerBox = player.getGlobalBounds();
        sf::FloatRect cpuBox = cpu.getGlobalBounds();

        if (ballBox.intersects(playerBox)) {
            ball.bounce(playerBox);
        }
        if (ballBox.intersects(cpuBox)) {
            ball.bounce(cpuBox);
        }

        if (Key::isKeyPressed(Key::Up)) {
            player.player_move(-1);
        }
        if (Key::isKeyPressed(Key::Down)) {
            player.player_move(1);
        }

        // make it move faster with difficulty
        // smarter moves as your score gets higher
        /*cpu.bounce_move();*/
        cpu.follow_move(ball.getPosition().y);

        // uses sprite inheritence now instead of custom func
        // much easier to read
        window.clear();
        ball.follow_trajectory();
        window.draw(bg);
        window.draw(ball);
        window.draw(player);
        window.draw(cpu);
        window.display();
    }
}
