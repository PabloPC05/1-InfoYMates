#include <iomanip>
#include "tHora.h"
using namespace std;

bool operator<(tHora const& a, tHora const& b) {
    if (a.hh < b.hh) return true;
    else if (a.hh > b.hh) return false;
    else if (a.mm < b.mm) return true;
    else if (a.mm > b.mm) return false;
    else return a.ss < b.ss;
}

istream &operator>>(istream & entrada, tHora &/*sal*/ hora) {
    char aux;
    entrada >> hora.hh >> aux >> hora.mm >> aux >> hora.ss;
    return entrada;
}

ostream &operator<<(ostream & salida, tHora const& hora) {
    salida << setfill('0') << setw(2) << hora.hh << ':' << setfill('0') << setw(2) << hora.mm << ':' << setfill('0') << setw(2) << hora.ss;
    return salida;
}

