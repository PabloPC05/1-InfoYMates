#include <iostream>
using namespace std;
void calculo() {
	int h, v, cerillas; 
	cin >> h >> v;
	cerillas = h + 2 * h * v + v;
	cout << cerillas << "\n";
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}