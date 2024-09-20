#include <iostream>
#include <iomanip>
using namespace std;
void calculo() {
	int tiempototal, horas, minutos, segundos;
	cin >> tiempototal;
	horas = tiempototal / 3600;
	minutos = (tiempototal % 3600) / 60;
	segundos = (tiempototal % 3600) % 60;
	cout << setw(2) << setfill('0') << horas << ":" << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << segundos << "\n";

}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}