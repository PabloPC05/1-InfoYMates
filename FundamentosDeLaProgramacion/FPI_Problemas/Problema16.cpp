// Problema 16: Juego de dados II

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
* La funcion comienza declarando las variables de los dados de los 3 e introduciendolas en el teclado
* luego se suman y se comparan segun los posibles casos
*/

void calculo() {
	int jorge1, jorge2, ana1, ana2, amigo1, amigo2, jorge, ana, amigo;
	cin >> jorge1 >> jorge2 >> ana1 >> ana2 >> amigo1 >> amigo2;
	jorge = jorge1 + jorge2;
	ana = ana1 + ana2;
	amigo = amigo1 + amigo2;

	if (ana == jorge && jorge == amigo) cout << "EMPATE AMIGO ANA JORGE " << amigo;
	else if (ana == jorge && ana > amigo) cout << "EMPATE ANA JORGE " << ana;
	else if (ana < jorge && jorge == amigo) cout << "EMPATE AMIGO JORGE " << amigo;
	else if (amigo == ana && ana > jorge) cout << "EMPATE AMIGO ANA " << amigo;
	else if (amigo > jorge && amigo > ana) cout << "AMIGO " << amigo;
	else if (ana > jorge && ana > amigo) cout << "ANA " << ana;
	else cout << "JORGE " << jorge;
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