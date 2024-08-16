#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

class Ball : public sf::Sprite {
  private:
    sf::Texture texture;
    int xDir;
    int yDir;
    double speed;
    double rotSpeed;
    sf::Sprite sprite;
    double rad;
    double scale;

  public:
    Ball(sf::Texture&);

    void bounce();
    void follow_trajectory();
    void center();
    void draw_ball(sf::RenderWindow&);
};
