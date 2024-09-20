#include <iostream>
using namespace std;
void calculo() {
	int dias, horas, minutos, segundos,horastarea, minutostarea, segundostarea;

	cin >> dias >> horas >> minutos >> segundos, cin.ignore(':');

	int tiempodisponible = (dias * 24 * 3600) + (horas * 3600) + (minutos * 60) + segundos;
	
	for(int i = 0; )

	cin >> horastarea >> minutostarea >> segundostarea;

	int tiempotareas = (horastarea * 3600) + (minutostarea * 60) + segundostarea;

	if (tiempodisponible < tiempotareas) cout << "NO" << "\n";

	else if (tiempodisponible > tiempotareas) cout << "SI" << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}