#include "multiconjuntos.h"
using namespace std;

int multiconjunto::pertenece(int elem){
    int i = 0; 
    while(i < num_elems && elems.at(i).valor != elem) i++;
    if(i == num_elems) i = -1;
    return i;
}

void multiconjunto::insertar(int valor){
    int found = pertenece(valor);
    if(found == -1) {
        multiconjunto::elem newElem;
        newElem.setValor(valor); 
        newElem.setMultiplicidad(1);
        elems.push_back(newElem);
        setNumElems(getNumElems() + 1);
        setValorEnSecuencia(valor);
    }
    else{
        elems.at(found).setMultiplicidad((elems.at(found).getMultiplicidad() +1));
        setValorEnSecuencia(valor);
    }
}

void multiconjunto::eliminar(int elem){
    int found = pertenece(elem);
    if(elems.at(found).multiplicidad > 1){ //Si el elemento esta presente mas de una vez, elimina solo una de las tantas
        elems.at(found).setMultiplicidad((elems.at(found).getMultiplicidad()-1));
    }
    else{ //Si el elemento esta presente solo una vez, lo elimina por completo
        elems.erase(elems.begin()+found);
        setNumElems(getNumElems()-1);
    }
}

void multiconjunto::comparar(const multiconjunto& mIntento, tResultado& r){
    comparar1a1(mIntento, r);
    compararTodosConTodos(mIntento, r); 
}

void inicializarResultado(tResultado& r, int n){
    for(int i = 0; i < n; i++){
        r.push_back('.');
    }
}

ostream& operator<<(ostream& os, const tResultado& r){
    int size = r.size();
    for(int i = 0; i < size; i++){
        os << r.at(i);
    }
    return os;
}

void multiconjunto::comparar1a1(const multiconjunto& mIntento, tResultado& r){
    for(int i = 0; i < getSecuenciaSize(); i++){
        if(getValorEnSecuencia(i) == mIntento.getValorEnSecuencia(i)){
            r.at(i) = '#';
            eliminar(getValorEnSecuencia(i));
        }
    }
}

void multiconjunto::compararTodosConTodos(const multiconjunto& mIntento, tResultado& r){
    for(int i = 0; i < getNumElems(); i++){
        bool encontrado = false;
        for(int j = 0; j < mIntento.getSecuenciaSize() && !encontrado; j++){
                if(getElem(i) == mIntento.getValorEnSecuencia(j) && r.at(j) == '.'){
                r.at(j) = 'O';
                eliminar(mIntento.getValorEnSecuencia(j));
                encontrado = true;
            }
        }
        if(encontrado) i--;
    }
}
