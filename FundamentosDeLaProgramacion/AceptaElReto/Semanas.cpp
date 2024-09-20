#include <iostream>
using namespace std;
void calculo() {
	int diasdelano, diasdelasemana, diainicio, caso1, caso2;
	cin >> diasdelano >> diasdelasemana >> diainicio;
	if (diainicio == 1) cout << diasdelano / diasdelasemana << "\n";
	else if (diainicio != 1) cout << (diasdelano - (diasdelasemana - (diainicio - 1))) / diasdelasemana << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}