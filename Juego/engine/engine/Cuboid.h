#pragma once
#include "GameObject.h"
class Cuboid : public GameObject
{
private:
	float height;											// Dimensi�n en el eje y
	float length;											// Dimensi�n en el eje x
	float width;											// Dimensi�n en el eje z
public:
	Cuboid() : GameObject(), height(1.0f), length(2.0f), width(0.5f) {}
	/* Metodos de acceso */
	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline float GetLength() const { return this->length; }
	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
	inline float GetWidth() const { return this->width; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	void Render();

};

