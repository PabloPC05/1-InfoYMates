// Practica 1
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int LONG_CARRETERA = 10;
const int MAX_PASOS = 2;
const int TIEMPO_PARADO = 2;
const bool DEBUG = 0;
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
struct tCoche {
    int pos;
    int tiempoParado;
};

tTipoPosicion stringToEnum(string s) {
    if (s == "CLAVO") return tTipoPosicion(CLAVO);
    else if (s == "SORPRESA") return tTipoPosicion(SORPRESA);
    return tTipoPosicion(NORMAL);
}
/* 
* Se encarga de limpiar el buffer en determinados casos 
*/
void limpiaBuffer() {
    cin.get();
}

/*
* Inicializa los valores del strcut coche a 0
*/
void iniciaCoche(tCoche& coche) {
    coche.pos = 0;
    coche.tiempoParado = 0;
}

/*
* Inicializa los valores del array carrtera a normal
*/
void iniciaCarril(tCarretera carretera) {
    for (int i = 0; i < LONG_CARRETERA; i++) {
        carretera[i] = NORMAL;
    }
}

/*
* Verifica que el archivo esta abierto o se encuentra en la ubicacion y carga los clavos y sorpresas en el array
*/
bool cargaCarretera(tCarretera carretera) {
    string nombreArchivo, tipoObjeto;
    ifstream archivo;
    int numObjetos, posObjetos;
    cout << "Dame el nombre del archivo: ";
    cin >> nombreArchivo;
    limpiaBuffer();
    iniciaCarril(carretera);
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
* Dibuja la primera linea del carril compuesta por las sorpresas y clavos; y la segunda linea del carril en la que se situa el coche
*/
void dibujaCarril(const tCarretera carretera, tCoche& coche) {
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
    int i = 0; 
    while (i < LONG_CARRETERA && i < coche.pos) {
        cout << ' ';
        i++;
    }
    cout << CHAR_COCHE;
    while (i < LONG_CARRETERA - 1) {
        cout << ' ';
        i++;
    }
    cout << CHAR_LINEA_VERTICAL << "\n";
}

/*
* Dibuja la linea horizontal superior
*/
void dibujaLineaHorizontalSuperior() {
    cout << CHAR_ESQUINA_SUPERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_SUPERIOR_DERECHA;
}

/*
* Dibuja la linea horizontal inferior
*/
void dibujaLineaHorizontalInferior() {
    cout << CHAR_ESQUINA_INFERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_INFERIOR_DERECHA;
}

/*
* Llama a todas las funciones relacionadas con la impresion de la carretera en pantalla
*/
void dibujaCarretera(const tCarretera carretera, tCoche& coche) {
    dibujaLineaHorizontalSuperior();
    cout << "\n";
    dibujaCarril(carretera, coche);
    dibujaLineaHorizontalInferior();
    cout << "\n";
}

////////////////////////////////////////// PRACTICA 2.1

/*
* Verifica si la posicion del coche es sorpresa 
*/
bool esSorpresa(const tCarretera carretera, tCoche& coche) {
    return carretera[coche.pos] == SORPRESA;
}

/*
* Verifica si la posicion del coche es clavo
*/
bool esClavo(const tCarretera carretera, tCoche& coche) {
    return carretera[coche.pos] == CLAVO;
}

/*
* Verifica si la posicion del coche esta en la carretera
*/
bool enCarrtera(int n) {
    return  (0 <= n && n < LONG_CARRETERA);
}

/*
* Verifica si la posicion del coche ha llegado a la meta
*/
bool haLlegado(tCoche& coche) {
    return (coche.pos >= LONG_CARRETERA);
}

/*
* Busca o encuentra la nueva posicion sorpresa desde donde se encuentra el coche en la carrtera
*/
int buscaPosicionSorpresa(const tCarretera carretera, int posIni, int incr, tCoche coche, int newPos) {
    int i = coche.pos;
    if (incr == 1) {
        i++;
        while (carretera[i] != SORPRESA && enCarrtera(i)) i++;
        if (carretera[i] == SORPRESA) newPos = i;
    }
    else if (incr == -1) {
        i--;
        while (carretera[i] != SORPRESA && enCarrtera(i)) i--;
        if (carretera[i] == SORPRESA) newPos = i;
    }
    else newPos = 0;
    return newPos;
}

/*
* Imprime en pantalla las consecuencias de que el coche se situe en la posicion de un clavo o una sorpresa
*/
bool calculaPosicion(const tCarretera carretera, tCoche& coche) {
    if (esClavo(carretera, coche)) {
        coche.tiempoParado = TIEMPO_PARADO;
        cout << "EL COCHE HA PINCHADO. ESTARA INMOVILIZADO " << TIEMPO_PARADO << " PASOS\n";
        if (coche.tiempoParado > 0) {
            cout << "EL COCHE ESTA PINCHADO. LE QUEDAN " << coche.tiempoParado << " PASOS PARA MOVERSE";
            if (DEBUG) {
                limpiaBuffer();
            }
            limpiaBuffer();
            coche.tiempoParado--;
            while (coche.tiempoParado > 0) {
                cout << "EL COCHE ESTA PINCHADO. LE QUEDAN " << coche.tiempoParado << " PASOS PARA MOVERSE";
                limpiaBuffer();
                coche.tiempoParado--;
            }
        }
    }
    else if (esSorpresa(carretera, coche)) {
        cout << "POSICION SORPRESA.\n";
        int posIni = 0, incr = 0, newPos = 0, oldPos = 0;
        if (DEBUG) {
            cout << "Introduce 1 si deseas avanzar o -1 si deseas retroceder:";
            cin >> incr;
        }
        else {
            while (incr == 0) incr = -1 + rand() % ((1 + 1) - (-1));
        }
        oldPos = coche.pos;
        coche.pos = buscaPosicionSorpresa(carretera, posIni, incr, coche, newPos);
        if (oldPos < coche.pos) cout << "AVANZAS HASTA LA SIGUIENTE SORPRESA EN LA POSICION " << (coche.pos + 1) << "\n";
        else if (oldPos > coche.pos && coche.pos != 0) cout << "RETROCEDES HASTA LA SORPRESA ANTERIOR EN LA POSICION " << (coche.pos + 1) << "\n";
        else cout << "VUELVES AL INICIO.\n";
        dibujaCarretera(carretera, coche);
        return true;
    }
    return false;
}

/*
* Se encarga de que se introduzca cuanto avanza el coche y de que supone, si un avance o un retroceso
*/
int avanza(tCoche& coche) {
    int numPasos = 0, newPos = coche.pos;
    if (!DEBUG) {
        cout << "Pulsa una tecla para continuar";
        limpiaBuffer();
        numPasos = 1 + rand() % (MAX_PASOS + 1 - 1);
    }
    else {
        cout << "Introduce un numero para continuar: ";
        cin >> numPasos;
    }
    newPos = newPos + numPasos;
    if (newPos < 0) {
        cout << "VUELVES AL INICIO. TE HAS SALIDO DE LA CARRETERA.\n";
        return 0;
    }
    else if (numPasos < 0) cout << "EL COCHE RETROCEDE " << numPasos << " PASOS\n";
    else cout << "EL COCHE AVANZA " << numPasos << " PASOS\n";
    return newPos;
}

/*
* Llama a todas las funciones relacionadas con el avance del coche
*/
void avanzaCarril(const tCarretera carretera, tCoche& coche) {
    if (!haLlegado(coche)) {
        calculaPosicion(carretera, coche);
        coche.pos = avanza(coche);
        dibujaCarretera(carretera, coche);
    }
}

/*
* Llama a todas las funciones relacionadas con la simulacion total de la carrtera
*/
void simulaCarrera(const tCarretera carretera, tCoche& coche) {
    calculaPosicion(carretera, coche);
    coche.pos = avanza(coche);
    dibujaCarretera(carretera, coche);
    while (!haLlegado(coche)) avanzaCarril(carretera, coche);
    if (haLlegado(coche)) cout << "HA LLEGADO A LA META\n";
}

/*
* Comienza el programa, si y solo si el archivo carga correctamente, luego vuelve a llamar a producirse si se desea realizar otra simulacion
*/
int main() {
    tCarretera carretera;
    tCoche coche;
    char newGame = 'Y';
    srand(time(NULL));
    if (cargaCarretera(carretera)) {
        while (newGame == 'y' || newGame == 'Y') {
            iniciaCoche(coche);
            dibujaCarretera(carretera, coche);
            simulaCarrera(carretera, coche);
            cout << "DESEA REALIZAR OTRA SIMULACION? (y/n): ";
            cin >> newGame;
            limpiaBuffer();
        }
    }
    else cout << "Error al abrir el archivo\n";
    cout << "PARTIDA FINALIZADA\n";
    return 0;
}

// Practica 2.1
/*
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

tTipoPosicion stringToEnum(string s) {
    if (s == "CLAVO") return tTipoPosicion(CLAVO);
    else if (s == "SORPRESA") return tTipoPosicion(SORPRESA);
    return tTipoPosicion(0);
}

void inicializaCarretera(tCarretera carretera) {
    for (int i = 0; i < LONG_CARRETERA; i++) {
        carretera[i] = NORMAL;
    }
}

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

void dibujaLineaHorizontalSuperior() {
    cout << CHAR_ESQUINA_SUPERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_SUPERIOR_DERECHA;
}

void dibujaLineaHorizontalInferior() {
    cout << CHAR_ESQUINA_INFERIOR_IZQUIERDA << setw(LONG_CARRETERA) << setfill(CHAR_LINEA_HORIZONTAL) << CHAR_LINEA_HORIZONTAL << CHAR_ESQUINA_INFERIOR_DERECHA;
}

void dibujaCarretera(tCarretera carretera, int posCoche) {
    dibujaLineaHorizontalSuperior();
    cout << "\n";
    dibujaCarril(carretera, posCoche);
    dibujaLineaHorizontalInferior();
    cout << "\n";
}

int main() {
    tCarretera carretera;
    int posCoche = 7;
    if (cargaCarretera(carretera)) dibujaCarretera(carretera, posCoche);
    else cout << "Error al abrir el archivo\n";
    return 0;
}
*/