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
	switch (key) {
	case 'a':
	case 'A':
		/*if (this->GetPosition().GetZ() > -9.0) {
			
			this->getposition().setz(this->getposition().getz() - this->getspeed().getz());
			collisionpoints[0] -= this->getspeed().getz();
			collisionpoints[2] -= this->getspeed().getz();
			collisionpoints[4] -= this->getspeed().getz();
			collisionpoints[6] -= this->getspeed().getz();
			collisionpoints[8] -= this->getspeed().getz();
			this->setposition(this->getposition());
		}*/
		if (this->GetPosition().GetX() > -1.0f) {
			this->SetPosition(Vector3D(this->GetPosition().GetX() - 0.4f, 1.0f, 10.0f));

			std::cout << "Pos X -> " << this->GetPosition().GetX() << std::endl;
		}
		break;
	case 'd':
	case 'D':
		/*if (this->GetPosition().GetZ() < 19.0) {
			
			this->GetPosition().SetZ(this->GetPosition().GetZ() + this->GetSpeed().GetZ());
			collisionPoints[0] += this->GetSpeed().GetZ();
			collisionPoints[2] += this->GetSpeed().GetZ();
			collisionPoints[4] += this->GetSpeed().GetZ();
			collisionPoints[6] += this->GetSpeed().GetZ();
			collisionPoints[8] += this->GetSpeed().GetZ();
			this->SetPosition(this->GetPosition());
		}*/
		if (this->GetPosition().GetX() < 11.0f) {
			this->SetPosition(Vector3D(this->GetPosition().GetX() + 0.4f, 1.0f, 10.0f));

			std::cout << "Pos X -> " << this->GetPosition().GetX() << std::endl;
		}
			break;
		
	}
}
