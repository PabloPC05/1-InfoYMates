// Problema 5: Puntos de silla
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
using namespace std;
const int DIM = 300;
using tMatriz = int[DIM][DIM];
const int CENTINELA = 0;

//Esta funcion se encarga de coprobar si un punto es de silla, con la definicion de que un punto de silla es el menor de su fila y el maximo de su columna
bool esMatrizSillaA(tMatriz& m, int dimF, int dimC){
    bool returnValue = false;
    for(int i = 0; i < dimF && !returnValue; i++){
        for(int j = 0; j < dimC && !returnValue; j++){
            int minF = m[i][j], maxC = m[i][j];
            for(int k = 0; k < dimC && !returnValue; k++){
                if(m[i][k] < minF) minF = m[i][k];
            }
            if(minF == m[i][j]) returnValue = true;
            for(int k = 0; k < dimF && returnValue; k++){
                if(m[k][j] > maxC) maxC = m[k][j];
            }
            if(returnValue && maxC == m[i][j]) returnValue = true;
            else returnValue = false;
        }
    }
    return returnValue;
}

//Por otro lado esta funcion se encarga de la otra definicion de punto de silla, que sea el mayor de su fila y el menor de su columna
bool esMatrizSillaB(tMatriz& m, int dimF, int dimC){
    bool returnValue = false;
    for(int i = 0; i < dimF && !returnValue; i++){
        for(int j = 0; j < dimC && !returnValue; j++){
            int minC = m[i][j], maxF = m[i][j];
            for(int k = 0; k < dimC && !returnValue; k++){
                if(m[i][k] > maxF) maxF = m[i][k];
            }
            if(maxF == m[i][j]) returnValue = true;
            for(int k = 0; k < dimF && returnValue; k++){
                if(m[k][j] < minC) minC = m[k][j];
            }
            if(returnValue && minC == m[i][j]) returnValue = true;
            else returnValue = false;
        }
    }
    return returnValue;
}

void leerMatriz(tMatriz& m, int dimF, int dimC){
    for(int i = 0; i < dimF; i++){
        for(int j = 0; j < dimC; j++){
            cin >> m[i][j];
        }
    }
}

void inicializar(tMatriz& m, int dimF, int dimC){
    for(int i = 0; i < dimF; i++){
        for(int j = 0; j < dimC; j++){
            m[i][j] = 0;
    }
}
}

bool resuelveCaso(){
    tMatriz m;
    int dimF, dimC;
    cin >> dimF >> dimC;
    if(dimF == CENTINELA && dimC == CENTINELA) return false;
    leerMatriz(m, dimF, dimC);
    if(esMatrizSillaA(m, dimF, dimC) || esMatrizSillaB(m, dimF, dimC)) cout << "SI\n";
    else cout << "NO\n";
    inicializar(m, dimF, dimC);
    return true;
}
int main(){
    while(resuelveCaso());
    return 0;
}