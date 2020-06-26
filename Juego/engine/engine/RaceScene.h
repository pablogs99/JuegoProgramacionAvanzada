#pragma once
#include <vector>
#include "Vector3D.h"
#include "GameObject.h"
#include "Camera.h"
#include "PowerUp.h"
#include "Ranking.h"
#include "CamaraFija.h"
#include "Player2.h"
#include "Scene.h"
#include "ObstaculoCubo.h"
#include "ObstaculoEsfera.h"
#include "Cuboid.h"

using namespace std;

class RaceScene: public Scene
{
private:
	CamaraFija camera;
	vector<GameObject*> gameObjects;
	vector<GameObject*> obstacles;
	Player2 player2;
	PowerUp* powerUp;
	Ranking rank;

	int numObstaculos;
	float puntos = 0;
	bool derrota = false;
	bool powerUpColision = false;
	bool powerUpSpawned = false;

public:
	//En el constructor creamos el mapa, obstaculos, jugador y power up
	RaceScene(int nObstaculos, Vector3D cameraPosition = Vector3D(5.0f, 10.0f, 20.0f), 
		Vector3D cameraOrientation = Vector3D(20.0f, 0.0f, 0.0f)):
		Scene(),camera(CamaraFija(cameraPosition, cameraOrientation)) {
		numObstaculos = nObstaculos;
		 CreateCarretera();
		 CreateObstacle();
		 CreatePlayer();
		 CreatePowerUp();
	}

	inline int GetPuntos() { return this->puntos; }
	inline void SetPuntos(int puntos) { this->puntos = puntos; }

	inline CamaraFija GetCamera() const { return this->camera; }
	inline void SetCamera(CamaraFija cameraToSet) { this->camera = cameraToSet; }

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
	void ObstaculosLimits(const float& time);
	void CheckCollision();
	void CheckPowerUpCollision();
	void SpawnPowerUp();

	void ProcessKeyPressed(unsigned char key, int px, int py);
};
