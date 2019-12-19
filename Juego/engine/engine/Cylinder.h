#pragma once
#include "GameObject.h"
#include <GL/glut.h>

class Cylinder : public GameObject
{
private:
	GLUquadricObj* quadratic;
	float radius;
	float height;
public:
	Cylinder(float radius, float height);
	~Cylinder();
	inline float GetRadius() const { return this->radius; }
	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline GLUquadricObj* GetQuadratic() const { return this->quadratic; }

	void Render();
};

