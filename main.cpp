#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <string>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Powerup.hpp"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

void textureLoad(sf::Texture& texture, const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << filepath << " : IMAGE NOT LOADED" << std::endl;
    }
    texture.setSmooth(true);
}

void soundLoad(sf::SoundBuffer& sound, const std::string& filepath) {
    if (!sound.loadFromFile(filepath)) {
        std::cerr << filepath << " : SOUND NOT LOADED" << std::endl;
    }
}

void fontLoad(sf::Font& font, const std::string& filepath) {
    if (!font.loadFromFile(filepath)) {
        std::cerr << filepath << " : FONT NOT LOADED" << std::endl;
    }
}

int main() {
#define Key sf::Keyboard
    const std::string OBAMA_IMG_FILEPATH = "img/obama.png";
    const std::string MONKEY_IMG_FILEPATH = "img/monkey.jpg";
    const std::string SOLID_IMG_FILEPATH = "img/solidColor.jpg";
    const std::string WIN_SOUND_FILEPATH = "sfx/soda.wav";
    const std::string WOMP_SOUND_FILEPATH = "sfx/obamna.wav";
    const std::string LOSE_SOUND_FILEPATH = "sfx/pipe.wav";
    const std::string FONT_FILEPATH = "fonts/Minecraft.ttf";

    const int DIST_FROM_SIDE = 25;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    window.setFramerateLimit(60);

    sf::Texture obama;
    textureLoad(obama, OBAMA_IMG_FILEPATH);
    sf::Texture monkey;
    textureLoad(monkey, MONKEY_IMG_FILEPATH);
    sf::Texture pureColor;
    textureLoad(pureColor, SOLID_IMG_FILEPATH);

    sf::RectangleShape bg(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    bg.setFillColor(sf::Color(100, 0, 100));
    Ball ball;
    ball.setTexture(obama);
    Paddle player(DIST_FROM_SIDE, 4);
    player.setTexture(pureColor);
    Paddle cpu(SCREEN_WIDTH - DIST_FROM_SIDE, 5);
    cpu.setTexture(pureColor);
    sf::RectangleShape playerGoal(sf::Vector2f(2, SCREEN_HEIGHT));
    playerGoal.setPosition(0, 0);
    sf::RectangleShape cpuGoal(sf::Vector2f(2, SCREEN_HEIGHT));
    cpuGoal.setPosition(SCREEN_WIDTH - 2, 0);
    sf::RectangleShape line(sf::Vector2f(5, SCREEN_HEIGHT));
    line.setPosition(SCREEN_WIDTH / 2, 0);
    Powerup decreaseBallSize;
    decreaseBallSize.setTexture(monkey);
    Powerup increasePaddleSize;
    increasePaddleSize.setTexture(monkey);

    sf::SoundBuffer womp;
    soundLoad(womp, WOMP_SOUND_FILEPATH);
    sf::Sound hit;
    hit.setBuffer(womp);
    hit.setVolume(50);
    sf::SoundBuffer win;
    soundLoad(win, WIN_SOUND_FILEPATH);
    sf::Sound winner;
    winner.setBuffer(win);
    sf::SoundBuffer lose;
    soundLoad(lose, LOSE_SOUND_FILEPATH);
    sf::Sound loser;
    loser.setBuffer(lose);

    /// REMOVE IN FINAL PROJECT
    /// the noise is too loud augh
    /*hit.setVolume(0);*/
    /*winner.setVolume(0);*/
    /*loser.setVolume(0);*/

    const int SCORE_PADDING = 50;
    sf::Font font;
    fontLoad(font, FONT_FILEPATH);
    sf::Text p1score;
    p1score.setFont(font);
    p1score.setFillColor(sf::Color(255, 255, 255));
    p1score.setPosition(SCORE_PADDING, SCORE_PADDING / 2);

    sf::Text p2score;
    p2score.setFont(font);
    p2score.setFillColor(sf::Color(255, 255, 255));
    p2score.setPosition(SCREEN_WIDTH - SCORE_PADDING, SCORE_PADDING / 2);

    int score = 0;
    int cpuScore = 0;
    sf::Clock clock;

    enum sizePowerUp {
        notSeen,
        present,
        activated,
    };
    sizePowerUp status;
    status = notSeen;

    bool running = true;
    while (running) {
        sf::Time timePassed = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        ball.follow_trajectory();

        sf::FloatRect ballBox = ball.getGlobalBounds();
        sf::FloatRect playerBox = player.getGlobalBounds();
        sf::FloatRect cpuBox = cpu.getGlobalBounds();
        sf::FloatRect playerGoalBox = playerGoal.getGlobalBounds();
        sf::FloatRect cpuGoalBox = cpuGoal.getGlobalBounds();
        sf::FloatRect powerupBox = decreaseBallSize.getGlobalBounds();

        if (ballBox.intersects(powerupBox) && status == present) {
            status = activated;
            ball.powerup(0.06);
        }

        if (ballBox.intersects(playerGoalBox)) {
            ++cpuScore;
            clock.restart();
            ball.center();
            loser.play();
            std::cout << "Player: " << score << std::endl;
            std::cout << "   CPU: " << cpuScore << std::endl;
        }
        if (ballBox.intersects(cpuGoalBox)) {
            ++score;
            clock.restart();
            ball.center();
            winner.play();
            std::cout << "Player: " << score << std::endl;
            std::cout << "   CPU: " << cpuScore << std::endl;
        }

        if (ballBox.intersects(playerBox)) {
            ball.bounce(playerBox);
            hit.play();
        }
        if (ballBox.intersects(cpuBox)) {
            ball.bounce(cpuBox);
            hit.play();
        }

        if (Key::isKeyPressed(Key::Up)) {
            player.player_move(-1);
        }
        if (Key::isKeyPressed(Key::Down)) {
            player.player_move(1);
        }

        // make it move faster with difficulty
        // smarter moves as your score gets higher
        if (score > 0) {
            cpu.follow_move(ball.getPosition().y);
        } else {
            cpu.bounce_move();
        }

        p1score.setString(std::to_string(score));
        p2score.setString(std::to_string(cpuScore));

        // uses sprite inheritence now instead of custom func
        // much easier to read
        window.clear();
        window.draw(bg);
        window.draw(line);
        window.draw(p1score);
        window.draw(p2score);
        if (status == notSeen && timePassed.asSeconds() > 5) {
            status = present;
            decreaseBallSize.goToRandomPlace();
            decreaseBallSize.goToRandomPlace();
            decreaseBallSize.goToRandomPlace();
            decreaseBallSize.goToRandomPlace();
        } else if (status == present) {
            window.draw(decreaseBallSize);
        }
        window.draw(ball);
        window.draw(player);
        window.draw(cpu);
        window.display();

        /*std::cout << "CHANGING SPEEDS" << std::endl;*/
        ball.setSpeed(timePassed.asSeconds());
        ball.setSize(timePassed.asSeconds());
        cpu.setSpeed(timePassed.asSeconds());
        player.setSpeed(timePassed.asSeconds());
    }
}
