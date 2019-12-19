#include "Camera.h"

void Camera::Render() {
	glTranslatef(-this->GetPosition().GetX(), -this->GetPosition().GetY(), -this->GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
}

void Camera::Update(const float& time, const Vector3D& gravity)
{}