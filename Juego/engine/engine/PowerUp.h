#pragma once
#include "Torus.h"
class PowerUp: public Torus
{
public:
	PowerUp(){
		this->SetColor(Color(0.3f, 0.9f, 0.8f));
		this->SetIsAffectedByGravity(false);
	}
};

