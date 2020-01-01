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
	Vector3D newPosition = this->GetPosition();
	switch (key) {
	case 'a':
	case 'A':
		if (this->GetPosition().GetZ() > -9.0) {
			//this->setOrientation(Vector3D(0.0f,90.0f,-45.0f));
			newPosition.SetZ(newPosition.GetZ() - this->GetSpeed().GetZ());
			collisionPoints[0] -= this->GetSpeed().GetZ();
			collisionPoints[2] -= this->GetSpeed().GetZ();
			collisionPoints[4] -= this->GetSpeed().GetZ();
			collisionPoints[6] -= this->GetSpeed().GetZ();
			collisionPoints[8] -= this->GetSpeed().GetZ();
			this->SetPosition(newPosition);
		}
		break;
	case 'd':
	case 'D':
		if (this->GetPosition().GetZ() < 19.0) {
			//this->setOrientation(Vector3D(0.0f, 90.0f, 45.0f));
			newPosition.SetZ(newPosition.GetZ() + this->GetSpeed().GetZ());
			collisionPoints[0] += this->GetSpeed().GetZ();
			collisionPoints[2] += this->GetSpeed().GetZ();
			collisionPoints[4] += this->GetSpeed().GetZ();
			collisionPoints[6] += this->GetSpeed().GetZ();
			collisionPoints[8] += this->GetSpeed().GetZ();
			this->SetPosition(newPosition);
		}
		break;
	}
}
