#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct tPalabra {
	string palabra;
	vector <int> posiciones;
};
using tListaPalabras = vector <tPalabra>;
using listaInt = vector <int>;

int busquedaBinaria(const tListaPalabras& listaPalabras, const string& s) {
	int ini = 0, fin = listaPalabras.size() - 1, mitad;
	while (ini <= fin) {
		mitad = (ini + fin) / 2;
		if (listaPalabras[mitad].palabra == s) return mitad;
		else if (listaPalabras[mitad].palabra < s) ini = mitad + 1;
		else fin = mitad - 1;
	}
	return ini;
}

bool findIndex(const listaInt& lista, const int& t) {
	for (size_t i = 0; i < lista.size(); i++) {
		if (lista[i] == t) return false;
	}
	return true;
}

void generarPalabras(tListaPalabras& listaPalabras, string s, int linea) {
	while (s.size() > 0) {
		int pos = s.find(' ');
		if (pos == -1) {
			pos = s.size();
		}
		string palabra = s.substr(0, pos);
		s.erase(0, pos + 1);
		if (palabra.size() <= 2) {
			continue;
		}
		int i = busquedaBinaria(listaPalabras, palabra);
		if (i >= listaPalabras.size() || listaPalabras.at(i).palabra != palabra) {
			tPalabra nuevaPalabra;
			nuevaPalabra.palabra = palabra;
			nuevaPalabra.posiciones.push_back(linea);
			listaPalabras.insert(listaPalabras.begin() + i, nuevaPalabra);
		}
		else if (findIndex(listaPalabras.at(i).posiciones, linea)) {
			listaPalabras.at(i).posiciones.push_back(linea);
		}
	}
}

void stringToLower(string& s) {
	for (size_t i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
}

void imprimirResultado(tListaPalabras& listaPalabras) {
	for (size_t i = 0; i < listaPalabras.size(); i++) {
		cout << listaPalabras[i].palabra << " ";
		for (size_t j = 0; j < listaPalabras[i].posiciones.size(); j++) {
			cout << listaPalabras[i].posiciones[j] + 1 << " ";
		}
		cout << endl;
	}
	cout << "---" << endl;
}

bool centinela() {
	int numLineas;
	cin >> numLineas;
	if (numLineas == 0) return false;
	cin.ignore();
	tListaPalabras listaPalabras;
	for (int i = 0; i < numLineas; i++) {
		string s;
		getline(cin, s);
		stringToLower(s);
		generarPalabras(listaPalabras, s, i);
	}
	imprimirResultado(listaPalabras);
	return true;
}

int main() {
	while (centinela());
	return 0;
}