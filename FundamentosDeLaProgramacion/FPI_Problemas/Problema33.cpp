// Problema 31: Numeros que suman lo mismo

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;
void calculo(int num) {
	int aux = 0, inv = 0, multiplicador = 10;
	while (num != 0) {
		aux = num % 10;
		num = num / 10;
		inv = inv * 10 + aux;
	}
	cout << inv << "\n";
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) return false;
	else calculo(num);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}