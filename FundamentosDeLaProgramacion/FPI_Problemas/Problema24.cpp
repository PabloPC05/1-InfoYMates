// Problema 24: Por encima de la media I
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/*
* La funcion comienza introduciendo la altura del primer chico, y posteriormente se comparan con los del resto. 
* Se suman todos los niños y al finalizar el bucle, si es positiva es mayor a la media y al contrario si es negativa. 
*/

void calculo() {
	int hboy, hboy2, i = 0, aux;
	cin >> hboy >> hboy2; 
	while (hboy2 != 0) {
		aux = hboy - hboy2; 
		i = i + aux; 
		cin >> hboy2;
	}
	if (i > 0 || i == 0) cout << "MAYOR\n";
	else cout << "MENOR\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}