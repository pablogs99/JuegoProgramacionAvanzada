#pragma once
#include <vector>
#include "Vector3D.h"
#include "GameObject.h"
#include "Camera.h"
#include "FlyingCamera.h"

using namespace std;

class Scene
{
private:
	FlyingCamera camera;
	vector<GameObject*> gameObjects;
	Vector3D size;
	Vector3D gravity;
public:

	Scene(Vector3D sizeToSet = Vector3D(10.0f, 10.0f, 10.0f), Vector3D cameraPosition = Vector3D(5.0f, 5.0f, 22.0f), 
		Vector3D cameraOrientation = Vector3D(), Vector3D gravity = Vector3D(0.0f, -0.01f, 0.0f)) : 
		size(sizeToSet), gravity(gravity), camera(FlyingCamera(cameraPosition, cameraOrientation)) {}

	inline Vector3D GetSize() const { return this->size; }
	inline Vector3D GetGravity() const { return this->gravity; }
	inline void SetGravity(const Vector3D& gravity) { this->gravity = gravity; }
	inline void SetSize(const Vector3D& sizeToSet) { this->size = sizeToSet; }
	inline FlyingCamera GetCamera() const { return this->camera; }
	inline void SetCamera(FlyingCamera cameraToSet) { this->camera = cameraToSet; }

	void AddGameObject(GameObject* objectToAdd);
	void ClearScene();
	void Render();
	void Update(const float& time);

	void ProcessMouseMovement(const int& x, const int& y);
	void ProcessMouseClick(const int& button, const int& state, const int& x, const int& y);
	void ProcessKeyPressed(unsigned char key, int px, int py);


};
