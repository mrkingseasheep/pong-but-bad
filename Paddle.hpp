#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

class Paddle : public sf::Sprite {
  private:
    double height;
    double width;
    double xPos;
    double speed;

  public:
    Paddle(double, double);
    void player_move(int);
    bool at_edge(double);
    void bounce_move();
    void follow_move(double);
    void setSpeed(double);
};
