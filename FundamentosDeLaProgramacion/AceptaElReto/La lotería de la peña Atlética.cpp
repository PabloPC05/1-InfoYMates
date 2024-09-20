#include <iostream>
using namespace std;
void calculo() {
	int numdecimos, numimpares = 0, n = 0;
	cin >> numdecimos;
	for (int i = 0; i < numdecimos; i++) {
		int decimos;
		cin >> decimos; 
		numimpares = decimos % 2;
		n = n + numimpares;
	}
	cout << numdecimos - n << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}