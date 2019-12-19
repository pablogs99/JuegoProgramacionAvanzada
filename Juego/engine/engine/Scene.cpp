#include "Scene.h"

void Scene::AddGameObject(GameObject* object)
{
	this->gameObjects.push_back(object);
}

void Scene::ClearScene()
{
	this->gameObjects.clear();
}

void Scene::Render()
{
	this->camera.Render();

	// tres formas de recorrer el vector de s�lidos
	//1.- bucle for con �ndice comprobando con el tama�o del vector
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
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
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(time, this->GetGravity());

		if (this->gameObjects[idx]->GetPosition().GetX() > this->GetSize().GetX() || this->gameObjects[idx]->GetPosition().GetX() < 0) {
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX() * -1, this->gameObjects[idx]->GetSpeed().GetY(), this->gameObjects[idx]->GetSpeed().GetZ()));
		}
		if (this->gameObjects[idx]->GetPosition().GetY() > this->GetSize().GetY() || this->gameObjects[idx]->GetPosition().GetY() < 0) {
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(), this->gameObjects[idx]->GetSpeed().GetY() * -1, this->gameObjects[idx]->GetSpeed().GetZ()));
		}
		if (this->gameObjects[idx]->GetPosition().GetZ() > this->GetSize().GetZ() || this->gameObjects[idx]->GetPosition().GetZ() < 0) {
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(), this->gameObjects[idx]->GetSpeed().GetY(), this->gameObjects[idx]->GetSpeed().GetZ() * -1));
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
	this->camera.ProcessKeyPressed(key, px, py);
}


