#pragma once
#include "GameObject.h"
#include "Model.h"
#include <iostream>

class Player2 : public Model {
private:

	float colision1 = 3.8; //Lado izquierdo
	float colision2 = 6.6; //Lado derecho
	
	float velocidad = 0.45f;

public:
	Player2() {
		this->LoadModel("heart.obj");
		this->SetColor(Color(1.0, 0.0, 0.0));
		this->SetOrientation(Vector3D(0.0f, 90.0f, 0.0f));
		this->SetIsAffectedByGravity(false);
		this->SetSpeed(Vector3D(velocidad, 0, 0));
	}

	void cambiarVelocidad(float v);
	inline float getColision1() { return colision1; }
	inline float getColision2() { return colision2; }

	void ProcessKeyPressed(unsigned char key, int px, int py);
};

