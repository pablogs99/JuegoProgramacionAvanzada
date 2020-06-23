#pragma once
#include "Camera.h"

class CamaraFija : public Camera
{
private:

public:
	CamaraFija(Vector3D positionToSet, Vector3D orientationToSet) : Camera(positionToSet, orientationToSet) {}
	CamaraFija(float x, float y, float z) : Camera(x, y, z) {}

	void Render() override;
	void ProcessKeyPressed(unsigned char key, int px, int py);
};
