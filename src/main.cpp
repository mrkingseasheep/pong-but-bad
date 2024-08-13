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

#include "game.hpp"

const std::string PLAYER_TEXTURE_FILE = "obama.jpg";
const double SCR_SZ_X = 800;
const double SCR_SZ_Y = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(SCR_SZ_X, SCR_SZ_Y), "Hi");
    window.setFramerateLimit(60);

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
