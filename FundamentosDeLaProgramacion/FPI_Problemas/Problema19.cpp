// Problema 19: Hablando del reves 

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
* La funcion comienza con un string en el que se introduce la oracion, 
* a continuacion se imprime en pantalla el numero de caracteres
* y posteriormente la frase dada la vuelta en mayusculas 
*/

void calculo() {
	string oracion;
	getline(cin, oracion);
	cout << oracion.size() << ' ';
	for (int j = oracion.size()-1; j >= 0; j--) {
		char a = oracion[j];
		cout << (char)toupper(a);
	}
	cout << "\n";
}

int main() {
	int numCasos;
	string dummyString;
	cin >> numCasos;
	getline(cin, dummyString);
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}