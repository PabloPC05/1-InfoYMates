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
const int MAX = 300000;

bool estaContenido(int a1[], int a2[], int numNums2, int k, int& l) {
	while (l < numNums2 && a1[k] >= a2[l]) {
		if (a1[k] == a2[l]) {
			l++;
			return true;
		}
		l++;
	}
	return false;
}

bool calculo() {
	int a1[MAX], a2[MAX], numNums1, numNums2, k = 0, l = 0;
	cin >> numNums1;
	for(int i = 0; i < numNums1; i++){
		cin >> a1[i];
	}
	cin >> numNums2;
	for(int i = 0; i < numNums2; i++){
		cin >> a2[i];
	}
    sort(a1, a1+numNums1);
	sort(a2, a2+numNums2);
    if (numNums1 > numNums2) return false;
    while(k < numNums1){
        if(estaContenido(a1,a2,numNums2, k, l)) k++;
        else return false;
    }
    return true;
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