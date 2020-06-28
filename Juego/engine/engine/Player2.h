#pragma once
#include "GameObject.h"
#include "Model.h"
#include <iostream>

class Player2 : public Model {
private:

	float colision1 = 3.6; //Lado izquierdo
	float colision2 = 6.8; //Lado derecho
	
	float velocidad = 0.45f;

public:
	Player2() {
		this->LoadModel("Heart1.obj");
		this->SetColor(Color(1.0, 0.0, 0.0));
		this->SetIsAffectedByGravity(false);
		this->SetSpeed(Vector3D(velocidad, 0, 0));
	}

	void cambiarVelocidad(float v);
	inline float getColision1() { return colision1; }
	inline float getColision2() { return colision2; }

	void ProcessKeyPressed(unsigned char key, int px, int py);
};

