#include "RaceScene.h"

void RaceScene::AddGameObject(GameObject* object)
{
	this->gameObjects.push_back(object);
}

void RaceScene::AddObstacle(GameObject* object)
{
	this->obstacles.push_back(object);
}

void RaceScene::ClearScene()
{
	this->gameObjects.clear();
	this->obstacles.clear();
}

void RaceScene::CreateCarretera() {

	Cuboid* floor = new Cuboid();
	floor->SetPosition(Vector3D(5.0f, -0.5f, 5.0f));
	floor->SetColor(Color(0.4f, 0.4f, 0.4f));
	floor->SetHeight(1.0f);
	floor->SetLength(14.0f);
	floor->SetWidth(1000.0f);
	floor->SetIsAffectedByGravity(false);
	this->AddGameObject(floor);

	Cuboid* pianoIZq = new Cuboid();
	pianoIZq->SetPosition(Vector3D(-3.0f, -1.0f, 5.0f));
	pianoIZq->SetColor(Color(120.0f, 1.0f, 1.0f));
	pianoIZq->SetHeight(1.0f);
	pianoIZq->SetLength(1.0f);
	pianoIZq->SetWidth(1000.0f);
	pianoIZq->SetIsAffectedByGravity(false);
	this->AddGameObject(pianoIZq);

	Cuboid* pianoDer = new Cuboid();
	pianoDer->SetPosition(Vector3D(13.0f, -1.0f, 5.0f));
	pianoDer->SetColor(Color(120.0f, 1.0f, 1.0f));
	pianoDer->SetHeight(1.0f);
	pianoDer->SetLength(1.0f);
	pianoDer->SetWidth(1000.0f);
	pianoDer->SetIsAffectedByGravity(false);
	this->AddGameObject(pianoDer);
}

void RaceScene::CreateObstacle() {
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
			this->AddObstacle(pointerToCubes + index);
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
			this->AddObstacle(pointerToSpheres + index);
		}
	}
}

void RaceScene::CreatePlayer() {

	Player2* jugador2 = new Player2();
	jugador2->SetPosition(Vector3D(5.0f, 1.0f, 10.0f));
	jugador2->SetSpeed(Vector3D(0.45f, 0, 0));
	this->setPlayer2(*jugador2);
}

void RaceScene::CreatePowerUp() {

	PowerUp* powerUp = new PowerUp();
	powerUp->SetPosition(Vector3D(6.0f, -4.2f, -25.0f)); //y = 1.2
	powerUp->SetOrientationSpeed(Vector3D(0.0f, 20.0f, 0.0f));
	this->setPower(powerUp);
}
void RaceScene::Render()
{
	this->camera.Render();
	this->player2.Render();
	if (!powerUpColision) {
		this->powerUp->Render();
	}
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
	for (int idx = 0; idx < this->obstacles.size(); idx++)
	{
		this->obstacles[idx]->Render();
	}
}

void RaceScene::Update(const float& time)
{
	if (!derrota) {
		this->puntos += time;
		cout << puntos << endl;

		/////////////////
		if (!powerUpSpawned) {
			SpawnPowerUp();
		}
		//////////////////
		CheckCollision();
		///////////////////
		CheckPowerUpCollision();
		///////////////////////
		GameObjectLimits(time);
		///////////////////////

		//Mientras que no haya colisionado el powerUp, seguimos actualizandolo
		if (!powerUpColision) {
			this->powerUp->Update(time, this->GetGravity());
		}
		if (derrota) {
			cout << "HAS PERDIDO!" << endl;
			rank.crearRanking(puntos);
			cout << "PULSA M PARA VOLVER A INTENTARLO" << endl;
		}
	}
}

void RaceScene::SpawnPowerUp() {
	//A los 100 puntos aparece el anillo powerUp que nos aumentara la velocidad de movimiento
	if (puntos >= 100) {
		this->powerUp->SetPosition(Vector3D(6.0f, 1.2f, -25.0f));
		this->powerUp->SetSpeed(Vector3D(0.0f, 0.0f, 0.5f));
		powerUpSpawned = true;
	}
}

void RaceScene::CheckCollision() {
	//Comprobar colisiones
	for (int idx = 0; idx < this->obstacles.size(); idx++)
	{
		if (obstacles[idx]->GetPosition().GetZ() < 11.7) { //Para que no haya colision despues de que el obstaculo sobrepase al jugador
			// Colision eje X
			bool collisionX = obstacles[idx]->GetPosition().GetX() > this->player2.getColision1() && obstacles[idx]->GetPosition().GetX() < this->player2.getColision2();

			// Colision eje Z
			bool collisionZ = obstacles[idx]->GetPosition().GetZ() >= this->player2.GetPosition().GetZ();

			// Colision solo si ha habido colision en los dos ejes
			// Si hay colision se para el juego y perdemos
			if (collisionX && collisionZ) {
				this->player2.SetSpeed(Vector3D(0, 0, 0));
				for (int idx = 0; idx < this->obstacles.size(); idx++)
				{
					this->obstacles[idx]->SetSpeed(Vector3D(0, 0, 0));
				}
				derrota = true;
			}
		}
	}
}

void RaceScene::CheckPowerUpCollision() {

	//Colision con el PowerUp
	if (powerUp->GetPosition().GetZ() < 11.7) {
		bool collisionX = powerUp->GetPosition().GetX() > this->player2.getColision1() && powerUp->GetPosition().GetX() < this->player2.getColision2();

		bool collisionZ = powerUp->GetPosition().GetZ() >= this->player2.GetPosition().GetZ();

		if (collisionX && collisionZ) {
			this->player2.cambiarVelocidad(this->player2.GetSpeed().GetX() * 2);
			powerUpColision = true;
			//Liberar memoria del powerUp
			delete this->powerUp;
		}
	}
	if (powerUp->GetPosition().GetZ() > 12) {
		powerUpColision = true;
		delete this->powerUp;
	}
}
void RaceScene::GameObjectLimits(const float& time) {

	for (int idx = 0; idx < this->obstacles.size(); idx++)
	{
		//Para que los obstaculos no se salgan del mapa
		this->obstacles[idx]->Update(time, this->GetGravity());

		if (this->obstacles[idx]->GetPosition().GetX() > this->GetSize().GetX()
			|| this->obstacles[idx]->GetPosition().GetX() < 0) {

			this->obstacles[idx]->SetSpeed(Vector3D(this->obstacles[idx]->GetSpeed().GetX() * -1,
				this->obstacles[idx]->GetSpeed().GetY(), this->obstacles[idx]->GetSpeed().GetZ()));
		}
		if (this->obstacles[idx]->GetPosition().GetY() > this->GetSize().GetY() ||
			this->obstacles[idx]->GetPosition().GetY() < 0) {

			this->obstacles[idx]->SetSpeed(Vector3D(this->obstacles[idx]->GetSpeed().GetX(),
				this->obstacles[idx]->GetSpeed().GetY() * -1, this->obstacles[idx]->GetSpeed().GetZ()));
		}
		//Si los obstaculos llegan al final, vuelven a posicionarse al principio del mapa
		//para dar una sensacion de obstaculos infinitos
		if (this->obstacles[idx]->GetPosition().GetZ() > 20 ||
			this->obstacles[idx]->GetPosition().GetZ() < -30) {

			this->obstacles[idx]->SetPosition(Vector3D((rand() % 13), (0.5), -25));
		}
	}
}

void RaceScene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->player2.ProcessKeyPressed(key, px, py);
	this->camera.ProcessKeyPressed(key, px, py);
}
