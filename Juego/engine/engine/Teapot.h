#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "GameObject.h"

class Teapot : public GameObject
{
private:

public:
	Teapot(): GameObject() { }
	
	Teapot(Vector3D positionToSet, Color colorToSet, Vector3D speedToSet = Vector3D(), Vector3D orientationToSet = Vector3D()) 
		: GameObject(positionToSet, colorToSet, speedToSet, orientationToSet, Vector3D(), true) {}

	void Render();

};

