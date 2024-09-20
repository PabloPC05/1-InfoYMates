// Problema 07: bandera alemana

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 

void resuelveCaso() {
    int w, h;                                           //declaramos las variables que almacenaran los datos de ancho y alto de la bandera
    cin >> w >> h;                                      //se introducen dichos valores a traves del teclado
    for (int i = 0; i < h / 3; i++) {                   //se realizan los bucles necesarios para representar las colores de las banderas de forma que se repiten cuantas veces sea necesario para llegar a la altura deseada
    cout << setw(w) << setfill('3') << '3' << "\n";     //se utiliza la instruccion setw y setfill para realizar el ancho de las banderas
    }
    for (int i = 0; i < h / 3; i++) {
    cout << setw(w) << setfill('5') << '5' << "\n";
        }
    for (int i = 0; i < h / 3; i++) {
    cout << setw(w) << setfill('7') << '7' << "\n";
    }
}

int main() {
    int numCasos;
    std::cin >> numCasos;                              // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();                                // LLamada a la función para tratar cada caso
    }
    return 0;
}
