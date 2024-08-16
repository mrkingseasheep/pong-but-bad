#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

class Ball : public sf::Sprite {
  private:
    double xDir;
    double yDir;
    double speed;
    double rotSpeed;
    double rad;
    double scale;

  public:
    Ball();

    void bounce(sf::FloatRect&);
    void follow_trajectory();
    void center();
    void setSpeed(double);
    void setSize(double);
};
