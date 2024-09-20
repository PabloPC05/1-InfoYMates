#include <iostream>
#include <vector>
using namespace std;
struct tLista{
    vector <int> lista;
    void leerCaso();
    void mostrarLista();
};

void tLista::leerCaso(){
    for(int i = lista.size()-1; i >= 0; i--){
        int aux;
        cin >> aux; 
        lista.at(i) = aux;
    }
}

tLista listaOrdenada(tLista& lista1, tLista& lista2){
    tLista listaOrdenada;
    int size1 = lista1.lista.size()-1, size2 = lista2.lista.size()-1;
    while(0 < lista1.lista.size() && 0 < lista2.lista.size()){
        if(lista1.lista.at(size1) > lista2.lista.at(size2)){
            listaOrdenada.lista.push_back(lista2.lista.at(size2));
            lista2.lista.pop_back();
            size2 = lista2.lista.size()-1;
        }
        else{
            listaOrdenada.lista.push_back(lista1.lista.at(size1));
            lista1.lista.pop_back();
            size1 = lista1.lista.size()-1;
        }
    }   
    while(lista1.lista.size() > 0){
        listaOrdenada.lista.push_back(lista1.lista.at(size1));
        lista1.lista.pop_back();
        size1 = lista1.lista.size()-1;
    }

    while(lista2.lista.size() > 0){
        listaOrdenada.lista.push_back(lista2.lista.at(size2));
        lista2.lista.pop_back();
        size2 = lista2.lista.size()-1;
    }
    return listaOrdenada;
}

void tLista::mostrarLista(){
    int size = lista.size();
    for(int i = 0; i < size; i++){
        cout << lista.at(i) << " ";
    }
    cout << '\n';
}


void resuelveCaso(){
    int aux; 
    cin >> aux; 
    tLista lista1;
    lista1.lista.resize(aux);
    cin >> aux; 
    tLista lista2; 
    lista2.lista.resize(aux);
    lista1.leerCaso();
    lista2.leerCaso();
    listaOrdenada(lista1, lista2).mostrarLista();
}

int main(){
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++) resuelveCaso();
    return 0; 
}