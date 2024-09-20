// Problema 14: Invirtiendo en bolsa

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
*hola que tal
*/
void calculo() {
	int numObjetos, max = 1, min = 100000000;
	cin >> numObjetos;	
	for (int i = 0; i < numObjetos; i++) {
		int num1;
		cin >> num1;
		if (num1 > max) max = num1;
		if (num1 < min) min = num1;
	}
	cout << max << ' ' << min << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}