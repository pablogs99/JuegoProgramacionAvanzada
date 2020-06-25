#pragma once
#include <vector>
#include "Vector3D.h"
#include "GameObject.h"
#include "Camera.h"
#include "Player.h"
#include "PowerUp.h"
#include "Ranking.h"
#include "CamaraFija.h"
#include "Player2.h"
#include "Scene.h"
#include "ObstaculoCubo.h"
#include "ObstaculoEsfera.h"

using namespace std;

class RaceScene: public Scene
{
private:
	CamaraFija camera;
	vector<GameObject*> gameObjects;
	vector<GameObject*> obstacles;
	Player player;
	PowerUp* powerUp;
	Ranking rank;
	float puntos = 0;
	bool derrota = false;
	bool powerUpColision = false;
	bool powerUpSpawned = false;

	Player2 player2;
public:

	//Scene(Vector3D sizeToSet = Vector3D(10.0f, 10.0f, 10.0f), Vector3D cameraPosition = Vector3D(5.0f, 10.0f, 20.0f),
//	Vector3D cameraOrientation = Vector3D(20.0f, 0.0f, 0.0f), Vector3D gravity = Vector3D(0.0f, -0.01f, 0.0f)) :
//	size(sizeToSet), gravity(gravity), camera(CamaraFija(cameraPosition, cameraOrientation)) {}


	RaceScene(Vector3D cameraPosition = Vector3D(5.0f, 10.0f, 20.0f), Vector3D cameraOrientation = Vector3D(20.0f, 0.0f, 0.0f)):
		Scene(),camera(CamaraFija(cameraPosition, cameraOrientation)) {
		 CreateCarretera();
		 CreateObstacle();
		 CreatePlayer();
		 CreatePowerUp();
	}

	inline int GetPuntos() { return this->puntos; }
	inline void SetPuntos(int puntos) { this->puntos = puntos; }

	inline CamaraFija GetCamera() const { return this->camera; }
	inline void SetCamera(CamaraFija cameraToSet) { this->camera = cameraToSet; }

	Player getPlayer() { return this->player; }
	void setPlayer(const Player& player){ this->player = player;}

	PowerUp* getPower() { return this->powerUp; }
	void setPower(PowerUp* power) { this->powerUp = power; }
	bool getPowerColision() { return this->powerUpColision; }

	Player2 getPlayer2() { return this->player2; }
	void setPlayer2(const Player2& player) { this->player2 = player; }

	void AddGameObject(GameObject* objectToAdd);
	void AddObstacle(GameObject* objectToAdd);
	void ClearScene() override;
	void Render() override;

	//Crear todos los elementos de la escena
	void CreateCarretera();
	void CreateObstacle();
	void CreatePlayer();
	void CreatePowerUp();

	//Progreso del juego
	void Update(const float& time) override;
	void GameObjectLimits(const float& time);
	void CheckCollision();
	void CheckPowerUpCollision();
	void SpawnPowerUp();

	void ProcessKeyPressed(unsigned char key, int px, int py);
};
