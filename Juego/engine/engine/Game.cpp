#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "ObstaculoCubo.h"
#include "ObstaculoEsfera.h"
#include "PowerUp.h"
#include "Model.h"
#include "RaceScene.h"

void Game::Create() 
{
	RaceScene* mainScene = new(nothrow) RaceScene();
	this->scenes.push_back(mainScene);
	this->activeScene = mainScene;
}

void Game::Render() 
{
	this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}

void Game::ProcessKeyPressed(const unsigned char& key, const int& xPosition, const int& yPosition)
{
	this->activeScene->ProcessKeyPressed(key, xPosition, yPosition);

	switch (key) {
	case 'm':
	case 'M':
		this->activeScene->ClearScene(); //Reiniciar nivel
		this->Create();
		break;
	}
}

void Game::ProcessMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition) 
{
}

void Game::ProcessMouseMovement(const int& xPosition, const int& yPosition)
{
}

