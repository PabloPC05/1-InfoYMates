//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include <iostream>
#include <iomanip>
#include <vector>
using par = std::pair<int, int>;
enum Celda { NULA, VACIA, FICHA };
const int MAXDIM = 10;
class Tablero {
public:
    Tablero(par d) : filas(d.first), columnas(d.second) {   //Constructor
        for (int i = 0; i < MAXDIM; i++) {
            for (int j = 0; j < MAXDIM; j++) {
                celdas[i][j] = NULA;
            }
        }
    }

    //Getter y setter del numero de filas
    int getFilas() const { return filas; }
    void setFilas(int f) { filas = f; }

    //Getter y setter del numero de columnas
    int getColumnas() const { return columnas; }
    void setCols(int c) { columnas = c; }

    //Getter y setter de las celdas
    Celda leer(int f, int c) const { return celdas[f][c]; }
    Celda leer(par p) const { return celdas[p.first][p.second]; }
    void escribir(int f, int c, Celda valor) { celdas[f][c] = valor; }
    void escribir(par p, Celda valor) { celdas[p.first][p.second] = valor; }

    //Metodos de comparacion
    bool enLimites(par ficha) const { return (ficha.first >= 0 && ficha.first < getFilas() && ficha.second >= 0 && ficha.second < getColumnas()); }
private:
    int filas, columnas;
    Celda celdas[MAXDIM][MAXDIM];
};