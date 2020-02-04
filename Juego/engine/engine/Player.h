#pragma once
#include "GameObject.h"
#include "Cuboid.h"
#include <iostream>
class Player : public Cuboid {
private:								

	float colision1 = 3.2; //Lado izquierdo
	float colision2 = 6.8; //Lado derecho

public:
	Player(){
		this->SetHeight(2.0f);
		this->SetLength(2.0f);
		this->SetWidth(2.0f);
		this->SetColor(Color(1.0f, 30.0f, 1.0f));
		this->SetIsAffectedByGravity(false);
	}


	inline float getColision1() { return colision1; }
	inline float getColision2() { return colision2; }

	void ProcessKeyPressed(unsigned char key, int px, int py);
};

