#include "tHora.h"
#include "horario.h"
using namespace std;

int main() {
    int nTrenes, nConsultas; 
    cin >> nTrenes >> nConsultas;
    tHorarioTrenes trenes;
    inicia(trenes);
    while(nTrenes != 0){
        for(int i = 0; i < nTrenes; i++){
            tHora h;
            cin >> h;
            inserta(trenes, h);
        }
        for(int i = 0; i < nConsultas; i++){
            tHora h, sig;
            cin >> h;
            if(busca(trenes, h, sig)) cout << sig << '\n';
            else cout << "NO\n";
        }
        cout << "---\n";
        cin >> nTrenes >> nConsultas;
        inicia(trenes);
    }
    return 0;   
}