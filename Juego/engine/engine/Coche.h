#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include "Vector3D.h"
//#include "contorno.h"
#include "triangulo.h"
#include "GameObject.h"

using namespace std;

class Modelo : public GameObject {
	vector<Vector3D*> vertices;
	vector<Vector3D*> textures;
	vector<Vector3D*> normals;
	vector<Triangulo*> triangulos;
	float maxX, maxY, maxZ;
	float minX, minY, minZ;
	Vector3D scale;
public:
	Modelo() {}

	Modelo(string s) { cargar(s); scale = Vector3D(1, 1, 1); }
	Modelo(const Modelo& m);
	Modelo* clone() { return nullptr; }

	virtual ~Modelo();

	Triangulo* centrar(Triangulo* t);
	inline float getAncho() { return maxX - minX; }
	inline float getAlto() { return maxY - minY; }
	inline float getProfundo() { return maxZ - minZ; }
	inline void setScale(Vector3D s) { scale = s; }
	inline Vector3D getScale() { return scale; }
	//void setTexture(Textura* tex) {
		//for (Triangulo* t : triangulos)
			//t->setTextura(tex);
	//}
	inline void addTriangulo(Triangulo* t) {
		triangulos.push_back(t);
	}

	inline void SetColor(Vector3D c) {
		for (Triangulo* t : triangulos) {
			t->SetColor(c);
		}
	}
	inline void render() {
		Vector3D p = this->GetPosition();
		glPushMatrix();
		glTranslatef(p.GetX(), p.GetY(), p.GetZ());
		glRotatef(GetOrientation().GetX(), 1, 0, 0);
		glRotatef(GetOrientation().GetY(), 0, 1, 0);
		glRotatef(GetOrientation().GetZ(), 0, 0, 1);
		glScalef(scale.GetX(), scale.GetY(), scale.GetZ());

		for (Triangulo* t : triangulos)
			t->render();
		glPopMatrix();
	}

	void cargar(string& nombreFichero);

	Vector3D* parseVector3D(string& linea);
	Vector3D* parseVector2D(string& linea);

	Triangulo* parseTriangulo(string& linea);
	Triangulo* parseTriangulos(string& linea);
	void calculaExtremos(Vector3D* v);

};
