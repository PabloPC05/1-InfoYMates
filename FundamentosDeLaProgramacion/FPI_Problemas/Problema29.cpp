// Problema 29: Los primos de Rodolfo

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/*
* Para identificar los no primos se dividen entre 2 o 3 y si su resto es 0. 
* En el caso de 2 y 3 su resto también da 0 por lo que en dichos casos, 
* se resta a la variable despues de que se haya sumado
*/

void calculo() {
	int numAmount, noPrimo = 0; 
	cin >> numAmount; 
	for (int i = 0; i < numAmount; i++) {
		int num; 
		cin >> num; 
		if (num % 2 == 0 || num % 3 == 0) noPrimo++;
		if (num == 2 || num == 3) noPrimo--;
	}
	cout << "PRIMOS: " << numAmount - noPrimo << ", NO PRIMOS: " << noPrimo << "\n";
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}