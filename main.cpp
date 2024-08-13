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

/*
help im being jumped by lifetimes
i hate this
https://pvs-studio.com/en/blog/posts/cpp/1006/
const int& a = 0; // works
int& b = 0; dont work
first lifetime gets extended to end of {}
*/

// uses NRVO nvm doesnt work at all
// named return value optimization
// c++17+

// gosh damnitn why are lifetimes

// ight so we just shove it on nthe heap then :P 😔
sf::Sprite* newSprite(const std::string& fileTexture) {
    sf::Texture texture;
    if (!texture.loadFromFile(fileTexture)) {
        std::cerr << "uh ohhh stinky" << std::endl;
    }
    texture.setSmooth(true);
    sf::Sprite* sprite = new sf::Sprite(texture);
    return sprite;
}

const std::string PLAYER_TEXTURE_FILE = "obama.jpg";

class Ball {
  public:
    double xVel = 1;
    double yVel = 1;
    double speed = 5;
    sf::CircleShape shape;
    sf::Texture playerTexture;

    Ball(int radius) {
        if (!playerTexture.loadFromFile(PLAYER_TEXTURE_FILE)) {
            std::cerr << "unable to load texture" << std::endl;
        }
        playerTexture.setSmooth(true);
        shape.setRadius(radius);
        shape.setTexture(&playerTexture);
    }

    void bounceTopBottom() { yVel *= -1; }
    void bounceLeftRight() { xVel *= -1; }
};

int main() {

    sf::RenderWindow window(sf::VideoMode(600, 600), "Hello World!",
                            sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    // window.setFramerateLimit(60); // use this or the one above, not at same
    // time
    glEnable(GL_TEXTURE_2D);

    Ball ball = Ball(25);

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
                glViewport(0, 0, event.size.width, event.size.height);
            default:
                break;
            }
        }

        window.clear();
        window.draw(ball.shape);
        window.display();
    }

    return 0;
}
