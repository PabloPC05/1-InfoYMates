// Problema 08: bandera italiana

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void resuelveCaso() {
    int w, h;                                                                                                                                   //declaramos las variables que almacenaran el ancho y el alto de la bandera
    cin >> w >> h;                                                                                                                              //se dan los valores a las variables a traves del teclado
    for (int i = 0; i < h; i++) {                                                                                                               //se declara un bucle que se repetira hasta que se alcance la altura deseada    
        cout << setw(w / 3) << setfill('3') << '3' << setw(w / 3) << setfill('5') << '5' << setw(w / 3) << setfill('7') << '7' << "\n";         //el bucle consistira en escribir las columnas en filas en orden 3-5-7
    }
}

int main() {
    int numCasos;
    std::cin >> numCasos;                                                                                                                       // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();                                                                                                                         // LLamada a la función para tratar cada caso
    }
    return 0;
}
