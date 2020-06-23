#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Cuboid.h"
#include "Player.h"
#include "ObstaculoCubo.h"
#include "ObstaculoEsfera.h"
#include "PowerUp.h"

void Game::Create() 
{
	Scene* mainScene = new(nothrow) Scene();
	FlyingCamera mainCamera = mainScene->GetCamera();
	mainCamera.SetPosition(Vector3D(5.0f, 10.0f, 20.0f)); //posicion camara fija

	mainCamera.SetOrientation(Vector3D(20.0f, 0.0f, 0.0f));
	mainScene->SetCamera(mainCamera);
	mainCamera.SetSpeed(Vector3D(0.0f, .0f, -0.7f)); 

	//Jugador
	Player* jugador = new Player();
	jugador->SetPosition(Vector3D(5.0f, 1.0f, 10.0f));
	jugador->SetSpeed(Vector3D(0.45f, 0, 0));
	mainScene->setPlayer(*jugador);

	//obstaculos Cubos
	int numCubos = 3; // Son 4 en realidad porque index empieza en 1 para que la velocidad no sea 0
	ObstaculoCubo* pointerToCubes = new(nothrow) ObstaculoCubo[numCubos];
	if (pointerToCubes != nullptr) {
		for (int index = 1; index < numCubos; index++) {
			pointerToCubes[index] = ObstaculoCubo(
				Vector3D((rand() % 13), (0.5), -25),  //posición 
				Color((1), (1), (1)), //color
				Vector3D((0.07 + index * 0.001), (0), (0.6 * index)),  //velocidad 
				0.1 + 2 * 0.1 //orientacion
			);
			pointerToCubes[index].SetIsAffectedByGravity(false);
			mainScene->AddObstacle(pointerToCubes + index);
		}
	}
	//obstaculos Esferas
	int numEsferas = 3;
	ObstaculoEsfera* pointerToSpheres = new(nothrow) ObstaculoEsfera[numEsferas];
	if (pointerToSpheres != nullptr) {
		for (int index = 1; index < numEsferas; index++) {
			pointerToSpheres[index] = ObstaculoEsfera(
				Vector3D((rand() % 13), (0.8), -25),  //posición 
				Color((0.5), (0.5), (0.5)), 
				Vector3D((0.07 + index * 0.001), (0), (0.75 * index)),  //velocidad 
				0.1 + 2 * 0.1 //orientacion
			);
			pointerToSpheres[index].SetIsAffectedByGravity(false);
			mainScene->AddObstacle(pointerToSpheres + index);
		}
	}

	//Anillo
	PowerUp* powerUp = new PowerUp();
	powerUp->SetPosition(Vector3D(6.0f, -4.2f, -25.0f)); //y = 1.2
	powerUp->SetOrientationSpeed(Vector3D(0.0f, 20.0f, 0.0f));
	mainScene->setPower(powerUp);
	

	Cuboid* floor = new Cuboid();
	floor->SetPosition(Vector3D(5.0f, -0.5f, 5.0f));
	floor->SetColor(Color(0.4f, 0.4f, 0.4f));
	floor->SetHeight(1.0f);
	floor->SetLength(14.0f);
	floor->SetWidth(1000.0f);
	floor->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(floor);


	Cuboid* pianoIZq = new Cuboid();
	pianoIZq->SetPosition(Vector3D(-3.0f, -1.0f, 5.0f));
	pianoIZq->SetColor(Color(120.0f, 1.0f, 1.0f));
	pianoIZq->SetHeight(1.0f);
	pianoIZq->SetLength(1.0f);
	pianoIZq->SetWidth(1000.0f);
	pianoIZq->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(pianoIZq);

	Cuboid* pianoDer = new Cuboid();
	pianoDer->SetPosition(Vector3D(13.0f, -1.0f, 5.0f));
	pianoDer->SetColor(Color(120.0f, 1.0f, 1.0f));
	pianoDer->SetHeight(1.0f);
	pianoDer->SetLength(1.0f);
	pianoDer->SetWidth(1000.0f);
	pianoDer->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(pianoDer);

	this->scenes.push_back(mainScene);
	this->activeScene = mainScene;
}

void Game::Render() 
{
	this->activeScene->Render();
}

void Game::Update()
{
	this->activeScene->Update(this->deltaTime);
}

void Game::ProcessMouseMovement(const int& xPosition, const int& yPosition) 
{
	this->activeScene->ProcessMouseMovement(xPosition, yPosition);
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
	this->activeScene->ProcessMouseClick(button, state, xPosition, yPosition);
}
