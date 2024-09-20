#include "movimiento.h"
using namespace std;

string dirToString(Direccion d) {
    switch (d) {
    case ARRIBA: return "ARRIBA";
    case ABAJO: return "ABAJO";
    case IZQUIERDA: return "IZQUIERDA";
    case DERECHA: return "DERECHA";
    default: return "INDETERMINADA";
    }
}

string dirToStringSol(Direccion d) {
    switch (d) {
    case ARRIBA: return "ABAJO";
    case ABAJO: return "ARRIBA";
    case IZQUIERDA: return "DERECHA";
    case DERECHA: return "IZQUIERDA";
    default: return "INDETERMINADA";
    }
}

par dirToPar(Direccion d) {
    switch (d) {
    case ARRIBA: return { -1,0 };
    case ABAJO: return { 1,0 };
    case IZQUIERDA: return { 0,-1 };
    case DERECHA: return { 0,1 };
    default: return { 0, 0 };
    }
}

Direccion direccion(int i) { return static_cast<Direccion>(i); }

par operator+(par p, par d) {
    return { p.first + d.first, p.second + d.second };
}
par operator*(int n, par p) {
    return { n * p.first, n * p.second };
}

par operator+(int n, par p) {
    return { n + p.first, n + p.second };
}

std::ostream& operator<<(std::ostream& os, const par& p) {
    os << p.first << ' ' << p.second;
    return os;
}

//Esta funcion dada una entrada de datos, y una ficha redefine la entrada para hacer el codigo mas "bonito" 
std::istream& operator>>(std::istream& en, par& ficha) {
    en >> ficha.first >> ficha.second;
    ficha.first--;
    ficha.second--;
    return en;
}