#pragma once

#ifndef PLANO_H_
#define PLANO_H_
#include "GameObject.h"

class Plano : public GameObject {
	float a, b, c, d;
public:
	Plano();
	//vn must be normalized
	Plano(Vector3D vn, Vector3D p) :a(vn.GetX()), b(vn.GetY()), c(vn.GetZ()), d(vn* p) {}
	Plano(const Plano& p) :GameObject(p), a(p.a), b(p.b), c(p.c), d(p.d) {}
	virtual ~Plano();
	inline float getA() const { return a; }
	inline void setA(float a) { this->a = a; }
	inline float getB() const { return b; }
	inline void setB(float b) { this->b = b; }
	inline float getC() const { return c; }
	inline void setC(float c) { this->c = c; }
	inline float getD() const { return d; }
	inline void setD(float d) { this->d = d; }
	//bool colision(Solido *s);
	Vector3D getNormal() {
		Vector3D v(a, b, c);
		//v.normalize();
		return v;
	}
};

#endif /* PLANO_H_ */
