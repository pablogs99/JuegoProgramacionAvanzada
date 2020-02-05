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
	void agregar(int puntos) {
		ofstream addFile("puntos.txt", ios::app);

		if (addFile.is_open()) {
			cout << "Nombre:" << endl;
			cin >> nombre;

			addFile << nombre << " " << puntos << endl;
		}
		addFile.close();
	}
	void eliminarMinVec() {

		for (int i = 0; i < puntosVector.size(); i++)
		{
			if (puntosVector[i] < puntosVector[0]) {
				swap(puntosVector[0], puntosVector[i]);
				swap(nombres[0], nombres[i]);
			}
		}
		puntosVector.erase(puntosVector.begin());
		nombres.erase(nombres.begin());

	}
	void ordenarRanking() {
		for (size_t i = 1; i < puntosVector.size(); ++i) {
			for (size_t j = 0; j < puntosVector.size() - 1; ++j) {
				if (puntosVector[j] < puntosVector[i]) {
					swap(puntosVector[j], puntosVector[i]);
					swap(nombres[j], nombres[i]);
				}
			}
		}
	}

	void agregarFichero() {
		ofstream addFile("puntos.txt");
		if (addFile.is_open()) {
			for (int i = 0; i < nombres.size(); i++) {
				addFile << nombres[i] << " " << puntosVector[i] << endl;
			}
		}
		addFile.close();
	}
	void addToVector() {

		ifstream readFile("puntos.txt");

		while (readFile >> nombre >> points) {
			nombres.push_back(nombre);
			puntosVector.push_back(points);
		}
	}

	void visualizar() {

		ifstream readFile("puntos.txt");
		string text;
		if (readFile.is_open()) {
			cout << "RANKING: " << endl;
			while (getline(readFile, text)) {
				cout << text << endl;
			}
		}
		readFile.close();
	}

	void crearRanking(int puntos) {

		agregar(puntos);
		addToVector();
		if (nombres.size() > 5) {
			eliminarMinVec();
		}
		ordenarRanking();
		agregarFichero();
		visualizar();
	}
};
