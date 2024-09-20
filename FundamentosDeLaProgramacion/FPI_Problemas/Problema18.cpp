// Problema 18: Fuera las mayúsculas

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/*
* La funcion comienza introduciendo la palabra y cada caracter de la palabra se asigna 
*a un char que posteriormente se imprime en pantalla tras pasar por la funcion tolower
*/

void calculo() {	
	string palabra;
	cin >> palabra; 
	for (int i = 0; i < palabra.size(); i++) {
	char a = palabra.at(i);
	cout << (char)tolower(a);
	}
	cout << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}