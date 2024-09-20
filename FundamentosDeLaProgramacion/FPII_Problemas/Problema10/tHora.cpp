#include "tHora.h"
using namespace std;

void tHora::read(std::istream & entrada){
    char aux;
    entrada >> hh >> aux >> mm >> aux >> ss;
}
void tHora::write(std::ostream & salida) const{
    salida << setfill('0') << setw(2) << hh << ':' << setfill('0') << setw(2) << mm << ':' << setfill('0') << setw(2) << ss;
}
istream &operator>>(istream &entrada, tHora &hora){
    hora.read(entrada);
    return entrada;
}

ostream &operator<<(ostream &salida, tHora const& hora){
    hora.write(salida);
    return salida;
}

bool tHora::operator==(tHora const& hora1) const{
    return hora1.getHora() == hh && hora1.getMinuto() == mm && hora1.getSegundo() == ss;
}

tHora tHora::operator+(tHora const& hora1) const{
    tHora res;
    res.setSegundo((hora1.getSegundo() + ss) % 60);
    res.setMinuto((hora1.getMinuto() + mm + (hora1.getSegundo() + ss) / 60) % 60);
    res.setHora((hora1.getHora() + hh + (hora1.getMinuto() + mm + (hora1.getSegundo() + ss) / 60) / 60) % 24);
    return res;
}

bool tHora::operator<(tHora const& hora1) const{
    if(hora1.getHora() < hh) return true;
    else if(hora1.getHora() > hh) return false;
    else if(hora1.getMinuto() < mm) return true;
    else if(hora1.getMinuto() > mm) return false;
    else if(hora1.getSegundo() < ss) return true;
    else return false;
}

