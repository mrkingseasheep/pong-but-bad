#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

extern const std::string PLAYER_TEXTURE_FILE = "obama.jpg";
extern const double SCR_SZ_X = 800;
extern const double SCR_SZ_Y = 600;

class Ball {
  public:
    double xVel = 1;
    double yVel = 1;
    double speed = 5;
    double rotSpeed = 5;
    double radius = 25;
    sf::CircleShape shape;
    sf::Texture playerTexture;

    Ball() {}

    Ball(double rad) : radius(rad) {
        if (!playerTexture.loadFromFile(PLAYER_TEXTURE_FILE)) {
            std::cerr << "unable to load texture" << std::endl;
        }
        playerTexture.setSmooth(true);
        shape.setOrigin(radius, radius);
        shape.setRadius(radius);
        shape.setTexture(&playerTexture);
        center();
    }

    void center() { shape.setPosition(SCR_SZ_X / 2, SCR_SZ_Y / 2); }

    void move() {
        double curX = shape.getPosition().x;
        double curY = shape.getPosition().y;

        if (curY - radius < 0 || curY + radius > SCR_SZ_Y) {
            bounceTopBottom();
        }
        if (curX - radius < 0 || curX + radius > SCR_SZ_X) {
            bounceLeftRight();
        }

        shape.move(xVel * speed, yVel * speed);
        shape.rotate(rotSpeed);
    }

    void bounceTopBottom() { yVel *= -1; }
    void bounceLeftRight() { xVel *= -1; }
};

class Game {
    Ball ball;

  public:
    Game() { ball = Ball(25); }

    void render(sf::RenderWindow& window) {
        window.clear();
        window.draw(ball.shape);
        ball.move();
        window.display();
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(SCR_SZ_X, SCR_SZ_Y), "Hi");
    window.setFramerateLimit(60);

    /*Ball ball = Ball(25);*/
    Game pong;

    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                running = false;
                break;
            case sf::Event::Resized:
                std::cout << "w: " << event.size.width << std::endl;
                std::cout << "h: " << event.size.height << std::endl;
                // was there a resize func here?
                // oh it was the opengl one, no need here
            default:
                break;
            }
        }
        pong.render(window);
    }

    return 0;
}
