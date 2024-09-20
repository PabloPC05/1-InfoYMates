// Problema 2: Maxima cota de un mapa topografico
// IMPORTANTE
// Pablo Pardo Cotos
// FP2-DG25
#include <iostream>
const int DIM = 100;
using namespace std;
bool resuelveCaso(){
    int m[DIM][DIM], filas, columnas;
    cin >> filas >> columnas; 
    if(!cin) return false;
    else{
        for(int i = 0; i < filas; i++){ //lee la matriz segun las filas y columnas
            for(int j = 0; j < columnas; j++){
                cin >> m[i][j];
            }
        }
        int i = 0, j = 0, max_i = 0, max_j = 0, max = m[0][0];
        while(i < filas){   //busca el mayor valor de la matriz
            while(j < columnas){
                if(max < m[i][j]) { //se guarda su valor y su posicion
                    max = m[i][j];
                    max_i = i;
                    max_j = j;
                }
                j++;
            }
            i++;
            j = 0; //se reinicia la posicion en las columnas
        }
        cout << max <<' '<< max_i << ' ' << max_j <<'\n';
        return true;
    }
}
int main(){
    while(resuelveCaso());
    return 0;
}