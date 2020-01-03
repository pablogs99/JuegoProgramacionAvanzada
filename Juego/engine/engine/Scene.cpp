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
	this->player.Render();

	// tres formas de recorrer el vector de s�lidos
	//1.- bucle for con �ndice comprobando con el tama�o del vector
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
		
	}
	for (int idx = 0; idx < this->obstacles.size(); idx++)
	{
		this->obstacles[idx]->Render();
	}

	//2.- usando un bucle for autom�tico sobre el vector
	//for (GameObject* gameObjectInVector : this->gameObjects)
	//{
	//	gameObjectInVector->Render();
	//}

	//3.- empleando un iterador que proporciona la clase vector
	//for (vector<GameObject*>::iterator it = this->gameObjects.begin(); it != this->gameObjects.end(); ++it)
	//{
	//	(*it)->Render();
	//}
}

void Scene::Update(const float& time)
{
	if (!victoria && !derrota) {

		puntos += time;
		cout << puntos << endl;
		
		//Si llegamos a los 100 puntos, se para el juego y ganamos
		if (puntos == 100) {
			this->player.SetSpeed(Vector3D(0, 0, 0));
			for (int idx = 0; idx < this->obstacles.size(); idx++)
			{
				this->obstacles[idx]->SetSpeed(Vector3D(0, 0, 0));
			}
			victoria = true;
		}

		//Comprobar colisiones
		for (int idx = 0; idx < this->obstacles.size(); idx++)
		{
			if (obstacles[idx]->GetPosition().GetZ() < 11.7) { //Para que no haya colision despues de que el obstaculo sobrepase al jugador
				// Colision eje X
				bool collisionX = obstacles[idx]->GetPosition().GetX() > this->player.getColision1() && obstacles[idx]->GetPosition().GetX() < this->player.getColision2();

				// Colision eje Y
				bool collisionZ = obstacles[idx]->GetPosition().GetZ() >= this->player.GetPosition().GetZ();

				// Colision solo si ha habido colision en los dos ejes
				// Si hay colision se para el juego y perdemos
				if (collisionX && collisionZ) {
					this->player.SetSpeed(Vector3D(0, 0, 0));
					for (int idx = 0; idx < this->obstacles.size(); idx++)
					{
						this->obstacles[idx]->SetSpeed(Vector3D(0, 0, 0));
					}
					derrota = true;
				}
			}
		}

		for (int idx = 0; idx < this->obstacles.size(); idx++)
		{
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

		if (derrota) {
			cout << "Derrota" << endl;
		}
		if (victoria) {
			cout << "Victoria" << endl;
		}
		
	}
}

void Scene::ProcessMouseMovement(const int& x, const int& y)
{
	this->camera.ProcessMouseMovement(x, y);
}

void Scene::ProcessMouseClick(const int& button, const int& state, const int& x, const int& y)
{
	this->camera.ProcessMouseClick(button, state, x, y);
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->player.ProcessKeyPressed(key, px, py);
	this->camera.ProcessKeyPressed(key, px, py);

}


