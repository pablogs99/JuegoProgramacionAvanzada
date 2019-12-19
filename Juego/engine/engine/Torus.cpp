#include "Torus.h"
void Torus::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), (*this).GetPosition().GetY(), GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glutSolidTorus(this->GetInnerRadius(), this->GetOuterRadius(), this->GetSides(), this->GetRings());
	glPopMatrix();
}