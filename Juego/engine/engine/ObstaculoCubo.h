#pragma once
#include "Cube.h"

class ObstaculoCubo: public Cube
{
public:
	ObstaculoCubo(){}
	ObstaculoCubo(Vector3D position, Color color, Vector3D speed, Vector3D orientation) :
		Cube(position,color,speed,orientation){
		this->SetSize(2);
	}
};

