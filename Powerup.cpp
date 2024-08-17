#include "Powerup.hpp"
#include "Ball.hpp"
#include <iostream>
#include <random>

Powerup::Powerup() { setScale(0.05, 0.05); }

int getRandNum(int a, int b) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a, b);

    std::cout << dist6(rng) << std::endl;
    return dist6(rng);
}

void Powerup::goToRandomPlace() {
    const double PADDING = 75;
    /*std::default_random_engine generator;*/
    /*std::uniform_real_distribution<double> heightDist(PADDING,*/
    /*                                                  SCREEN_HEIGHT -
     * PADDING);*/
    /*std::uniform_real_distribution<double> widthDist(PADDING,*/
    /*                                                 SCREEN_WIDTH -
     * PADDING);*/
    /*double x = widthDist(generator);*/
    /*double y = heightDist(generator);*/

    int x = getRandNum(PADDING, SCREEN_WIDTH - PADDING);
    int y = getRandNum(PADDING, SCREEN_HEIGHT - PADDING);
    std::cout << "=========================" << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << "=========================" << std::endl;
    setPosition(x, y);
}
