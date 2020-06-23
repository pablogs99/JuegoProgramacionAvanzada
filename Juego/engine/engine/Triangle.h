#pragma once
#include <GL/glut.h>
#include "Vector3D.h"

class Triangle
{
private:
	Vector3D vertex1;
	Vector3D vertex2;
	Vector3D vertex3;
	Vector3D normal;

public:
	Triangle(const Vector3D& vertex1, const Vector3D& vertex2, const Vector3D& vertex3, const Vector3D& normal) :
		vertex1(vertex1), vertex2(vertex2), vertex3(vertex3), normal(normal) {};
	void Render();
};
