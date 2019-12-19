#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "GameObject.h"

class Cube : public GameObject
{
private:
	float size;
public:
	Cube() : GameObject(), size(1.0) {}

	Cube(Vector3D position, Color color, Vector3D speed, Vector3D orientation, float size = 1.0) :
		GameObject(position, color, speed, orientation, Vector3D(), true), size(size) {}

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

