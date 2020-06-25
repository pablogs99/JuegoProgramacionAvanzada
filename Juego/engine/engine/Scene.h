#pragma once
#include <vector>
#include "Vector3D.h"
#include "GameObject.h"

using namespace std;

class Scene
{
private:

	Vector3D size;
	Vector3D gravity;
public:

	Scene(Vector3D sizeToSet = Vector3D(10.0f, 10.0f, 10.0f), Vector3D gravity = Vector3D(0.0f, -0.01f, 0.0f)) :
		size(sizeToSet), gravity(gravity) {}

	inline Vector3D GetSize() const { return this->size; }
	inline Vector3D GetGravity() const { return this->gravity; }
	inline void SetGravity(const Vector3D& gravity) { this->gravity = gravity; }
	inline void SetSize(const Vector3D& sizeToSet) { this->size = sizeToSet; }

	virtual void ClearScene();
	virtual void Render();
	virtual void Update(const float& time);

	void ProcessMouseMovement(const int& x, const int& y);
	void ProcessMouseClick(const int& button, const int& state, const int& x, const int& y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
};
