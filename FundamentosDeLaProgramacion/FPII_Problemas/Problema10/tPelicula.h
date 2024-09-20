#include "tHora.h"
#include <string>
#include <algorithm>

class tPelicula{
    public: 
    //Constructor de la clase
    tPelicula(std::string nombre = "", tHora horaInicio = tHora(), tHora duracion = tHora()): nombre(nombre), horaInicio(horaInicio), duracion(duracion){}

    //Metodos de comparacion
    bool operator<(tPelicula const& peli) const;
    bool operator==(tPelicula const& peli) const;

    //Metodos de acceso
    std::string getName() const{return nombre;}
    tHora getHoraInicio () const{return horaInicio;}
    tHora getDuracion () const{return duracion;}
    tHora getHoraFin () const{return horaFin;}
    void read(std::istream & entrada = std::cin);

    //Metodos de modificacion
    void setName(std::string name){nombre = name;}
    void setHoraInicio(tHora hora){horaInicio = hora;}
    void setDuracion(tHora dur){duracion = dur;}
    void setHoraFin(tHora hora){horaFin = hora;}
    void write(std::ostream& salida = std::cout) const;

    void calcularHoraFin(tPelicula& peli);

    private:
    //Atributos de la clase
    std::string nombre;
    tHora horaInicio;
    tHora duracion;
    tHora horaFin;
};

struct tListaPeliculas{
    std::vector<tPelicula> pelis;
    int numPelis;
    tListaPeliculas(int numPelis = 0) : numPelis(numPelis){};
};  

    void insertarPelicula (const tPelicula &peli, tListaPeliculas &lista);

    std::istream &operator>>(std::istream &entrada, tPelicula &peli);
    std::ostream &operator<<(std::ostream &salida, tPelicula const& peli);
