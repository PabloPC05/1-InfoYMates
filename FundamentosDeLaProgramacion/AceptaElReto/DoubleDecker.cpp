#include <iostream>
using namespace std;
void calculo() {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	int rango = c * (c + 1) / 2 + a +1;
	cout << rango << "\n";
}
int main() {
	int numCasos; 
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) calculo();
}