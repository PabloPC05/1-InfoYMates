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
* Primero se introducen los dos primeros numeros, cuya resta sera la maxima y minima de partida. 
* Luego se pedirá el tercer número para asegurarse de que no es el 0 para comenzar el bucle. En el bucle se producira la resta y se comparara con los valores guardados
* Una vez terminada se guarda el valor del segundo numero como si fuera el tercero y se introduce el cuarto. Así hasta que el programa encuentre un 0. 
*/

void calculo() {
	int num2, num1, resta, restamin, restamax;
	cin >> num1 >> num2;
	resta = num1 - num2;
	if (resta < 0) resta = -resta;
	restamin = resta;
	restamax = resta;
	cin >> num1; 
	while (num1 != 0){
		resta = num1 - num2;	
		if (resta < 0) resta = -resta;
		if (resta > restamax) restamax = resta;
		else if (resta < restamin) restamin = resta;
		num2 = num1;
		cin >> num1;
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