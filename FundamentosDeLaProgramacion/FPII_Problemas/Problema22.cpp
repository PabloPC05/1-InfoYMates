#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
using par = pair<int, int>;
const par dir[8] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };
par operator+(par a, par b) {
    return { a.first + b.first, a.second + b.second };
}

using tTablero = vector<vector<char>>;

struct buscaMinas {
    tTablero tablero;
    vector <par> celdasDescubiertas;
    void leerCaso();
    bool enLimites(const par& f);
    bool esMina(const par& f);
    int hayMinas(const par f);
};

void buscaMinas::leerCaso() {
    int f, c;
    cin >> f >> c;
    if (!cin) return;  // no hay más casos de prueba
    tablero.resize(f, vector<char>(c));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            tablero[i][j] = temp;
        }
    }
    int numCeldasDescubiertas;
    cin >> numCeldasDescubiertas;
    for (int i = 0; i < numCeldasDescubiertas; i++) {
        int f, c;
        cin >> f >> c;
        f--;
        c--;
        celdasDescubiertas.push_back(make_pair(f, c));
    }
}

bool buscaMinas::enLimites(const par& f) {
    int i = tablero.size();
    int j = tablero[0].size();
    return f.first >= 0 && f.first < i && f.second >= 0 && f.second < j;
}

bool buscaMinas::esMina(const par& f) {
    return tablero[f.first][f.second] == '*';
}

int buscaMinas::hayMinas(const par f) {
    int numMinas = 0;
    for (int i = 0; i < 8; i++) {
        if (enLimites(f + dir[i]) && esMina(f + dir[i])) {
            numMinas++;
        }
    }
    return numMinas;
}

void descubrir(buscaMinas& bM, tTablero& sol, par f) {
    int minas = bM.hayMinas(f);
    if (minas > 0) {
        char temp = minas + '0';
        sol[f.first][f.second] = temp;
    }
    else {
        sol[f.first][f.second] = '-';
        for (int i = 0; i < 8; i++) {
            par temp;
            temp.first = f.first + dir[i].first;
            temp.second = f.second + dir[i].second;
            if (bM.enLimites(f + dir[i]) && sol[temp.first][temp.second] == 'X') {
                descubrir(bM, sol, temp);
            }
        }

    }
}

void imprimirTablero(const tTablero& tablero) {
    for (size_t i = 0; i < tablero.size(); i++) {
        for (size_t j = 0; j < tablero[0].size(); j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool equivocacion(buscaMinas& bM) {
    int limit = bM.celdasDescubiertas.size();
    for (int i = 0; i < limit; i++) {
        if (bM.esMina(bM.celdasDescubiertas[i])) return true;
    }
    return false;
}

bool resuelveCaso() {
    buscaMinas bM;
    bM.leerCaso();
    if (!cin) return false; // no hay más casos de prueba
    tTablero sol(bM.tablero.size(), vector<char>(bM.tablero[0].size(), 'X'));
    if (!equivocacion(bM)) {
        for (size_t i = 0; i < bM.celdasDescubiertas.size(); i++) {
            descubrir(bM, sol, bM.celdasDescubiertas[i]);
        }
        imprimirTablero(sol);
    }
    else {
        cout << "GAME OVER\n";
    }
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}