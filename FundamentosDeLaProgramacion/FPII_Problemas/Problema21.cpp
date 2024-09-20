#include <iostream>
#include <vector>
using namespace std;
struct arbol{
    int numHijos;
    vector<arbol> hijos;
};

void leerArbol(arbol &a){
    cin >> a.numHijos;
    for(int i = 0; i < a.numHijos; i++){
        arbol hijo;
        leerArbol(hijo);
        a.hijos.push_back(hijo);
    }
}

int alturaArbol(arbol& a){
    int max = 0;
    if(a.hijos.size() == 0){
        max = 1;
    }else{
        for(int i = 0; i < a.hijos.size(); i++){
            int altura = alturaArbol(a.hijos[i]);
            if(altura > max){
                max = altura;
            }
        }
        max++;
    }
    return max;
}


void resuelveCaso(){
    arbol a;
    leerArbol(a);
    cout << alturaArbol(a) << endl;
}

int main(){
    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++){
        resuelveCaso();
    }
    return 0;
}