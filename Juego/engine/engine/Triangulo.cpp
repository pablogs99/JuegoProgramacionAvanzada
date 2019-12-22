
#include "triangulo.h"

Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}
void Triangulo::render() {
	Vector3D c = this->GetColor();
	glColor3f(c.GetX(), c.GetY(), c.GetZ());
	Vector3D vn = this->getNormal();
	float vnx = vn.GetX();
	float vny = vn.GetY();
	float vnz = vn.GetZ();
	//textura.activar();
	glBegin(GL_TRIANGLES);
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p0.GetX(), p0.GetY(), p0.GetZ());
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p1.GetX(), p1.GetY(), p1.GetZ());
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p2.GetX(), p2.GetY(), p2.GetZ());
	glEnd();
	//textura.desactivar();
}

