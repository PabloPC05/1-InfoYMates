// Problema 6: El juego de las 4 en raya
// IMPORTANTE
// Pablo Pardo Cotos
// FP2-DG25
#include <iostream>
using namespace std;
const int numFilas = 6; 
const int numCol = 7; 
using tMatriz = int[numFilas][numCol];
using tCont = int[numCol];

void inicializarTablero(tMatriz& tablero){
    for(int i = 0; i < numFilas; i++){
        for(int j = 0; j < numCol; j++){
            tablero[i][j] = 0;
        }
    }
}

int fichaInicial(int filaFicha, int colFicha, int& dir){
    int returnValue = 0;
    while(filaFicha > 0 && colFicha < 6){
        filaFicha--; colFicha = colFicha + dir;
    }
    returnValue = filaFicha * 10 + colFicha;
    return returnValue;
}

bool enRango(const int& i, const int& j) {
    return j >= 0 && j < numCol && i >= 0 && i < numFilas;
}

int diagonal(tMatriz& tablero, int filaFicha, int colFicha, int dir){
    int returnValue = 0, cont = 0;
    int fichaIni = fichaInicial(filaFicha, colFicha, dir), posIniCol = fichaIni % 10, posIniFil = fichaIni / 10;
    dir = -dir;
    for(int i = posIniFil, j = posIniCol; enRango(i, j) && returnValue == 0; i++, j = j + dir){
        if(tablero[filaFicha][colFicha] == tablero[i][j]) cont++;
        else cont = 0;
        if(cont == 4) returnValue = tablero[filaFicha][colFicha];
    }
    return returnValue;
}

int cuatroEnRaya(tMatriz& tablero, int n, tCont& contF){
    int returnValue = 0, cont = 0, filaFicha = numFilas - contF[n-1], colFicha = n-1;
    //comprobar la fila de la ficha recien metida 
    for(int i = 0; i < numCol && returnValue == 0; i++){
        if(tablero[filaFicha][colFicha] == tablero[filaFicha][i]) cont++;
        else cont = 0;
        if(cont == 4) returnValue = tablero[filaFicha][colFicha];
    }
    cont = 0; 
    //comprobar la columna de la ficha recien metida
    for(int i = 0; i < numFilas && returnValue == 0; i++){
        if(tablero[filaFicha][colFicha] == tablero[i][colFicha]) cont++;
        else cont = 0;
        if(cont == 4) returnValue = tablero[filaFicha][colFicha];
    }
    int dir = -1; cont = 0;
    //comprobar desde arriba a la izquierda hasta abajo a la derecha
    if(returnValue == 0) returnValue = diagonal(tablero, filaFicha, colFicha, dir);
    dir = 1; cont = 0;
    //comprobar desde abajo a la izquierda hasta arriba a la derecha
    if(returnValue == 0) returnValue = diagonal(tablero, filaFicha, colFicha, dir);
    return returnValue;
}

void resuelveCaso(){
    tMatriz tablero;
    inicializarTablero(tablero);
    int n, cont = 0, ganador = 0; 
    int contF[numCol] = {0,0,0,0,0,0,0};
    while(cont != numFilas*numCol && ganador == 0){
        cin >> n;
        if(n >= 1 && n <= numCol){
            if(cont % 2 == 0) tablero[numFilas-1 - contF[n-1]][n-1] = 1;
            else tablero[numFilas-1 - contF[n-1]][n-1] = 2;
            cont++;
            contF[n-1]++;
            ganador = cuatroEnRaya(tablero, n, contF);
        }
    }
    if(ganador == 1) cout << "Ganan rojas\n";
    else if(ganador == 2) cout << "Ganan amarillas\n";
    else cout << "Empate\n";
}

int main(){
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++) resuelveCaso();
    return 0;
}