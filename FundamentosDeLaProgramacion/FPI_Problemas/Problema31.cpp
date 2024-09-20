// Problema 31: Numeros que suman lo mismo

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/*
* Comienza pidiendo el numero de numeros a introducir (bucle) y luego el numero cuyos digitos se sumaran de manera que el resto de la division del n� entre 10 
* sea lo que hay qe estar sumando y que el numero luego se convierta en el mismo entre 10, hasta que dicho numero sea 0. 
* La comparacion con los otros numeros sigue el mismo proceso pero se guarda el numero antes por si cumple la propiedad de sus la suma
*/

int sumaDigitos(int num) {
	int sumanum = 0;
	while (num != 0) {
		sumanum = sumanum + num % 10;
		num = num / 10;
	}
	return sumanum; 
}
void calculo() {
	int numAmount, num, numrelevant;
	cin >> numAmount >> num;
	numrelevant = sumaDigitos(num);
	for (int i = 0; i < numAmount; i++) { 
		cin >> num;  
		sumaDigitos(num);
		if (sumaDigitos(num) == numrelevant) cout << num << ' ';
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