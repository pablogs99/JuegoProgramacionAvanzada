#include "Player.h"



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
