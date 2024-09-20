// Problema 11: De compras

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
* Se declaran las variables del numero de objetos, su precio, y el total de la compra, se introducen los dos primeros datos
* se calcula el total de la compra sumando cada uno de los valores y se imprime en pantalla caca
*/

void calculo() {
    int numObjetos,precioObjeto, precioTotal = 0;
    cin >> numObjetos;
    for (int i = 0; numObjetos > i; i++) {
        cin >> precioObjeto; 
        precioTotal += precioObjeto;
    }
    cout << precioTotal << "\n";
 }

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        calculo();
    }
    return 0;
}