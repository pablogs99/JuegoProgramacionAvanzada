#include "Triangle.h"

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);
	glNormal3f(normal.GetX(), normal.GetY(), normal.GetZ());
	glVertex3f(vertex1.GetX(), vertex1.GetY(), vertex1.GetZ());
	glNormal3f(normal.GetX(), normal.GetY(), normal.GetZ());
	glVertex3f(vertex2.GetX(), vertex2.GetY(), vertex2.GetZ());
	glNormal3f(normal.GetX(), normal.GetY(), normal.GetZ());
	glVertex3f(vertex3.GetX(), vertex3.GetY(), vertex3.GetZ());
	glEnd();
}
