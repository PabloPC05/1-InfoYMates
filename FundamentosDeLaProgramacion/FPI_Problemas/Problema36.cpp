// Problema 36: Ultima vez que...

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int campeonMasReciente(int numCasos, string vencedor) {
	vector<string> vencedores(numCasos);
	int vecesCampeon = 0;
	for(int i = numCasos-1; i >= 0; i--) cin >> vencedores[i];
	while(vencedores[vecesCampeon] != vencedor && vecesCampeon < numCasos){
		vecesCampeon++;
	}
	if (vencedores[vecesCampeon] == vencedor) return vecesCampeon+1;
	return -1;
}

bool resuelveCaso(){
	int numCasos;
	string vencedor;
	cin >> numCasos;
    if (numCasos == 0) return false; 
	cin >> vencedor;
    int solucion = campeonMasReciente(numCasos, vencedor);
	if (solucion != -1) cout << solucion << "\n";
	else cout << "NUNCA\n";
	return true;
}

int main() {
    while(resuelveCaso())
    ;
	return 0;
}