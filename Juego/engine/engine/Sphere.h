#pragma once
#include "Vector3D.h"
#include "GameObject.h"
#include <GL/glut.h>

class Sphere : public GameObject
{
private:
	float radius;
	int slices;
	int stacks;

public:
	Sphere(Vector3D position, Color color, Vector3D speed, Vector3D orientation, float radius = 1.0, int slices = 20, int stacks = 20) :
		GameObject(position, color, speed, orientation, Vector3D(), true), radius(radius), slices(slices), stacks(stacks) {}

	inline float GetRadius() const { return this->radius; }
	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline int GetSlices() const { return this->slices; }
	inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	inline int GetStacks() const { return this->stacks; }
	inline void SetStacks(const int& stacksToSet) { this->stacks = stacksToSet; }

	void Render();
};

