#pragma once
#include <fstream>
#include <string>

class ListaPartes {
public:
   ListaPartes();
   ~ListaPartes();
   void cargar();
   int num_partes() const;
   std::string const& parte(int i) const;
   
private:
   std::string** lista;
   int cont;
   int capacidad;
   void redimensionar();
};

