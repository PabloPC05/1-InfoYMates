// Problema 34: De binario a decimal

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

/*
* El string se recorre de manera que dado que va a entrar un 0 o 1 se le resta el 0 para obtener el valor que queremos 
* pero en ASCII y que asi pueda ser guardado en una variable int. 
* Para sacar el decimal se multiplica el 1 o 0 obtenido por una variable dos que se va multiplicando continuamente por 2. 
*/

void calculo() {
	string binario; 
	cin >> binario; 
	long long int length = binario.size() - 1, decimal = 0, dos = 1, num = 0;
	for (long long int i = length; i >= 0; i--) {
		decimal = decimal + ((binario[i] - '0')*dos);
		dos = 2 * dos; 
	}
	cout << decimal << "\n";
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}