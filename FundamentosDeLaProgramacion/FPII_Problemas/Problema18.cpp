#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool centinela() {
	int valorInf, valorSup, valor; 
	cin >> valorInf >> valorSup; 
	if(valorInf == 0 && valorSup == 0) return false;
	srand(time(NULL));
	while (valorSup - valorInf > 0) {
		valor = valorInf + rand() % (valorSup - valorInf + 1);
		cout << '?' << ' ' << valor << endl;
		char respuesta;
		cin.ignore();
		cin >> respuesta; 
		if (respuesta == '>') {
			valorInf = valor + 1;
		}
		else {
			valorSup = valor;
		}
	}
	cout << "Respuesta: " << valorInf << endl;
	cin.ignore();
	return true;
}

int main() {
	while (centinela());
	return 0; 
}