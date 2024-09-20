// Problema 23: Calculo del dividendoimo comun divisor
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void calculo(int divisor, int dividendo) {
	int aux = 0, resto = 1;
	if (divisor > dividendo) {
		aux = dividendo; 
		dividendo = divisor;
		divisor = aux;
	}
	while (resto != 0) {
		resto = dividendo % divisor; 
		if (resto == 0) aux = divisor;
		else {
			dividendo = divisor;
			divisor = resto;
		}
	}
	cout << aux << "\n";
}

int main() {
	int divisor, dividendo; 
	cin >> divisor >> dividendo;
	while (divisor != 0 && dividendo != 0) {
		calculo(divisor, dividendo);
		cin >> divisor >> dividendo; 
	}
	return 0;
}