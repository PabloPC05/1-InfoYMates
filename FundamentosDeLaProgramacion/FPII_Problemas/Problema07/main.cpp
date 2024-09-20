#include "problema7.h"
using namespace std;

void escogeOpcion(matriz& m){
    int numOpciones;
    string opcion; 
    cin >> numOpciones;
    for(int i = 0; i < numOpciones; i++){
        cin >> opcion;
        if(opcion == "filas") m.intercambiarFilas();
        else if(opcion == "columnas") m.intercambiarColumnas();
        else if(opcion == "cruz") m.rellenarCruz(); 
        else if(opcion == "rotarFila") m.rotarFila();
        else if(opcion == "rotarCol") m.rotarCol();
    }
}
bool resuelveCaso(){
    matriz m;
    cin >> m;
    if(m.getFilas() == 0 || m.getCols() == 0) return false;
    escogeOpcion(m);
    cout << m;
    return true;
}

int main(){
    while(resuelveCaso());
    return 0; 
}
