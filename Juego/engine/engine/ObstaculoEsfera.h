#pragma once
#include "Sphere.h"

class ObstaculoEsfera: public Sphere
{
public:
	ObstaculoEsfera(){}
	ObstaculoEsfera(Vector3D position, Color color, Vector3D speed,Vector3D orientation) :
		Sphere(position,color,speed,orientation){
		this->SetRadius(1.3);
	}
};

