#include <functional>
#include <vector>
#include <iostream>

using namespace std;

struct usuario {
    int ident;
    int tiempo;
    int tiempo_const;
};

using usuarios = vector<usuario>;

struct tListaUsuarios {
    usuarios u;
    int k;
};

bool operator<(usuario u1, usuario u2) {
    if (u1.tiempo > u2.tiempo) return true;
    else if (u1.tiempo < u2.tiempo) return false;
    else return(u1.ident > u2.ident);
}

template <typename T, typename Comp = std::less<T>>
void ordenar_seleccion(std::vector<T>&/*ent/sal*/ lista, Comp ord = Comp()) {
    size_t N = lista.size();
    // ordenado lista[0..i) y todos los elementos de la parte ordenada
    // son "menores" (o iguales) que los de la parte no ordenada
    for (size_t i = 0; i + 1 < N; ++i) { // hasta el pen?ltimo
        // colocar el "menor" de la parte no ordenada (lista[i..N)) en lista[i]
        size_t menor = i;
        for (size_t j = i + 1; j < N; ++j)
            if (ord(lista[j], lista[menor])) menor = j;
        swap(lista[i], lista[menor]);
    }
    // parte ordenada lista[0..N)
}

template <typename T, class Comp = std::less<T>>
void insertar_ordenado(std::vector<T>&/*ent/sal*/ lista, size_t i, Comp ord = Comp()) {
    // parte ordenada lista[0..i)
    T elemento = lista[i];  // elemento a insertar
    size_t j = i; // desplazar los mayores de la parte ordenada
    while (j > 0 && ord(elemento, lista[j - 1])) {
        lista[j] = lista[j - 1];
        --j;
    }
    lista[j] = elemento; // colocar en el hueco
}

bool leer_casos(tListaUsuarios& t){
    t.u.clear();
    usuario aux;
    int num;
    cin >> num; if (num==0) return false;
    for (int i = 0; i < num; i++) {
        cin >> aux.ident;
        cin >> aux.tiempo_const;
        aux.tiempo = aux.tiempo_const;
        t.u.push_back(aux);
    }
    cin >> t.k;
    return true;
}

int main() {
    tListaUsuarios t;
    while (leer_casos(t)) {
        ordenar_seleccion(t.u);
        for (int i = 0; i < t.k; i++) {
            cout << t.u[t.u.size() - 1].ident<<'\n';
            for (int a = 0; a < t.u.size()-1; a++) {
                t.u[a].tiempo = t.u[a].tiempo - t.u[t.u.size() - 1].tiempo;
            }
            t.u[t.u.size() - 1].tiempo = t.u[t.u.size() - 1].tiempo_const;
            insertar_ordenado(t.u, t.u.size() - 1);
        }
        cout << "---\n";
    }
}