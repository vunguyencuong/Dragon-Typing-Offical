#include "GameScore.h"
#include"Typing.h"
#include"string"
#include"iostream"
#include"string"
#include"fstream"

GameScore::GameScore()
{

    font.loadFromFile("./resources/Inter-Medium.ttf");
    text.setFont(font);
    text.setCharacterSize(50);

    results = 0;
}

void GameScore::saveScore()
{
    int highS = getHighScore();
    std::cout << highS << " " << results << std::endl;

    std::ofstream writeFile("./resources/HighScore.txt");
    if (writeFile.is_open())
    {

        if (results > highS)
        {
            highS = results;
        }
        writeFile << highS;
    }
    writeFile.close();
}

void GameScore::render(sf::RenderWindow* window)
{
    std::string score = std::to_string(results);

    text.setString(score);

    window->draw(text);
}

void GameScore::notify(Publisher* publisher)
{
    results = ((Typing*)publisher)->getResults();
}

int GameScore::getResults()
{
    return results;
}


int GameScore::getHighScore()
{
    int highScore = 0;

    std::ifstream readFile;
    readFile.open("./resources/HighScore.txt");

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> highScore;
        }
    }
    else
    {
        std::cout << "Error while open file" << std::endl;
    }
    readFile.close();

    return highScore;
}