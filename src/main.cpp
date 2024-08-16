#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

#include "GameManager.hpp"

const std::string PLAYER_TEXTURE_FILE = "img/obama.jpg";
double SCR_SZ_X = 800;
double SCR_SZ_Y = 600;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCR_SZ_X, SCR_SZ_Y), "Hi",
                            sf::Style::Default, settings);
    window.setFramerateLimit(60);

    GameManager pong;

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
