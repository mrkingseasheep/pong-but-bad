#include <SFML/Graphics/Sprite.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

class Powerup : public sf::Sprite {
  public:
    Powerup();

    void goToRandomPlace();
};
