#include <iostream>
using namespace std;
void calculo() {
	int piso, escalones, pisoscomplete, escalonescomplete;
	cin >> piso >> escalones >> pisoscomplete >> escalonescomplete;
	cout << (pisoscomplete * escalones) + escalonescomplete << ' ' <<(piso * escalones) + ((pisoscomplete * escalones) + escalonescomplete) << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; numCasos > i; i++) calculo();
}