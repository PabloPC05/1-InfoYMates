// Problema 3: La fábrica de juguetes de Papá Noel
// IMPORTANTE 
// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
using namespace std;
const int MAX = 100;
using tMatriz = int[MAX][MAX];
void leerMatriz(tMatriz& m, int dimF, int dimC){
    for(int i = 0; i < dimF; i++){
        for(int j = 0; j < dimC; j++){
            cin >> m[i][j];
        }
    }
}

void multiplicarMatrices(tMatriz& mRes, tMatriz& m1, tMatriz& m2, int dimF1, int dimC1, int dimF2, int dimC2){
    for(int i = 0; i < dimF1; i++){
        for(int j = 0; j < dimC2; j++){
            mRes[i][j] = 0;
            for(int k = 0; k < dimC1; k++){
                mRes[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void imprimirMatriz(tMatriz& m, int dimF, int dimC){
    for(int i = 0; i < dimF; i++){
        for(int j = 0; j < dimC; j++){
            cout << m[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "---\n";
}

bool resuelveCaso(){
    int dimF1, dimC1, dimF2, dimC2;
    cin >> dimF1 >> dimC1;
    while(!cin) return false;
    tMatriz m1, m2, mRes;
    leerMatriz(m1, dimF1, dimC1);
    cin >> dimF2 >> dimC2;
    leerMatriz(m2, dimF2, dimC2);
    multiplicarMatrices(mRes, m1, m2, dimF1, dimC1, dimF2, dimC2),
    imprimirMatriz(mRes, dimF1, dimC2);
    return true;
}
int main(){
    while(resuelveCaso()); 
    return 0;
}