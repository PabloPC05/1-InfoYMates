#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct tProducto {
    int ID;
    int unidades;
    void leerProducto();
    void escribirProducto();
    void addUnidades(int b);
};

using tListaProductos = vector<tProducto>;
struct tOperacion {
    string nombre;
    int ID;
    int unidades;
    void leerOperacion();
    void addProducto(tListaProductos& listaProductos);
};

using tListaOperaciones = vector<tOperacion>;

void tProducto::leerProducto() {
    cin >> ID >> unidades;
}

void tProducto::escribirProducto() {
    cout << ID << " " << unidades << '\n';
}

void tOperacion::leerOperacion() {
    cin >> nombre >> ID;
    if (nombre == "vender") unidades = -1;
    else cin >> unidades;
}

void leerCaso(tListaProductos& listaProductos, tListaOperaciones& listaOperaciones) {
    for (size_t i = 0; i < listaProductos.size(); i++) listaProductos.at(i).leerProducto();
    int aux;
    cin >> aux;
    listaOperaciones.resize(aux);
    for (size_t i = 0; i < listaOperaciones.size(); i++) listaOperaciones.at(i).leerOperacion();
}

int busquedaBinaria(tListaProductos& listaProductos, int ID) {
    int ini = 0, fin = listaProductos.size() - 1, mitad;
    while (ini < fin) {
        mitad = (ini + fin) / 2;
        if (listaProductos.at(mitad).ID == ID) return mitad;
        else if (listaProductos.at(mitad).ID < ID) ini = mitad + 1;
        else fin = mitad - 1;
    }
    return ini;
}

void tProducto::addUnidades(int b) {
    unidades += b;
}

void tOperacion::addProducto(tListaProductos& listaProductos) {
    tProducto aux;
    aux.ID = ID;
    aux.unidades = unidades;
    listaProductos.insert(listaProductos.begin() + busquedaBinaria(listaProductos, ID), aux);
}

void resuelveCaso(tListaOperaciones& tListaOperaciones, tListaProductos& tListaProductos) {
    for (size_t i = 0; i < tListaOperaciones.size(); i++) {
        if (tListaOperaciones.at(i).nombre == "vender" || tListaOperaciones.at(i).nombre == "comprar") tListaProductos.at(busquedaBinaria(tListaProductos, tListaOperaciones.at(i).ID)).addUnidades(tListaOperaciones.at(i).unidades);
        else tListaOperaciones.at(i).addProducto(tListaProductos);
    }
}

void imprimirCaso(tListaProductos& listaProductos) {
    for (size_t i = 0; i < listaProductos.size(); i++) listaProductos.at(i).escribirProducto();
    cout << "---\n";
}

bool entradaCentinela() {
    tListaProductos listaProductos;
    int numProductos;
    cin >> numProductos;
    if (numProductos == 0) return false;
    tListaOperaciones listaOperaciones;
    listaProductos.resize(numProductos);
    leerCaso(listaProductos, listaOperaciones);
    resuelveCaso(listaOperaciones, listaProductos);
    imprimirCaso(listaProductos);
    return true;
}

int main() {
    while (entradaCentinela());
    return 0;
}