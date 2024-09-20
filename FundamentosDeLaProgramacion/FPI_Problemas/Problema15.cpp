//Problema 15: Años bisiestos

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
* Todo año bisiesto es divisible entre 4 y no sea divisible entre 100 o sea divisible entre 400
* por lo que si el resto de la division es 0 se trata de un año bisiesto, si no, no. 
*/
void calculo() {
	int ano = 0; 
	cin >> ano;
	if (ano % 4 == 0 && (!(ano % 100 == 0) || ano % 400 == 0)) cout << "SI" << "\n";
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