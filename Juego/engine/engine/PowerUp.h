#pragma once
#include "Model.h"
class PowerUp: public Model
{
public:
	PowerUp(){
		this->LoadModel("Star.obj");
		this->SetColor(Color(0.8f, 0.9f, 0.8f));
		this->SetIsAffectedByGravity(false);
	}
};

