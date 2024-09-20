// Problema 27: Diferencia maxima y minima

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/*
* Primero se introducen los dos primeros numeros se hace su resta y el valor absoluto de dicho valor se asigna como minimo y máximo
* Luego se comienza un bucle en el que se produce la resta con un nuevo numero, se hace su valor absoluto y se compara con los valores guardados
* Por último se asigna el valor del numero a la auxiliar para restarlo en el siguiente bucle.
*/

void calculo() {
	int numdNum, num1, aux, resta, restamin, restamax;
	cin >> numdNum >> num1 >> aux;
	resta = aux - num1; 
	if (resta < 0) resta = -resta;
	restamin = resta; 
	restamax = resta;
	for (int i = 2; i < numdNum; i++) {
		cin >> num1;
		resta = num1 - aux; 
		if (resta < 0) resta = -resta;
		if (resta > restamax) restamax = resta; 
		if (resta < restamin) restamin = resta; 
		aux = num1;
	}
	cout << restamax << ' ' << restamin << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}