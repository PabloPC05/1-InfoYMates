// Problema 8: Codigos QR
// IMPORTANTE
// Pablo Pardo Cotos
// FP2-DG25
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 31;
bool lineaAlmohadillas(vector<vector<char>> &matriz, int t, int s){ //t = fila, s = columna
    bool returnValue = true;
    int taux = t + 12, saux = s + 12, j = s, k = t;
    while(j < saux){
        for(int i = t; i < t+7; i++){
            if(matriz[i][j] != '#') returnValue = false;
        }
        j = j + 6;
    }
    while(k < taux){
        for(int i = s; i < s+7; i++){
            if(matriz[k][i] != '#') returnValue = false;
        }
        k = k+6;
    }
    return returnValue;
}
bool lineaPuntos(vector<vector<char>> &matriz, int t, int s){ //t = fila, s = columna
    bool returnValue = true;
    t++; s++; 
    for(int i = t; i < t+5; i++){
        if(matriz[i][s] != '.') returnValue = false;
    }
    return returnValue;
}

bool lineaMixta(vector<vector<char>> &matriz, int t, int s){ //t = fila, s = columna
    bool returnValue = true;
    t++; t++; s++; 
    for(int j = t; j < t+3; j++){
        int i = s;
        if(matriz[j][i] != '.') returnValue = false; 
        i++;
        int saux = s+3;
        while(i <= saux){
            if(matriz[j][i] != '#') returnValue = false;
            i++;
        }
        if(matriz[j][i] != '.') returnValue = false;
    }
    return returnValue;
}

bool esQR(vector<vector<char>> &matriz){
    bool returnValue1 = lineaAlmohadillas(matriz, 1, 1) && lineaPuntos(matriz, 1, 1) && lineaMixta(matriz, 1, 1);
    bool returnValue2 = lineaAlmohadillas(matriz, 1, 23) && lineaPuntos(matriz, 1, 23) && lineaMixta(matriz, 1, 23);
    bool returnValue3 = lineaAlmohadillas(matriz, 23, 1) && lineaPuntos(matriz, 23, 1) && lineaMixta(matriz, 23, 1);
   return returnValue1 && returnValue2 && returnValue3;
}

void girarQR(vector<vector<char>> &matriz){
    vector<vector<char>> aux(31, vector<char>(MAX));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            aux[i][j] = matriz[i][j];
        }
    }
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matriz[MAX-1-j][i] = aux[i][j];
        }
    }
}

void leerMatriz(vector<vector<char>> &matriz){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> matriz[i][j];
        }
    }
}

void imprimeMatriz(vector<vector<char>> &matriz){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << matriz[i][j];
        }
        cout << '\n';
    }
}

void resuelveCaso(){
    vector<vector<char>> matriz(MAX, vector<char>(MAX));
    leerMatriz(matriz);
    while(!esQR(matriz)){
        girarQR(matriz);
    }
    imprimeMatriz(matriz);
}
int main(){
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++) resuelveCaso();
    return 0;
}