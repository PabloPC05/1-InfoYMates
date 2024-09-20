// Problema 12: Juego de dados

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;
/*
* la funcion comienza declarando las varables de los dados de ambos, luego se introducen a traves del teclado, y se crean 2 condicionales, 
*el primero si jorge gana, el segundo si ana gana y por ultimo un "si no" que imprime el EMPATE entre ambos
*/
void calculo() {
	int jorge1, jorge2, ana1, ana2;
	cin >> jorge1 >> jorge2 >> ana1 >> ana2;
	if (jorge1 + jorge2 > ana1 + ana2) cout << "JORGE " << jorge1 + jorge2 << " ANA " << ana1 + ana2 << "\n";
	else if (jorge1 + jorge2 < ana1 + ana2) cout << "ANA " << ana1 + ana2 << " JORGE " << jorge1 + jorge2 << "\n";
	else cout << "EMPATE " << ana1 + ana2 << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}