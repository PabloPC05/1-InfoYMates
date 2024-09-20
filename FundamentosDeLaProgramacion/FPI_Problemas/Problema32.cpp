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
* Primero se lee un string para dar lugar a un bucle 
* que lee el numero en busca del caracter que se quiere buscar
*/

void calculo() {
	string num;
	char numrepetido; 
	int vecesrepetido = 0;
	cin >> num >> numrepetido; 
	for (int i = 0; i < num.size(); i++){
		if (numrepetido == num[i]) vecesrepetido++;
	}
	cout << vecesrepetido << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}