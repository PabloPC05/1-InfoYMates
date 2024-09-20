#include <iostream>
#include <vector>
#include <iomanip>
#ifndef THORA_H
#define THORA_H

class tHora{
    public: 
    
    tHora(int hh = 0, int mm = 0, int ss = 0): hh(hh), mm(mm), ss(ss){}

    //Metodos de acceso
    int getHora() const{return hh;}
    int getMinuto() const{return mm;}
    int getSegundo() const{return ss;}

    //Metodos de modificacion
    void setHora(int hora){hh = hora;}
    void setMinuto(int minuto){mm = minuto;}
    void setSegundo(int segundo){ss = segundo;}

    //Metodos artimetico-logicos
    tHora operator+(tHora const& hora1) const;
    bool operator<(tHora const& hora1) const;
    bool operator==(tHora const& hora1) const;

    //Metodos de lectura y escritura
    void read(std::istream & entrada = std::cin);
    void write(std::ostream & salida = std::cout) const;

    private:
    int hh, mm, ss;
};

    std::istream &operator>>(std::istream & entrada, tHora &hora);
    std::ostream &operator<<(std::ostream & salida, tHora const& hora);


#endif