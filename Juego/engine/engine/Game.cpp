#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Cuboid.h"
#include "Player.h"

void Game::Create() 
{
	Scene* mainScene = new(nothrow) Scene();
	FlyingCamera mainCamera = mainScene->GetCamera();
	mainCamera.SetPosition(Vector3D(5.0f, 10.0f, 20.0f)); //posicion camara fija

	mainCamera.SetOrientation(Vector3D(20.0f, 0.0f, 0.0f));
	mainScene->SetCamera(mainCamera);
	mainCamera.SetSpeed(Vector3D(0.0f, .0f, -0.7f)); //posicion camara fija

	//obstaculos
	int numCubos = 5; // Son 4 en realidad porque index empieza en 1
	Cube* pointerToCubes = new(nothrow) Cube[numCubos];
	if (pointerToCubes != nullptr) {
		for (int index = 1; index < numCubos; index++) {
			pointerToCubes[index] = Cube(
			
				Vector3D((rand() % 13), (0.5), -25),  //posición 
				Color(( index * 0.5), (index * 0.1), ( 0.1)), //color
				Vector3D((0.02 + index * 0.001), (0), (0.34 * index)),  //velocidad
				0.1 + 2 * 0.1 //orientacion
			); 
			pointerToCubes[index].SetIsAffectedByGravity(false);
			mainScene->AddGameObject(pointerToCubes + index);
		}
	}


	 //para posibles puntuaciones
	/*Torus* torus = new Torus();
	torus->SetPosition(Vector3D(2.0f, 3.0f, 1.0f));
	torus->SetColor(Color(0.8f, 0.9f, 0.8f));
	torus->SetOrientationSpeed(Vector3D(0.0f, 6.0f, 0.0f));
	torus->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(torus);*/

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

	Player* jugador = new Player();
	jugador->SetPosition(Vector3D(5.0f, 1.0f, 10.0f));
	jugador->SetColor(Color(1.0f, 30.0f, 1.0f));
	jugador->SetHeight(2.0f);
	jugador->SetLength(2.0f);
	jugador->SetWidth(2.0f);
	jugador->SetIsAffectedByGravity(false);
	//mainScene->AddGameObject(jugador);
	mainScene->setPlayer(*jugador);

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
}

void Game::ProcessMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition) 
{
	this->activeScene->ProcessMouseClick(button, state, xPosition, yPosition);
}
