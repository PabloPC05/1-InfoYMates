#include "inventario.h"
#include <functional>
using namespace std;

template <typename T, typename Comp = less<T>>
bool busqueda_binaria(vector<T> const& array, T const& buscado, size_t&/*sal*/ pos, Comp ord = Comp()) {
    int iz = -1, dr = array.size();
    bool encontrado = false;
    // 0 <= iz < dr <= N
    // array[0..iz] < buscado Y buscado <= array[dr..N)
    while (iz + 1 < dr) { // hay elementos sin categorizar
        int mitad = (iz + dr) / 2;
        if (ord(array[mitad], buscado)) iz = mitad;
        else dr = mitad;
    }
    pos = dr;
    return pos < array.size() && !ord(buscado, array[pos]);
}

template <typename T>
void desplazar_derecha(vector<T>&/*ent/sal*/ array, size_t pos) {
    array.push_back({}); // crear un nuevo hueco
    for (size_t i = array.size() - 1; i > pos; --i)
        array[i] = array[i - 1];
}

template <typename T, typename Comp = less<T>>
bool insertar(vector<T>&/*ent/sal*/ array, T const& dato, Comp ord = Comp()) {
    size_t pos = 0;
    if (!busqueda_binaria(array, dato, pos, ord)) {
        desplazar_derecha(array, pos);
        array[pos] = dato;
        return true;
    }
    else return false;
}

void inventario::nuevo_id(int i, int c)
{
    par p;
    p.id = i;
    p.cont = c;
    insertar(v,p);
}

void inventario::comprar_id(int i, int c)
{
    par p;
    p.id = i;
    p.cont = 0;
    size_t lugar;
    busqueda_binaria(v, p, lugar);
    v[lugar].cont = v[lugar].cont+c;

}

void inventario::vender(int i)
{
    par p;
    p.id = i;
    p.cont = 0;
    size_t lugar;
    busqueda_binaria(v, p, lugar);
    if (v[lugar].cont != 0) v[lugar].cont--;
 
}

void inventario::mostrar() const
{
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].id << ' ' << v[i].cont << '\n';
    }
    cout << "---\n";
}
