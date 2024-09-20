// Problema 37: Suma lo mismo

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
using namespace std;
using tListaDeNums = int[1000];

int calculo() {
	int realNumDeNums, suma = 0, arrayNumDeNums;
	cin >> realNumDeNums;
	arrayNumDeNums = realNumDeNums -1;
	tListaDeNums ListaDeNums;
	for (int i = 0; i < realNumDeNums; i++) { //se introducen todos los numeros de la lista
		cin >> ListaDeNums[i];
	}
	while(arrayNumDeNums > -1){//se comprueba la condicion requerida empezando por el final para ver si la suma de los numeros de la derecha de cada uno sea el mismo
		if (suma == ListaDeNums[arrayNumDeNums]){
			return arrayNumDeNums; // en caso de que se cumpla se devuelve la posicion del numero
		} 
		suma += ListaDeNums[arrayNumDeNums];
		arrayNumDeNums--;
	}
	return -1;// en caso de que no, se devuelve un -1, caso imposible pues no existen posiciones negativas
}
// he intentado hacerlo con una funcion booleana para hacerlo, el problema es que cada vez que lo ejecutaba como tenia que declarar la variable numPos en maiin, 
// cada vez que volvia a main con el true o el false, me volvia a coger el valor por defecto que tenia el numPos en main, en lugar de tener el que deberia tener asignado en calculo()

int main() {
	int numCasos, numPos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		numPos = calculo();
		if (numPos != -1) cout << numPos << "\n";
		else cout << "NO\n";
	}
	return 0;
}