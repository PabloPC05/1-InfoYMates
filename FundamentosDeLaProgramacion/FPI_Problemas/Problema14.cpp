// Problema 14: Invirtiendo en bolsa

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
*La funcion comienza declarando las variables del numero de numeros, el maximo y el minimo y sus posiciones, luego se introducen el numero de numeros. 
* El bucle se encarga de leer los numeros y en el primer momento, almacenar los primeros como los maximos y minimos para luego compararlos con los siguientes. 
* La posicion del maximo y el minimo se guarda utilizando la variable i del bucle. 
*/
void calculo() {
	int numObjetos, max=0, min=0, maxpos, minpos;
	cin >> numObjetos;
	for (int i = 1; i <= numObjetos; i++) {
		int num1;
		cin >> num1;
		if (num1 > max || i==1 ){
			max = num1;
			maxpos = i;
		}
		if (num1 <= min || i==1) {
			min = num1;
			minpos = i;
		}
	}
	cout << max << ' ' << maxpos << ' ' <<  min << ' ' << minpos << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}