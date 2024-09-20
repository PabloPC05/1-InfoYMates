#include <iostream>
using namespace std;
void calculo() {
	int insectos, spider, crustaceos, escalopendras, anillos; 
	cin >> insectos >> spider >> crustaceos >> escalopendras >> anillos; 
	cout << insectos * 6 + spider * 8 + crustaceos * 10 + escalopendras * (anillos * 2) << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
}