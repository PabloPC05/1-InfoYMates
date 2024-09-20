// Practica 1
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
using namespace std;
const int LONG_CARRETERA = 20;
const int MAX_PAS = 2;
const int TIEMPO_PARADO = 2;
const bool DEBUG = true;
const char CHAR_LINEA_HORIZONTAL = char(205);           // ˭
const char CHAR_ESQUINA_SUPERIOR_IZQUIERDA = char(201); // ╔═
const char CHAR_ESQUINA_SUPERIOR_DERECHA = char(187);   // ═╗
const char CHAR_ESQUINA_INFERIOR_IZQUIERDA = char(200); // ╚═
const char CHAR_ESQUINA_INFERIOR_DERECHA = char(188);   // ═╝
const char CHAR_LINEA_VERTICAL = char(186);             // ║
const char CHAR_COCHE = char(254);                      // ■
const char CHAR_CLAVO = char(193);                      // ┴
const char CHAR_SORPRESA = char(63);                    // ?
const char CHAR_NORMAL = char(32);                      // ' '
enum tTipoPosicion { NORMAL, CLAVO, SORPRESA };
using tCarretera = tTipoPosicion[LONG_CARRETERA];

// Transforma el string s en su correspondiente elemento del tipo enumerado tTipoPosicion
tTipoPosicion stringToEnum(string s) {
    if (s == "CLAVO") return tTipoPosicion(CLAVO);
    else if (s == "SORPRESA") return tTipoPosicion(SORPRESA);
    return tTipoPosicion(0);
}

// Se encarga de poner todos los valores del array a normal, para luego cambiarlos segun donde esten los clavos y sorpresas
void inicializaCarretera(tCarretera carretera) {
    for (int i = 0; i < LONG_CARRETERA; i++) {
        carretera[i] = NORMAL;
    }
}

/*
* Pide el nombre del archivo al
* usuario. Lo abre y carga los datos en carretera. Devuelve true sí y sólo sí la apertura
* del archivo ha sido correcta
*/
bool cargaCarretera(tCarretera carretera) {
    string nombreArchivo, tipoObjeto;
    ifstream archivo;
    int numObjetos, posObjetos;
    cin >> nombreArchivo;
    inicializaCarretera(carretera);
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) return false;
    archivo >> tipoObjeto;
    while (tipoObjeto != "XX") {
        archivo >> numObjetos;
        for (int i = 0; numObjetos > i; i++) {
            archivo >> posObjetos;
            carretera[posObjetos] = stringToEnum(tipoObjeto);
        }
        archivo >> tipoObjeto;
    }
    archivo.close();
    return true;
}

/*
* Dibuja el contenido del carril, es decir los clavos (┴ ), las sorpresas ( ? ) y el coche ( ■ ), que está en la
* posición posCoche. El carril realmente ocupa dos líneas. En la primera se colocan las
* posiciones clavo y sorpresa, y en la segunda línea se coloca el coche. De esta forma la
* visualización es más representativa. Observa además que cada línea empieza y acaba con ǁ.
* El siguiente dibujo muestra el carril del archivo “carriles.txt”, donde el coche está en
* la posición inicial.
*/
void dibujaCarril(tCarretera carretera, int posCoche) {
    string carrtera2;
    cout << CHAR_LINEA_VERTICAL;
    for (int i = 0; i < LONG_CARRETERA; i++) {
        switch (carretera[i]) {
        case NORMAL: cout << CHAR_NORMAL; break;
        case CLAVO: cout << CHAR_CLAVO; break;
        case SORPRESA: cout << CHAR_SORPRESA; break;
        }
    }
    cout << CHAR_LINEA_VERTICAL << "\n" << CHAR_LINEA_VERTICAL;
    for (int i = 0; i < posCoche; i++) cout << ' ';
    cout << CHAR_COCHE;
    for (int i = 0; i < LONG_CARRETERA - posCoche -1; i++) cout << ' ';
    cout << CHAR_LINEA_VERTICAL << "\n";
}

// Dibuja la línea superior de la carretera, teniendo en cuenta la longitud de la misma
void dibujaLineaHorizontalSuperior() {
    cout << CHAR_ESQUINA_SUPERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_SUPERIOR_DERECHA;
}

// Dibuja la línea inferior de la carretera, teniendo en cuenta la longitud de la misma
void dibujaLineaHorizontalInferior() {
    cout << CHAR_ESQUINA_INFERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_INFERIOR_DERECHA;
}

// Utiliza las funciones anteriores para dibujar la carretera completa
void dibujaCarretera(tCarretera carretera, int posCoche) {
    dibujaLineaHorizontalSuperior();
    cout << "\n";
    dibujaCarril(carretera, posCoche);
    dibujaLineaHorizontalInferior();
    cout << "\n";
}

/*
* Coloca el coche en el inicio (posición 0) e inicializa su tiempo parado a 0. Posteriormente se carga
* la configuración de la carretera de un archivo de texto, cuyo nombre se pide por consola. Se llama
* a la función dibujaCarretera para probar las funciones de carga de datos y mostrar la carretera
*/
int main() {
    tCarretera carretera;
    int posCoche = 7;
    if (cargaCarretera(carretera)) dibujaCarretera(carretera, posCoche);
    else cout << "Error al abrir el archivo\n";
    return 0;
}