#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Cuboid.h"


void Game::Create() 
{
	Scene* mainScene = new(nothrow) Scene();
	FlyingCamera mainCamera = mainScene->GetCamera();
	mainCamera.SetPosition(Vector3D(5.0f, 10.0f, 20.0f)); //posicion camara fija
	mainCamera.SetOrientation(Vector3D(20.0f, 0.0f, 0.0f));
	mainScene->SetCamera(mainCamera);

	/*Cube* cubes = new(nothrow) Cube[8];
	for (int index = 0; index < 8; index++)
	{
		cubes[index] = Cube();
		cubes[index].SetColor(Color(0.1f, 0.2f, 0.8f));
		cubes[index].SetSize(0.2f);
		cubes[index].SetIsAffectedByGravity(false);
		cubes[index].SetOrientationSpeed(Vector3D(10.0f, 10.0f, 10.0f));
		mainScene->AddGameObject(cubes + index);
	}
	cubes[0].SetPosition(Vector3D(0.0f, 0.0f, 0.0f));
	cubes[1].SetPosition(Vector3D(0.0f, 0.0f, 10.0f));
	cubes[2].SetPosition(Vector3D(0.0f, 10.0f, 0.0f));
	cubes[3].SetPosition(Vector3D(0.0f, 10.0f, 10.0f));
	cubes[4].SetPosition(Vector3D(10.0f, 0.0f, 0.0f));
	cubes[5].SetPosition(Vector3D(10.0f, 0.0f, 10.0f));
	cubes[6].SetPosition(Vector3D(10.0f, 10.0f, 0.0f));
	cubes[7].SetPosition(Vector3D(10.0f, 10.0f, 10.0f));*/

	int i = 10;
	Cube* pointerToCubes = new(nothrow) Cube[10];
	if (pointerToCubes != nullptr) {
		for (int index = 0; index < 10; index++) {
			pointerToCubes[index] = Cube(
				Vector3D((1 + index * 0.1), (0.5), (-10 - i+ 100 *0.1)),  //posición 
				Color((0.2 + index * 0.5),(0.4 * 0.1),(0.7 * 0.1)), 
				Vector3D((0.02 + index* 0.001),(0),(0)),  //velocidad
				0.1 + 2 * 0.1);
			i += 60;
			pointerToCubes[index].SetOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
			mainScene->AddGameObject(pointerToCubes + index);
			pointerToCubes[index].SetIsAffectedByGravity(false);
		}
	}

	 //para posibles puntuaciones
	/*Torus* torus = new Torus();
	torus->SetPosition(Vector3D(2.0f, 3.0f, 1.0f));
	torus->SetColor(Color(0.8f, 0.9f, 0.8f));
	torus->SetOrientationSpeed(Vector3D(0.0f, 6.0f, 0.0f));
	torus->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(torus);*/


	//paredes
	/*Cuboid* back = new Cuboid();
	back->SetPosition(Vector3D(5.0f, 5.0f, -0.5f));
	back->SetColor(Color(0.9f, 0.6f, 0.5f));
	back->SetHeight(10.0f);
	back->SetLength(10.0f);
	back->SetWidth(1.0f);
	back->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(back);

	Cuboid* right = new Cuboid();
	right->SetPosition(Vector3D(10.5f, 5.0f, 5.0f));
	right->SetColor(Color(0.6f, 0.5f, 0.9f));
	right->SetHeight(10.0f);
	right->SetLength(1.0f);
	right->SetWidth(10.0f);
	right->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(right);*/

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


	Cuboid* jugador = new Cuboid();
	jugador->SetPosition(Vector3D(5.0f, 1.0f, 10.0f));
	jugador->SetColor(Color(1.0f, 30.0f, 1.0f));
	jugador->SetHeight(2.0f);
	jugador->SetLength(2.0f);
	jugador->SetWidth(2.0f);
	jugador->SetIsAffectedByGravity(false);
	mainScene->AddGameObject(jugador);

	/*Modelo* coche = new Modelo("Formula1.obj");
	coche->SetPosition(Vector3D(0, 0, 0));
	coche->SetColor(Vector3D(1, 0, 0));
	coche->SetOrientation(Vector3D(0, 90, 0));
	mainScene->AddGameObject(coche);

	coche->SetCamera(mainCamera);*/

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
