#pragma once
#include "GameObject.h"
#include <iostream>
class Player : public GameObject {
private:
	float height;											
	float length;										
	float width;										

	float colision1 = 3.2; //Lado izquierdo
	float colision2 = 6.8; //Lado derecho

public:
	Player(): GameObject(), height(1.0f), length(2.0f), width(0.5f) {}
	
	inline float GetHeight() const { return this->height; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline float GetLength() const { return this->length; }
	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
	inline float GetWidth() const { return this->width; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	inline float getColision1() { return colision1; }
	inline float getColision2() { return colision2; }

	void Render();
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

