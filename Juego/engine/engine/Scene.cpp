#include "Scene.h"

void Scene::AddGameObject(GameObject* object)
{
	this->gameObjects.push_back(object);
}

void Scene::AddObstacle(GameObject* object)
{
	this->obstacles.push_back(object);
}

void Scene::ClearScene()
{
	this->gameObjects.clear();
	this->obstacles.clear();
}

void Scene::Render()
{
	this->camera.Render();
	//this->player.Render();
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

void Scene::Update(const float& time)
{
	if (!derrota) {
		this->puntos += time;
		//cout << puntos << endl;

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

void Scene::SpawnPowerUp() {
	//A los 100 puntos aparece el anillo powerUp que nos aumentara la velocidad de movimiento
	if (puntos >= 100) {
		this->powerUp->SetPosition(Vector3D(6.0f, 1.2f, -25.0f));
		this->powerUp->SetSpeed(Vector3D(0.0f, 0.0f, 0.5f));
		powerUpSpawned = true;
	}
}

void Scene::CheckCollision() {
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

void Scene::CheckPowerUpCollision() {

	//Colision con el PowerUp
	if (powerUp->GetPosition().GetZ() < 11.7) {
		bool collisionX = powerUp->GetPosition().GetX() > this->player2.getColision1() && powerUp->GetPosition().GetX() < this->player2.getColision2();

		bool collisionZ = powerUp->GetPosition().GetZ() >= this->player2.GetPosition().GetZ();

		if (collisionX && collisionZ) {
			this->player2.SetSpeed(Vector3D(0.9, 0, 0));
			powerUpColision = true;
			//Liberar memoria del powerUp
			delete this->powerUp;
		}
	}
	if (powerUp->GetPosition().GetZ() > 12) {
		powerUpColision = true;
	}
}
void Scene::GameObjectLimits(const float& time) {

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

void Scene::ProcessMouseMovement(const int& x, const int& y)
{
}

void Scene::ProcessMouseClick(const int& button, const int& state, const int& x, const int& y)
{
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->player2.ProcessKeyPressed(key, px, py);
	this->camera.ProcessKeyPressed(key, px, py);
}


