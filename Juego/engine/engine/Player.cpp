#include "Player.h"


void Player::Render() {
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glScalef(GetLength(), GetHeight(), GetWidth());
	glutSolidCube(1);
	glPopMatrix();
}

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	float velocidad = this->GetSpeed().GetX(); // velocidad = 0.45f
	switch (key) {
	case 'a':
	case 'A':

		if (this->GetPosition().GetX() > -1.0f) { //para no salirse de los bordes
			 this->SetPosition(Vector3D(this->GetPosition().GetX() - velocidad, 1.0f, 10.0f));

			 colision1 -= velocidad; //movemos los puntos de colision
			 colision2 -= velocidad;
		}
		break;
	case 'd':
	case 'D':

		if (this->GetPosition().GetX() < 10.9f) {
			this->SetPosition(Vector3D(this->GetPosition().GetX() + velocidad, 1.0f, 10.0f));

			colision1 += velocidad;
			colision2 += velocidad;
		}
			break;
		
	}
}
