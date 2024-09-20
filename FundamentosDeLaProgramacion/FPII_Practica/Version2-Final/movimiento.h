//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include <string>
#include <utility>
#include <iostream>
#include <vector>
using par = std::pair<int, int>;
using pares = std::vector<par>;

// numero de direcciones a considerar
const int NUMDIR = 5;

// Redefinciones de operadores primitivos adaptados al tipo par
par operator+(par p, par d);
par operator*(const int& n, const par& p);
std::ostream& operator<<(std::ostream& os, const par& p);
par operator+(const int& n, const par& p);
std::istream& operator>>(std::istream& is, par& p);

enum Direccion { ARRIBA, ABAJO, IZQUIERDA, DERECHA, INDETERMINADA };
//Convierte una direccion en un par
std::pair<int, int> dirToPar(Direccion d);
//Convierte un entero en una direccion
Direccion direccion(int i);
// Convierte una direcci�n en un string
std::string dirToString(Direccion d);
std::string dirToStringSol(Direccion d);

class Movimiento {
public:
    Movimiento() : ficha({ 0, 0 }), activa(INDETERMINADA) {}   //Constructor

    //Getter y setter de la direccion activa
    Direccion getDirActiva() const { return activa; }
    void setDirActiva(Direccion d) { activa = d; }

    //Getter del numero de direcciones
    size_t getNumDirs() const { return direcciones.size(); }

    //Getter y setter de las posibles direcciones direcciones
    void setDireccion(Direccion d) { direcciones.push_back(d); }
    Direccion getDireccion(int i) const { return direcciones.at(i); }

    //Getter y setter de la ficha del movimiento
    par getFicha() const { return ficha; }
    void setFicha(par f) { ficha = f; }

private:
    //Atributos
    std::pair<int, int> ficha; // fila y columna de la ficha
    Direccion activa; // de todas las direcciones posibles, contiene la direccion activa, i.e., la direccion que se va a ejecutar
    std::vector<Direccion> direcciones; // direcciones a las que se puede mover
};
