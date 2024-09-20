#include "tPelicula.h"
using namespace std;

bool tPelicula::operator<(tPelicula const& peli1)const {
    if(peli1.getHoraFin() < horaFin) return true;
    else if(peli1.getHoraFin() == horaFin){
        if(peli1.getName().compare(nombre) > 0) return true;
        else return false;
    }
    else return false;
}

bool operator==(tPelicula const& peli1, tPelicula const& peli2){
    return peli1.getName() == peli2.getName();
}

void tPelicula::read(std::istream & entrada){
    entrada >> horaInicio >> duracion;
    cin.ignore(256,' ');
    getline(entrada, nombre);
}

istream &operator>>(istream &entrada, tPelicula &peli){
    peli.read(entrada);
    return entrada;
}

void tPelicula::write(std::ostream & salida) const{
    salida << horaFin << " " << nombre;
}

ostream &operator<<(ostream &salida, tPelicula const& peli){
    peli.write(salida);
    return salida;
}

void insertarPelicula(const tPelicula &peli, tListaPeliculas &lista){
    lista.pelis.push_back(peli);
    lista.numPelis++;
}

void tPelicula::calcularHoraFin(tPelicula&){
    setHoraFin(getHoraInicio() + getDuracion());
}