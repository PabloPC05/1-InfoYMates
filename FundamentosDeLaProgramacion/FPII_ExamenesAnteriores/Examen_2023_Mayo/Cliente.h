#pragma once
#include <iostream>
#include <string>

class Cliente {
public:
   Cliente(std::string nif, double p, int nP) : nifn(nif), precio(p), numPartes(nP) {}
   int num_partes() const{return numPartes;}
   std::string const& nif() const {return nifn;}
   void nuevo_parte() {numPartes++;}
   double precio_seguro() const {return precio;}
   void actualiza_precio(double p) {precio = p;}
   void mostrar() const;
private:
   std::string nifn;
   double precio;
   int numPartes;
};

