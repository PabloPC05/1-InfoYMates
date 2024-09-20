#include "tPelicula.h"
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n != 0){
        tListaPeliculas listaPelis;
        tPelicula peli;
        for(int i = 0; i < n; i++){
            cin >> peli;
            peli.calcularHoraFin(peli);
            insertarPelicula(peli, listaPelis);
        }
        std::sort(listaPelis.pelis.begin(), listaPelis.pelis.end());
        for(int i = 0; i < n; i++){
            cout << listaPelis.pelis[i] << '\n';
        }
        cout << "---\n";
        cin >> n;         
    }
    return 0;
}