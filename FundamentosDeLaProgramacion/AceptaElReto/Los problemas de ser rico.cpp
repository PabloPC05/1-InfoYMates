#include <iostream>
using namespace std;
void calculo() {
	int n, max, d, capacidadtotal;
	cin >> n >> max >> d;
	capacidadtotal = (n * max) - ((n * (n - 1)) / 2 * d);
	cout << capacidadtotal << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos; 
	for (int i = 0; numCasos > i; i++) {
		calculo();
	}
	return 0;
}