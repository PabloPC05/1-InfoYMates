// Problema 4: Sudokus correctos
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
using namespace std;
const int DIM = 9;
const int subDIM = 3;
using tMatriz = int[DIM][DIM];
using tsubMatriz = int[subDIM][subDIM];

void leerMatriz(tMatriz& m){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cin >> m[i][j];
        }
    }
}

void inicializar(bool (&l)[DIM]){
    for(int i = 0; i < DIM; i++){
        l[i] = false;
    }
}

bool comrpobarfc(int (&m)[DIM]){
    bool returnValue = true, l[DIM];
    inicializar(l);
    for(int i = 0; i < DIM; i++){
        l[m[i]-1] = true;
    }
    for(int i = 0; i < DIM && returnValue; i++){
        if(!l[i]) returnValue = false;
    }
    return returnValue;
}

bool comprobarM3x3(tsubMatriz& m){
    bool returnValue = true;
    for(int i =0; i< subDIM && returnValue; i++){
        for(int j = 0; j < subDIM && returnValue; j++){
            for(int t = 0; t < subDIM && returnValue; t++){
                for(int s = 0; s < subDIM; s++){
                    if(m[i][j] == m[t][s] && i != t && j != s) returnValue = false;
                } 
            }
        }
    }
    return returnValue;
}

bool resuelveCaso(tMatriz& m){ 
    bool returnValue = true;
    tsubMatriz subM;
    int fc[DIM];
    for(int i = 0; i < DIM && returnValue; i++){
        for(int j = 0; j < DIM && returnValue; j++){
            fc[j] = m[i][j];
        }
        returnValue = comrpobarfc(fc);
        for(int j = 0; j < DIM && returnValue; j++){
            fc[j] = m[j][i];
        }
        if (returnValue) returnValue = comrpobarfc(fc);
    }
    for(int j = 0; j < DIM && returnValue; j+= 3){
        for(int k = 0; k < DIM && returnValue; k+= 3){ 
            for(int t = 0; t < subDIM && returnValue; t++){
                for(int s = 0; s < subDIM; s++){
                    subM[t][s] = m[j+t][k+s];
                }
            }
            returnValue = comprobarM3x3(subM);
        }
    }
    return returnValue;
}

int main(){
    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++){
        tMatriz m;  
        leerMatriz(m);
        if (resuelveCaso(m)) cout << "SI\n";
        else cout << "NO\n";
    } 
    return 0;
}