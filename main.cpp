#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Hello World!",
                            sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    // window.setFramerateLimit(60); // use this or the one above, not at same
    // time
    sf::CircleShape shape(10);
    shape.setFillColor(sf::Color::Red);
    glEnable(GL_TEXTURE_2D);
    window.setActive();

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("obama.jpg")) {
        std::cerr << "bro tf did you do" << std::endl;
    }
    playerTexture.setSmooth(true);
    sf::Sprite player;
    player.setTexture(playerTexture);

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
        window.draw(player);
        window.draw(shape);
        window.display();
    }

    return 0;
}
