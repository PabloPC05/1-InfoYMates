#pragma once
#include "Cliente.h"
#include <string>

class ListaClientes {
public:
   ListaClientes(int c = 0) : cont(c), clientes() {}
   ~ListaClientes() {
    for(int i = 0; i < MAX_CLIENTES; i++){
        delete clientes[i];
    }
}
   void cargar();
   Cliente* buscar_cliente(std::string const& nif);
   void eliminar_cliente(std::string const& nif);
   void mostrar();

   //Getter y Setter de los atributos
   Cliente* cliente(int pos) const;
   int num_clientes() const{return cont;}

private:
   static const int MAX_CLIENTES = 30;
   int buscar_indice_cliente(std::string const& nif);
   //Atributos
   Cliente* clientes[MAX_CLIENTES];
   int cont;
};

