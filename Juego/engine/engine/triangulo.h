
#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include <iostream>
#include <GL/glut.h>
#include "plano.h"
#include "Vector3D.h"
 //#include "textura.h"

using namespace std;

class Triangulo : public Plano {
protected:
	Vector3D p0, p1, p2;
	Vector3D n0, n1, n2;
	Vector3D t0, t1, t2;
	//Textura textura;
public:
	Triangulo(Vector3D p0, Vector3D p1, Vector3D p2) :Plano(), p0(p0), p1(p1), p2(p2) {
		Vector3D v0 = p1 - p0;
		Vector3D v1 = p2 - p1;
		Vector3D vn = v0.DotProduct(v1);
		try {
			vn = v0.DotProduct(v1);
			//vn.normalize();
			double d = vn * p2;
			this->setA(vn.GetX());
			this->setB(vn.GetY());
			this->setC(vn.GetZ());
			this->setD(d);
		}
		catch (exception & e) {
			//cout << "Capturado:" << e.what() << ".En contructor Triangulo." << endl;
			double d = vn * p2;
			this->setA(vn.GetX());
			this->setB(vn.GetY());
			this->setC(vn.GetZ());
			this->setD(d);
		}
	}
	Triangulo(const Triangulo& t) :Plano(t), p0(t.p0), p1(t.p1), p2(t.p2) {}
	virtual Triangulo* clone() { return new Triangulo(*this); }
	inline Vector3D& getP0() { return p0; }
	inline Vector3D& getP1() { return p1; }
	inline Vector3D& getP2() { return p2; }
	inline Vector3D& getN0() { return n0; }
	inline Vector3D& getN1() { return n1; }
	inline Vector3D& getN2() { return n2; }
	inline Vector3D& getT0() { return t0; }
	inline Vector3D& getT1() { return t1; }
	inline Vector3D& getT2() { return t2; }
	inline void setP0(Vector3D& n) { p0 = n; }
	inline void setP1(Vector3D& n) { p1 = n; }
	inline void setP2(Vector3D& n) { p2 = n; }
	inline void setN0(Vector3D& n) { n0 = n; }
	inline void setN1(Vector3D& n) { n1 = n; }
	inline void setN2(Vector3D& n) { n2 = n; }
	inline void setT0(Vector3D& n) { t0 = n; }
	inline void setT1(Vector3D& n) { t1 = n; }
	inline void setT2(Vector3D& n) { t2 = n; }
	virtual ~Triangulo();
	void render();
};

#endif /* TRIANGULO_H_ */
