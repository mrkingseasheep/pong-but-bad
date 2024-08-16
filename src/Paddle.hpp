#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Paddle {
  private:
    double width;
    double height;
    double x;
    double y;
    double movSpeed;

  public:
    /*sf::Texture texture;*/
    sf::RectangleShape sprite;

    Paddle(double);

    void move(int);
    void bounce();
    void follow_ball();
    bool at_edge(int);
    bool ball_touching(double, double, double);
};
