// Problema 4: Calcular las horas, minutos y segundos
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
using namespace std;

/*
* La funcion comienza declarando las variables de tiempototal, y despues las de la salida.
*El calculo se realiza prinicpalmente haciendo uso del operador modulo y como salida se utiliza el setw y el setfill que imprimiran 0s en pantalla cuando no haya o cuando el n�mero sea menor de 10
*/
void calculo() {
	int tiempototal, horas, minutos, segundos;
	cin >> tiempototal;
	horas = tiempototal / 3600;
	minutos = (tiempototal % 3600) / 60;
	segundos = (tiempototal % 3600) % 60;
	cout << setw(2) << setfill('0') << horas << ':' << setw(2) << setfill('0') << minutos << ':' << setw(2) << setfill('0') << segundos << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}