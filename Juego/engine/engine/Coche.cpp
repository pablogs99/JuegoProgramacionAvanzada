#include "Coche.h"

vector<string> split(string& s, char delimiter = ' ') {
	vector<string> tokens;
	string token;
	istringstream iss(s);
	while (getline(iss, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}
Modelo::~Modelo() {
	// TODO Auto-generated destructor stub
}

Triangulo* Modelo::centrar(Triangulo* t) {
	Vector3D centro(minX + getAncho() / 2.0, minY + getAlto() / 2.0, minZ + getProfundo() / 2);
	Vector3D p0 = t->getP0();
	Vector3D p1 = t->getP1();
	Vector3D p2 = t->getP2();
	return(new Triangulo(p0 - centro, p1 - centro, p2 - centro));
}

Vector3D* Modelo::parseVector3D(string& linea) {
	float x, y, z;

	istringstream ss(linea);
	string s;
	ss >> s;//line type
	ss >> x;
	ss >> y;
	ss >> z;
	return new Vector3D(x, y, z);
}
Vector3D* Modelo::parseVector2D(string& linea) {
	float x, y, z;

	istringstream ss(linea);
	string s;
	ss >> s;//line type
	ss >> x;
	ss >> y;
	return new Vector3D(x, y, 0);
}

Triangulo* Modelo::parseTriangulo(string& linea) {
	istringstream ss(linea);
	int iv0, iv1, iv2;
	ss >> iv0;
	ss >> iv1;
	ss >> iv2;
	iv0--;
	iv1--;
	iv2--;
	Vector3D p0 = *vertices[iv0];
	Vector3D p1 = *vertices[iv1];
	Vector3D p2 = *vertices[iv2];
	Triangulo* t = new Triangulo(p0, p1, p2);
	return t;
}
Triangulo* Modelo::parseTriangulos(string& linea) {
	vector<string> vs = split(linea);
	if (vs.size() != 4)
		throw runtime_error("Not triangle detected in parseTriangulos from model.cpp");
	if (vs[0] != "f")
		throw runtime_error("Not face line in parseTriangulos from model.cpp");
	vector<string> vs0 = split(vs[1], '/');
	vector<int> vid0;
	for (string s : vs0) {
		int i = stoi(s);
		vid0.push_back(i - 1);
	}
	vector<string> vs1 = split(vs[2], '/');
	vector<int> vid1;
	for (string s : vs1) {
		int i = stoi(s);
		vid1.push_back(i - 1);
	}
	vector<string> vs2 = split(vs[3], '/');
	vector<int> vid2;
	for (string s : vs2) {
		int i = stoi(s);
		vid2.push_back(i - 1);
	}
	Vector3D p0 = *vertices[vid0[0]];
	Vector3D p1 = *vertices[vid1[0]];
	Vector3D p2 = *vertices[vid2[0]];
	Triangulo* t = new Triangulo(p0, p1, p2);
	if (vid0.size() > 1) {
		Vector3D t0 = *textures[vid0[1]];
		Vector3D t1 = *textures[vid1[1]];
		Vector3D t2 = *textures[vid2[1]];
		t->setT0(t0);
		t->setT1(t1);
		t->setT2(t2);
	}
	if (vid0.size() == 3) {
		Vector3D n0 = *normals[vid0[2]];
		Vector3D n1 = *normals[vid1[2]];
		Vector3D n2 = *normals[vid2[2]];
		t->setN0(n0);
		t->setN1(n1);
		t->setN2(n2);
	}
	return t;
}
void Modelo::calculaExtremos(Vector3D* v) {
	float x = v->getX();
	float y = v->getY();
	float z = v->getZ();
	maxX = fmax(maxX, x);
	maxY = fmax(maxY, y);
	maxZ = fmax(maxZ, z);
	minX = fmin(minX, x);
	minY = fmin(minY, y);
	minZ = fmin(minZ, z);
}

void Modelo::cargar(string& nombreFichero) {
	maxX = maxY = maxZ = -1e40;
	minX = minY = minZ = 1e40;

	std::string linea;

	ifstream ficheroModeloObj(nombreFichero.c_str());
	if (ficheroModeloObj.is_open()) {
		while (getline(ficheroModeloObj, linea)) {
			//getline (ficheroModeloObj,linea);
			if (linea[0] == 'v') {
				if (linea[1] == 't') {
					//Texture detected
					Vector3D* v = parseVector2D(linea);
					textures.push_back(v);
				}
				else if (linea[1] == 'n') {
					//Normal detected
					Vector3D* v = parseVector3D(linea);
					normals.push_back(v);
				}
				else if (linea[1] == ' ') {
					//Vertex detected
					Vector3D* v = parseVector3D(linea);
					calculaExtremos(v);
					vertices.push_back(v);
				}
				else {
					cout << "vertice no detectado" << endl;
				}
			}
			Vector3D centro(minX + getAncho() / 2.0, minY + getAlto() / 2.0, minZ + getProfundo() / 2);
			if (linea[0] == 'f') {
				Triangulo* t = parseTriangulos(linea);
				triangulos.push_back(t);
				//triangulos.push_back(centrar(t));
				//delete t;
			}
		}
		ficheroModeloObj.close();
	}
	else {
		cout << "Fichero " + nombreFichero + " no existe." << endl;
	}

}
