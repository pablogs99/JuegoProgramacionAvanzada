#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Player.h"
#include "ObstaculoCubo.h"
#include "ObstaculoEsfera.h"
#include "PowerUp.h"
#include "Model.h"
#include "RaceScene.h"

void Game::Create() 
{
	RaceScene* mainScene = new(nothrow) RaceScene();
	//CamaraFija mainCamera = mainScene->GetCamera();
	//mainCamera.SetPosition(Vector3D(5.0f, 10.0f, 20.0f)); //posicion camara fija

	//mainCamera.SetOrientation(Vector3D(20.0f, 0.0f, 0.0f));
	//mainScene->SetCamera(mainCamera);
	//mainCamera.SetSpeed(Vector3D(0.0f, .0f, -0.7f)); 

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

void Game::ProcessMouseMovement(const int& xPosition, const int& yPosition) 
{
	//this->activeScene->ProcessMouseMovement(xPosition, yPosition);
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
	//this->activeScene->ProcessMouseClick(button, state, xPosition, yPosition);
}
