#include "multiconjuntos.h"
using namespace std;
int main(){
    int n, e;
    cin >> n;
    while(n != 0){
        multiconjunto mSecreto;
        multiconjunto mIntento;
        tResultado r;
        inicializarResultado(r, n);
        for(int i = 0; i < n; i++){
            cin >> e;
            mSecreto.insertar(e);
        }
        for(int i = 0; i < n; i++){
            cin >> e;
            mIntento.insertar(e);
        }
        mSecreto.comparar(mIntento, r);
        cout << r << '\n';
        cin >> n;
    }
    return 0;
}
