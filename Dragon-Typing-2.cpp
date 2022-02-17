#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    Game::instance()->setup(1000, 600, "Dragon Typing");

    Game::instance()->init();

    Game::instance()->setFrameRateLimit(60);

    Game::instance()->start();
}