#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

extern const std::string PLAYER_TEXTURE_FILE;
extern const double SCR_SZ_X;
extern const double SCR_SZ_Y;

class Ball {
  private:
    double xVel = 1;
    double yVel = 1;
    double speed = 5;
    double rotSpeed = 5;
    double radius = 25;
    sf::Texture playerTexture;

  public:
    sf::CircleShape shape;

    Ball() {
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
            yVel *= -1;
        }
        if (curX - radius < 0 || curX + radius > SCR_SZ_X) {
            xVel *= -1;
        }

        shape.move(xVel * speed, yVel * speed);
        shape.rotate(rotSpeed);
    }
};
