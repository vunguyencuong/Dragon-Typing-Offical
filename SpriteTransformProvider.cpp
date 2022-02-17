#include "SpriteTransformProvider.h"

SpriteTransformProvider::SpriteTransformProvider()
{
    flySlow = vector<sf::IntRect>(3);
    flyNormal = vector<sf::IntRect>(3);
    flyFast = vector<sf::IntRect>(3);
    flyFail = vector<sf::IntRect>(3);

    for (int i = 0; i < flySlow.size(); i++) {
        flySlow[i] = sf::IntRect(i * 400, 0, 400, 400);
    }

    for (int i = 0; i < flyNormal.size(); i++) {
        flyNormal[i] = sf::IntRect(1200 + i * 400, 0, 400, 400);
    }

    for (int i = 0; i < flyFast.size(); i++) {
        flyFast[i] = sf::IntRect(i * 800, 400, 800, 400);
    }

    for (int i = 0; i < flyFail.size(); i++) {
        flyFail[i] = sf::IntRect(i * 400, 800, 400, 400);
    }
}

SpriteTransformProvider* SpriteTransformProvider::instance = nullptr;

SpriteTransformProvider* SpriteTransformProvider::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SpriteTransformProvider();
    }

    return instance;
}