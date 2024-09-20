// Problema 40: Lucky Lucke en busca del culpable

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
using namespace std;

// Se realiza el algoritmo de busqueda binaria para encontrar la posicion del sospechoso.
int buscaIz(int numCasos, int hSospechoso) {
    vector<int> alturasSospechosos(numCasos);    
    int inicio = 0, final = numCasos-1, posicion, posFound = -1;
    for(int i = 0; i <= final; i++){
        cin >> alturasSospechosos[i];
    }
    while (inicio <= final){
        posicion = (inicio + final) / 2;
        if (alturasSospechosos[posicion] == hSospechoso) {
            posFound = posicion;
            final = posicion - 1;
        }
        else if (alturasSospechosos[posicion] < hSospechoso){
            inicio = posicion + 1;
        }
        else {
            final = posicion - 1;
        }
    }
    return posFound;
}

bool resuelveCaso(){
    int numCasos, hSospechso;
    cin >> numCasos >> hSospechso; 
    if(!cin) return false;
    int posSospechoso = buscaIz(numCasos, hSospechso);
    if (posSospechoso != -1) cout << posSospechoso << "\n";
    else cout << "NO EXISTE\n";
    return true;
}

int main() {
    while(resuelveCaso())
        ; 
	return 0;
}