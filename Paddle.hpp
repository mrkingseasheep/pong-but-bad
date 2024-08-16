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

  public:
    Paddle(int);
    void player_move(int);
};
