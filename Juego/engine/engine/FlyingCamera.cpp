#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "FlyingCamera.h"

void FlyingCamera::Render() {
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glTranslatef(-this->GetPosition().GetX(), -this->GetPosition().GetY(), -this->GetPosition().GetZ());
}

void FlyingCamera::Update(const float& time, const Vector3D& gravity)
{
	float yOrientationInRadians = this->GetOrientation().GetY() * M_PI / 180;
	float xOrientationInRadians = this->GetOrientation().GetX() * M_PI / 180;
	float xComponent = -cos(xOrientationInRadians) * sin(yOrientationInRadians);
	float yComponent = sin(xOrientationInRadians);
	float zComponent = cos(xOrientationInRadians) * cos(yOrientationInRadians);
	Vector3D velocity(xComponent, yComponent, zComponent);
	this->SetPosition(this->GetPosition() -  velocity * time);

	std::cout << "X: " << this->GetPosition().GetX() << " Y: " << this->GetPosition().GetY() << " Z: " << this->GetPosition().GetZ() << std::endl;
	std::cout << "P: " << this->GetOrientation().GetX() << " Y: " << this->GetOrientation().GetY() << " R: " << this->GetOrientation().GetZ() << std::endl;

}

void FlyingCamera::ProcessMouseMovement(const int& x, const int& y) 
{
	this->SetOrientation(this->GetOrientation() + Vector3D(y - this->GetMouseCoordinateY(), x - this->GetMouseCoordinateX(), 0.0));
	this->SetMouseCoordinateX(x);
	this->SetMouseCoordinateY(y);
}

void FlyingCamera::ProcessMouseClick(const int& button, const int& state, const int& x, const int& y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		this->SetMouseCoordinateX(x);
		this->SetMouseCoordinateY(y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		this->SetMouseCoordinateX(0);
		this->SetMouseCoordinateY(0);
	}
}

void FlyingCamera::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key) {
	case 'w':
	case 'W':
		this->Update(0.1f, Vector3D());
		break;
	case 's':
	case 'S':
		this->Update(-0.1f, Vector3D());
		break;
	}
}

