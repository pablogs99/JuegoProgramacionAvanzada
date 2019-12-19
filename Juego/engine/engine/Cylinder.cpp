#include "Cylinder.h"

Cylinder::Cylinder(float baseRadius, float cylinderHeight) {
	this->quadratic = gluNewQuadric();
	this->radius = baseRadius;
	this->height = cylinderHeight;
}

Cylinder::~Cylinder()
{
	delete this->quadratic;
}

void Cylinder::Render() {
	glPushMatrix();
	glColor3f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue());
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	gluCylinder(this->GetQuadratic(), this->GetRadius(), this->GetRadius(), this->GetHeight(), 16, 16);
	glPopMatrix();
}


