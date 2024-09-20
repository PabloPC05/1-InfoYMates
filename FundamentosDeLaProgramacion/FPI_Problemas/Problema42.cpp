// Problema 42: Comprobar si todos los elementos de un array estan contenidos en otro. Version ineficiente

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
using namespace std;
const int MAX = 1000;

bool calculo() {
	int a1[MAX], a2[MAX], numTrue = 0, numNums1,numNums2;
	cin >> numNums1;
	for(int i = 0; i < numNums1; i++){
		cin >> a1[i];
	}
	cin >> numNums2;
	for(int i = 0; i < numNums2; i++){
		cin >> a2[i];
	}
	for(int k = 0; numNums1 > k; k++){
		for(int l = 0; numNums2 > l; l++){
			if(a1[k] == a2[l]) numTrue++;
		}
	}
	if(numTrue == numNums1) return true;
	else return false;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		if (calculo()) cout << "SI\n";
		else cout << "NO\n";
	}
	return 0;
}