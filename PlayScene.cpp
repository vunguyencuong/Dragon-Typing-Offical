#include "PlayScene.h"
#include "BackGround.h"
#include "Dragon.h"
#include "Typing.h"
#include"GameScore.h"
#include "PassageProvider.h"
#include "Game.h"
#include "EndScene.h"

PlayScene::PlayScene()
{
	BackGround* bkg = new BackGround();
	Dragon* dragon = new Dragon();
	Typing* typing = new Typing(PassageProvider::getInstance()->random(), "./resources/Inter-Medium.ttf", 25);
	GameScore* score = new GameScore();

	typing->addSubscriber((Subscriber*)dragon);
	typing->addSubscriber((Subscriber*)score);

	objects.push_back(bkg);
	objects.push_back(dragon);
	objects.push_back(typing);
	objects.push_back(score);
}

void PlayScene::update()
{
	for (int i = 0; i < objects.size(); i++)
		objects[i]->update();

	if (getObject<Dragon>()->isDead())
	{
		Game::instance()->setScene(new EndScene(getObject<GameScore>()));
	}

	if (getObject<Typing>()->checkEnd())
	{
		Game::instance()->setScene(new EndScene(getObject<GameScore>()));
	}
}

void PlayScene::onEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		getObject<Typing>()->onKeyPressed(event);
		getObject<Typing>()->update();
	}

}

void PlayScene::render(sf::RenderWindow* window)
{
	for (int i = 0; i < objects.size(); i++)
		objects[i]->render(window);
}

void PlayScene::clear()
{
	objects.clear();
}
