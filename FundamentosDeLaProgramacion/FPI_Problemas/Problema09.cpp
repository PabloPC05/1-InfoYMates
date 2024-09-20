// Problema 09: Marco de un cuadro

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
* Funcion que imprime en la pantalla las partes superior e inferior del marco dado que son identicas
*/
void margenes(int margenh, int wmarco) {
    for (int i = 0; i < margenh; i++) {
        cout << setw(wmarco) << setfill('*') << '*' << "\n";
    }
}

/*
* Función que declara las variables, pide por el teclado los datos que almcaneran y se encarga de hacer el cuerpo del cuadro/marco.
*/
void resuelveCaso() {
    int wmarco, hmarco, wcuadro, hcuadro, margenh, margenw;
    cin >> wmarco >> hmarco >> wcuadro >> hcuadro;
    margenh = (hmarco - hcuadro) / 2;
    margenw = (wmarco - wcuadro) / 2;
    margenes(margenh, wmarco);
    for (int i = 0; i < hcuadro; i++) {
        cout << setw(margenw) << setfill('*') << '*' << setw(wcuadro) << setfill(' ') << ' ' << setw(margenw) << setfill('*') << '*' << "\n";
    }
    margenes(margenh, wmarco);
}

int main() {
    int numCasos;
    std::cin >> numCasos; // lectura del número de casos
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso(); // LLamada a la función para tratar cada caso
    }
    return 0;
}