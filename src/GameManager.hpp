#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

#include "Ball.hpp"
#include "Paddle.hpp"

class GameManager {
  private:
    Ball ball;
    sf::RectangleShape divLine;
    Paddle player;
    Paddle cpu;
    std::vector<Paddle> solidObjs;

  public:
    GameManager();

    void render(sf::RenderWindow&);
};
