#include <iostream>
using namespace std;
void calculo() {
	int coste, dineroentregado;
	cin >> coste >> dineroentregado;
	int num1 = dineroentregado - coste; 
	if (dineroentregado < coste) cout << "DEBE " << coste - dineroentregado << "\n";
	else {
			cout << num1 / 200 << ' ';
			num1 = num1 % 200;
			cout << num1 / 100 << ' ';
			num1 = num1 % 100;
			cout << num1 / 50 << ' ';
			num1 = num1 % 50;
			cout << num1 / 20 << ' ';
			num1 = num1 % 20;
			cout << num1 / 10 << ' ';
			num1 = num1 % 10;
			cout << num1 / 5 << ' ';
			num1 = num1 % 5;
			cout << num1 / 2 << ' ';
			num1 = num1 % 2;
			cout << num1 / 1 << "\n";
	}
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}