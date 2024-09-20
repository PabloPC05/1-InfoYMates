#include <iostream>
using namespace std;
void calculo() {
	char z = ':';
	int a, b, c, d; 
	cin >> a >> z >> b >> z >> c >> z >> d;
	int tiempototal = (a * 24 * 3600) + b * 3600 + c * 60 + d;
	int tiempotareas = 0;
	int a2 = 0, b2 = 0, c2 = 1, d1 = 1;
	while (d1 == 1) {
		cin >> a2 >> z >> b2 >> z >> c2;
		int d2 = a2 * 3600 + b2 * 60 + c2;
		tiempotareas = tiempotareas + d2;
		if (a2 == 0 && b2 == 0 && c2 == 0) d1 = 0; 
	}
	if (tiempotareas < tiempototal) cout << "SI\n";
	else cout << "NO" << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; numCasos > i; i++) calculo();
}	