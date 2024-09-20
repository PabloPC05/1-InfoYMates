// Problema 1: Matriz identidad
// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
using namespace std;
const int DIM = 50;
bool resuelveCaso(){
    int m[DIM][DIM];
    int dim; 
    cin >> dim;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cin >> m[i][j];
        }
    }
    bool returnValue = true;
    int i = 0, j = 0; 
    while(i < dim && returnValue){
        while(j < dim && returnValue){
            if((i == j && m[i][i] != 1)||(i != j && m[i][j] != 0)) returnValue = false;
            j++;
        }
        j = 0; 
        i++; 
    }
    return returnValue;
}

int main(){
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++){
        if(!resuelveCaso()) cout << "NO\n";
        else cout << "SI\n";
    }
    return 0;
}