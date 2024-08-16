#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Paddle : public sf::Sprite {
  private:
    double height;
    double width;
    double xPos;

  public:
    Paddle(sf::Texture&);
    void player_move(int);
};
