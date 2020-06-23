#include "Ranking.h"

//Agregamos el nombre y los puntos en un fichero
void Ranking::agregar(int puntos) {
	ofstream addFile("puntos.txt", ios::app);

	if (addFile.is_open()) {
		cout << "Nombre:" << endl;
		cin >> nombre;

		addFile << nombre << " " << puntos << endl;
	}
	addFile.close();
}

//Leemos el fichero e introducimos los valores a un vector de strings(nombres) y a uno de doubles
void Ranking::addToVector() {

	ifstream readFile("puntos.txt");

	while (readFile >> nombre >> points) {
		nombres.push_back(nombre);
		puntosVector.push_back(points);
	}
}

//Obtenemos el elemento de menos puntos y lo eliminamos
void Ranking::eliminarMinVec() {

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

//Ordenamos los vectores de mayor a menor
void Ranking::ordenarRanking() {
	for (size_t i = 1; i < puntosVector.size(); ++i) {
		for (size_t j = 0; j < puntosVector.size() - 1; ++j) {
			if (puntosVector[j] < puntosVector[i]) {
				swap(puntosVector[j], puntosVector[i]);
				swap(nombres[j], nombres[i]);
			}
		}
	}
}

//Volvemos a meter los elementos de los vectores en el fichero
//No le metemos ios::app para que pueda sobreescribir lo que habia ya
void Ranking::agregarFichero() {
	ofstream addFile("puntos.txt");
	if (addFile.is_open()) {
		for (int i = 0; i < nombres.size(); i++) {
			addFile << nombres[i] << " " << puntosVector[i] << endl;
		}
	}
	addFile.close();
}

//Leer el fichero
void Ranking::visualizar() {

	ifstream readFile("puntos.txt");
	string text;
	if (readFile.is_open()) {
		cout << "RANKING - Top 5: " << endl;
		while (getline(readFile, text)) {
			cout << text << endl;
		}
	}
	readFile.close();
}

//Metodo que usa los otros metodos anteriores ordenados para crear el ranking
void Ranking::crearRanking(int puntos) {

	agregar(puntos);
	addToVector();
	if (nombres.size() > 5) { //Si los jugadores son mayores que 5, eliminamos el jugador con menos puntos
		eliminarMinVec();
	}
	ordenarRanking();
	agregarFichero();
	visualizar();
}