// Problema 35: Comenzando con arrays

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
using tListaDeNums = int [1000];

/*
* Coge los números los almacena en un array y si son positivos o negativos los suma en una variable y luego se usa un for para imprimir todos los numeros cambiados de signo
*/

void calculo() {
    tListaDeNums ListaDeNums; 
    int numDNums = 0, numsNegativos = 0, numsPositivos = 0; 
    cin >> numDNums; 
    for (int i = 0; i < numDNums; i++){
        cin >> ListaDeNums[i];
        if (ListaDeNums[i] >= 0) numsPositivos = numsPositivos + ListaDeNums[i]; 
        else numsNegativos = numsNegativos + ListaDeNums[i];
    }
    cout << numsPositivos << ' ' << numsNegativos << "\n";
    for (int i = 0; i < numDNums; i++){
        cout << -ListaDeNums[i] << ' '; 
    }
    cout << "\n";
}



int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}