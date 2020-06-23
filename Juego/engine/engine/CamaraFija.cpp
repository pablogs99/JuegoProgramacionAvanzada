#include "CamaraFija.h"

void CamaraFija::Render() {
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glTranslatef(-this->GetPosition().GetX(), -this->GetPosition().GetY(), -this->GetPosition().GetZ());
}
void CamaraFija::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key) {
	case 'j':
	case 'J':
		this->SetPosition(Vector3D(5.0f, 10.0f, 20.0f)); //main Camera
		this->SetOrientation(Vector3D(20.0f, 0.0f, 0.0f));
		break;

	case 'k':
	case 'K':
		this->SetPosition(Vector3D(5.0f, 30.0f, 1.0f)); //camara Cenital
		this->SetOrientation(Vector3D(90.0f, 0.0f, 0.0f));
		break;

	case 'l':
	case 'L':
		this->SetPosition(Vector3D(5.0f, 30.0f, -6.0f)); //camara Lateral
		this->SetOrientation(Vector3D(90.0f, -90.0f, 0.0f));
		break;
	}

}