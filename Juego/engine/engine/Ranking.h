#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <time.h>  
using namespace std;

class Ranking
{
private:
	string nombre;
	vector<string> nombres;
	vector<double> puntosVector;
	double points;

public:
	Ranking() {}
	void agregar(int puntos);
	void addToVector();
	void eliminarMinVec();
	void ordenarRanking();
	void agregarFichero();
	void visualizar();
	void crearRanking(int puntos);
};
