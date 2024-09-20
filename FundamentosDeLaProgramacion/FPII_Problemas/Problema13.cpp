#include <iostream>
#include <vector>
using namespace std;

struct tListaBaterias{
    vector <int> bateria;
    int bateriaMin;
    int numBaterias;
    void leerCaso();
};

template <typename T>
void ordenar_insercion(vector<T> &array) {
    size_t N = array.size();
    for (size_t i = 1; i < N; ++i) {
        T elemento = array[i];
        size_t j = i;
        while (j > 0 && elemento < array[j - 1]) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = elemento;
    }
}

void tListaBaterias::leerCaso(){
    cin >> numBaterias >> bateriaMin;
    for(int i = 0; i < numBaterias; i++){
        int b; 
        cin >> b; 
        bateria.push_back(b);
    }
}

int numBateriasDisponibles(tListaBaterias& baterias){
    int numBaterias = 0;
    for(int i = 0; i < baterias.bateria.size() && baterias.bateria.size() != 1; i++){
        int bateriaMin = baterias.bateria.at(i);
        int bateriaMax = baterias.bateria.at(baterias.bateria.size() - 1);
        if(bateriaMax + bateriaMin >= baterias.bateriaMin){
            numBaterias++;
            baterias.bateria.erase(baterias.bateria.begin() + i);
            baterias.bateria.erase(baterias.bateria.end() - 1);
        }
        else{
            baterias.bateria.erase(baterias.bateria.begin() + i);
        }
        i--;
    }
    return numBaterias;
}

void resuelveCaso(){
    tListaBaterias baterias;
    baterias.leerCaso();
    ordenar_insercion(baterias.bateria);
    cout << numBateriasDisponibles(baterias) << '\n';
}


int main(){
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++) resuelveCaso();
}