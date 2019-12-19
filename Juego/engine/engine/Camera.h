#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <GL/glut.h>
#include "Vector3D.h"
#include "GameObject.h"

class Camera :  public GameObject
{
private:
public:
	Camera() : GameObject() {}
	
	Camera(Vector3D positionToSet, Vector3D orientationToSet) : GameObject(positionToSet, Color(), Vector3D(), orientationToSet, Vector3D(), true) {}
	
	Camera(float x, float y, float z) : GameObject(Vector3D(x, y, z), Color(), Vector3D(), Vector3D(), Vector3D(), true) {}

	void Render();
	void Update(const float& time, const Vector3D& gravity);
};

