#pragma once
#include "Camera.h"
class FlyingCamera : public Camera
{
private:
	int mouseCoordinateX;
	int mouseCoordinateY;
public:
	FlyingCamera() : Camera(), mouseCoordinateX(0), mouseCoordinateY(0) {}
	FlyingCamera(Vector3D positionToSet, Vector3D orientationToSet) : Camera(positionToSet, orientationToSet) {}
	FlyingCamera(float x, float y, float z) : Camera(x, y, z), mouseCoordinateX(0), mouseCoordinateY(0) {}

	inline float GetMouseCoordinateX() const { return this->mouseCoordinateX; }
	inline void SetMouseCoordinateX(const int& mouseX) { this->mouseCoordinateX = mouseX; }
	inline float GetMouseCoordinateY() const { return this->mouseCoordinateY; }
	inline void SetMouseCoordinateY(const int& mouseY) { this->mouseCoordinateY = mouseY; }

	void Render() override;
	void Update(const float& time, const Vector3D& gravity) override;

	void ProcessMouseMovement(const int& x, const int& y);
	void ProcessMouseClick(const int& button, const int& state, const int& x, const int& y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

