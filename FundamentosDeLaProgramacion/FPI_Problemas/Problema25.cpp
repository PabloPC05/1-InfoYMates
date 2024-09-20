// Problema 25: Siguiente potencia de dos
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

/*
* Se introduce un número, se hace su logaritmo en base 2, se trunca y se suma 1 para obtener la siguiente potencia. 
* Luego 2 se eleva a ese resultado y se imprime en pantalla. 
*/
void calculo() {
	int num1;
	cin >> num1; 
	num1 = pow(2,trunc(log2(num1)) + 1);
	cout << num1 << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}