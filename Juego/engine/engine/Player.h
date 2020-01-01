#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
	float height;											
	float length;										
	float width;										

	float collisionPoints[10] = { 0.75 * -2.0, 0.75 * 4, 0.75 * 2.0, 0.75 * 4, 0.75 * 0.0, 0.75 * 8, 0.75 * -1.0, 0.75 * 6, 0.75 * 1.0, 0.75 * 6 };	//Coordenadas de los puntos de colisión. Van x, z para cada punto (x[0], z[0], x[1], z[1], x[2], z[2]...)
	int collisionPointsNumber = 5;	//Número de puntos de colisión

public:
	Player(): GameObject(), height(1.0f), length(2.0f), width(0.5f) {}
	

	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline float GetLength() const { return this->length; }
	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
	inline float GetWidth() const { return this->width; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	inline int getCollisionPointsNumber() { return collisionPointsNumber; }
	inline float* getCollisionPoints() { return collisionPoints; }

	void Render();
	bool checkCollisionZX(const float& z, const float& x) { return false; };

	void ProcessKeyPressed(unsigned char key, int px, int py);
};

