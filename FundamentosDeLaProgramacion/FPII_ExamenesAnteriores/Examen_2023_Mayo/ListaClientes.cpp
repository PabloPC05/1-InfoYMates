#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
#include "ListaClientes.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

void ListaClientes::cargar(){
    cin >> cont;
    for(int i = 0; i < cont; i++){
        string nif;
        int nP;
        double p;
        cin >> nif >> p >> nP;
        clientes[i] = new Cliente(nif, p, nP);
    }
}

int ListaClientes::buscar_indice_cliente(string const& nifn){
    int i = -1, fin = cont;
    while(i+1 < fin){
        int mitad = (i + fin)/2;
        if(clientes[mitad]->nif() < nifn) i = mitad;
        else fin = mitad;
    }
    return fin;
}

Cliente* ListaClientes::buscar_cliente(string const& nifn){
    int i = buscar_indice_cliente(nifn);
    if(i < cont && clientes[i]->nif() == nifn) return clientes[i];
    return nullptr;
}

void ListaClientes::eliminar_cliente(string const& nifn){
    int pos = buscar_indice_cliente(nifn);
    if(pos < cont && clientes[pos]->nif() == nifn){
        delete clientes[pos];
        for(int i = pos; i < cont; i++){
            clientes[i] = clientes[i+1];
        }
        cont--;
    }

}

void ListaClientes::mostrar(){
    for(int i = 0; i < cont; i++){
        clientes[i]->mostrar();
    }
}

Cliente* ListaClientes::cliente(int pos) const {
    assert(0 <= pos && pos < cont);
    return clientes[pos];
}


