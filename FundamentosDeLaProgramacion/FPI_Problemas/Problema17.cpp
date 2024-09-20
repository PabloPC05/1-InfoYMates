// Problema 16: Juego de dados II

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/*
* La funcion comienza de manera que se introduce la palabra para luego en un bucle que dura tantas veces como letras tenga la palabra 
haga que en caso de que haya una vocal se "sume" un 1, y que luego la suma de cada una de las vocales de 5 imprima un SI	
*/

void calculo() {
	string palabra; 
	cin >> palabra;
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	for (int j = 0; j < palabra.size(); j++) {
		if (palabra.at(j) == 'a') a = 1;
		if (palabra.at(j) == 'e') e = 1;
		if (palabra.at(j) == 'i') i = 1;
		if (palabra.at(j) == 'o') o = 1;
		if (palabra.at(j) == 'u') u = 1;
	}
	if (a == 1 && e == 1 && i == 1 && o == 1 && u == 1) cout << "SI" << "\n";
	else cout << "NO" << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}