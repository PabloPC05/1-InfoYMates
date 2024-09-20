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
const int NUM_CARRILES = 3;
const int MAX_CARRERAS = 2;
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
const string CENTINELA = "XX";
enum tTipoPosicion { NORMAL, CLAVO, SORPRESA };
struct tCoche {
    int pos;
    int tiempoParado;
};
struct tCarril {
    tCoche coche;
    tTipoPosicion posicion[LONG_CARRETERA];
};
using tCarretera = tCarril[NUM_CARRILES];

struct tClasificacion {
    string idCarrera;
    int clasificacion[NUM_CARRILES];
    int cont;
};
struct tListaClasificacion {
    tClasificacion lista[MAX_CARRERAS];
    int cont;
};

tTipoPosicion stringToEnum(string s) {
    if (s == "CLAVO") return CLAVO;
    else if (s == "SORPRESA") return SORPRESA;
    return NORMAL;
}

/*
* Se encarga de limpiar el buffer en determinados casos
*/
void limpiaBuffer() {
    cin.ignore();
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
void iniciaCarril(tCarril& carril) {
    int j = 0;
    while (j < LONG_CARRETERA) {
        carril.posicion[j] = NORMAL;
        j++;
    }
}

/*
* Carga un carril entero desde el archivo .txt
*/
void leeCarril(ifstream& archivo, tCarril& carril) {
    string tipoObjeto;
    int numObjetos, posObjetos;
    archivo >> tipoObjeto;
    while (tipoObjeto != CENTINELA) {
        archivo >> numObjetos;
        for (int i = 0; numObjetos > i; i++) {
            archivo >> posObjetos;
            carril.posicion[posObjetos] = stringToEnum(tipoObjeto);
        }
        archivo >> tipoObjeto;
    }
}

/*
* Verifica que el archivo esta abierto o se encuentra en la ubicacion y carga los clavos y sorpresas en el array
*/
bool cargaCarretera(tCarretera carriles) {
    string nombreArchivo, tipoObjeto;
    ifstream archivo;
    int numObjetos, posObjetos, i = 0;
    cout << "Dame el nombre del archivo: ";
    cin >> nombreArchivo;
    limpiaBuffer();
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) return false;
    for (int i = 0; i < NUM_CARRILES; i++) {
        iniciaCarril(carriles[i]);
        leeCarril(archivo, carriles[i]);
    }
    archivo.close();
    return true;
}
/*
* Dibuja la primera linea del carril compuesta por las sorpresas y clavos; y la segunda linea del carril en la que se situa el coche
*/
void dibujaCarril(const tCarril& carril) {
    string carrtera2;
    cout << CHAR_LINEA_VERTICAL;
    for (int i = 0; i < LONG_CARRETERA; i++) {
        switch (carril.posicion[i]) {
        case NORMAL: cout << CHAR_NORMAL; break;
        case CLAVO: cout << CHAR_CLAVO; break;
        case SORPRESA: cout << CHAR_SORPRESA; break;
        }
    }
    cout << CHAR_LINEA_VERTICAL << "\n" << CHAR_LINEA_VERTICAL;
    int i = 0;
    while (i < LONG_CARRETERA && i < carril.coche.pos) {
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

void dibujaLineaDiscontinua() {
    int i = 0;
    cout << CHAR_LINEA_VERTICAL;
    while (i <= LONG_CARRETERA - 1) {
        cout << CHAR_LINEA_HORIZONTAL;
        i++;
        if (i <= LONG_CARRETERA - 1) {
            cout << ' ';
            i++;
        }
    }
    cout << CHAR_LINEA_VERTICAL << "\n";
}

/*
* Llama a todas las funciones relacionadas con la impresion de la carretera en pantalla
*/
void dibujaCarretera(const tCarretera carriles) {
    int i = 0;
    dibujaLineaHorizontalSuperior();
    cout << "\n";
    while (NUM_CARRILES > i) {
        dibujaCarril(carriles[i]);
        if (NUM_CARRILES > 1 && i < NUM_CARRILES - 1) {
            dibujaLineaDiscontinua();
        }
        i++;
    }
    dibujaLineaHorizontalInferior();
    cout << "\n";   
}

/*
* Verifica si la posicion del coche es sorpresa
*/
bool esSorpresa(const tTipoPosicion pos[], int p) {
    return pos[p] == SORPRESA;
}

/*
* Verifica si la posicion del coche es clavo
*/
bool esClavo(const tTipoPosicion pos[], int p) {
    return (pos[p] == CLAVO);
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
int buscaSiguientePosSorpresa(const tCarril& carril, int incr) {
    int posIni2 = carril.coche.pos, newPos = 0;
    do{
        if (incr == 1) {
            posIni2++;
        }
        else if (incr == -1) {
            posIni2--;
        }
    }
    while (enCarrtera(posIni2) && carril.posicion[posIni2] != SORPRESA);
    if (carril.posicion[posIni2] == SORPRESA) {
        newPos = posIni2;
    }
    return newPos;
}

/*
* Imprime en pantalla las consecuencias de que el coche se situe en la posicion de un clavo o una sorpresa
*/
bool calculaPosicion(tCarril& carril) {
    bool esSorpresaValue = esSorpresa(carril.posicion, carril.coche.pos);       //se guarda el valor de la funcion esSorpresa para evitar llamarla dos veces cuando se devuelve un valor
    if (esSorpresaValue) {
        cout << "HAS CAIDO EN UNA SORPRESA.\n";
        int posIni = carril.coche.pos, incr = 0;
        if (DEBUG) {
            cout << "Introduce 1 si deseas avanzar o -1 si deseas retroceder:";
            cin >> incr;
        }
        else {
            incr = (rand() % 2 == 0) ? -1 : 1;
        }
        carril.coche.pos = buscaSiguientePosSorpresa(carril, incr);
        if (posIni < carril.coche.pos) cout << "Avanzas hasta la proxima sorpresa en la posicion " << (carril.coche.pos + 1) << "...\n";
        else if (posIni > carril.coche.pos && carril.coche.pos != 0) cout << "Retrocedes hasta la sorpresa anterior en la posicion " << (carril.coche.pos + 1) << "...\n";
        else cout << "Te toca empezar de nuevo... No habia sorpresas en tu camino...\n";
    }
    else if (esClavo(carril.posicion, carril.coche.pos)) {
        carril.coche.tiempoParado = TIEMPO_PARADO;
        cout << "Tu coche ha pinchado. Estara inmovilizado " << TIEMPO_PARADO << " pasos\n";
    }
    return esSorpresaValue;
}

/*
* Se encarga de que se introduzca cuanto avanza el coche y de que supone, si un avance o un retroceso
*/
int avanza(int pos) {
    int numPasos = 0;
    if (!DEBUG) {
        cout << "Pulsa una tecla para continuar";
        limpiaBuffer();
        numPasos = 1 + rand() % (MAX_PASOS + 1 - 1);
    }
    else {
        cout << "Introduce un numero para continuar: ";
        cin >> numPasos;
    }
    pos = pos + numPasos;
    if (pos < 0) {
        cout << "VUELVES AL INICIO. TE HAS SALIDO DE LA CARRETERA.\n";
        pos = 0;
    }
    else if (numPasos < 0) cout << "El coche retrocede " << numPasos << " pasos\n";
    else cout << "El coche avanza " << numPasos << " pasos\n";
    return pos;
}

/*
* Llama a todas las funciones relacionadas con el avance del coche
*/
bool avanzaCarril(tCarretera carriles, int i) {
    char c;
    bool haLlegadoValue = false;
    if (!haLlegado(carriles[i].coche)) {
        if (carriles[i].coche.tiempoParado > 0) {
            cout << "Coche en carril " << i << " pinchado. Te quedan " << carriles[i].coche.tiempoParado << " pasos para continuar";
            if (cin.rdbuf()->in_avail() != 0) limpiaBuffer(); //con la funcion rdbuf que lee la direccion de memoria del buffer que la pasa a la funcion in_avail que se encarga de contar cuantos caracteres hay en el buffer, por tanto si es diferente de 0, llama a limpiaBuffer
            limpiaBuffer();
            carriles[i].coche.tiempoParado--;
        }
        else {
            cout << "Avanzando en el carril " << i << "...\n";
            carriles[i].coche.pos = avanza(carriles[i].coche.pos);
            calculaPosicion(carriles[i]);
            dibujaCarretera(carriles);
            haLlegadoValue = haLlegado(carriles[i].coche);
        }
    }
    return haLlegadoValue;
}

/*
* Llama a todas las funciones relacionadas con el avance de los coches
*/
void avanzaCarriles(tCarretera carriles, tClasificacion& clasificacion) {
    for (int i = 0; i < NUM_CARRILES; i++) {  
        if (avanzaCarril(carriles, i) && clasificacion.clasificacion[clasificacion.cont] == -1) {
            cout << "Ha llegado a la meta...\n";
            clasificacion.clasificacion[clasificacion.cont] = i;
            clasificacion.cont++;
        }
    }
}

/*
* Inicializa los valores de la clasificacion a -1
*/
void iniciaClasificacion(tClasificacion& clasificacion) {
    clasificacion.cont = 0;
    for (int i = 0; i < NUM_CARRILES; i++) {
        clasificacion.clasificacion[i] = -1;
    }
}

/*
* Llama a todas las funciones relacionadas con la simulacion total de la carrtera
*/
tClasificacion simulaCarrera(tCarretera carriles) {
    tClasificacion clasificacion;
    clasificacion.cont = 0;         //se inicializa a 0 la cantidad de coches que han llegado a la meta
    iniciaClasificacion(clasificacion);
    cout << "Dame un identificador para la carrera: ";
    cin >> clasificacion.idCarrera;
    limpiaBuffer();
    dibujaCarretera(carriles);
    while (clasificacion.cont < NUM_CARRILES) {
        avanzaCarriles(carriles, clasificacion);
    }
    return clasificacion;
}

/*
* Imprime en el archivo .txt la clasificacion de la carrera
*/
ostream& operator<<(ostream& salida, tClasificacion const& cl) {
    salida << "Clasificacion de la carrera " << cl.idCarrera << "\n";
    for (int i = 0; i < NUM_CARRILES; i++) {
        salida << "\t Puesto " << i + 1 << ": Coche en el carril " << cl.clasificacion[i] << "\n";
    }
    return salida;
}

/*
* Inicializa los valores de listaC a 0, sin meterse en las clasificaciones de las carreras
*/
void iniciaListaClasificacion(tListaClasificacion& listaC) {
    listaC.cont = 0;        //se inicializa a 0 el contador de el número máximo de carreras
    for (int i = 0; i < MAX_CARRERAS; i++) {
        listaC.lista[i].cont = 0;
    }
}

/*
* Elimina la clasificacion de la carrera que se encuentra en la posicion pos
*/
void eliminaClasificacion(tListaClasificacion& listaC, int pos) {
    for (int i = 0; i+1 < MAX_CARRERAS; i++) {
        listaC.lista[i] = listaC.lista[i + 1];
    }
    listaC.lista[pos].cont = 0;
    for (int i = 0; i < NUM_CARRILES; i++) {
        listaC.lista[pos].clasificacion[i] = 0;
    }
}

/*
* Inserta la clasificacion de la carrera en la lista de clasificaciones
*/
void insertaClasificacion(tListaClasificacion& listaC, const tClasificacion& clasificacion) {
    if (listaC.cont >= MAX_CARRERAS) {
        eliminaClasificacion(listaC, MAX_CARRERAS);
        listaC.cont = listaC.cont-1;
    }
    listaC.lista[listaC.cont] = clasificacion;
}

/*
* Se encarga de abrir, llamar a la funcion operator<<, que imprime la lista de clasificaciones en el archivo .txt y cerrar el archivo. Devuelve true si y solo si el archivo se abre correctamente
*/
bool guardaListaClasificacion(const tListaClasificacion& listaC) {
    ofstream archivo;
    archivo.open("clasificacion.txt");  
    if (!archivo.is_open()) return false;
    for (int i = 0; i <= listaC.cont-1; i++) {
        operator<<(archivo, listaC.lista[i]);
    }
    archivo.close();
    return true;
}

/*
* Comienza el programa, si y solo si el archivo carga correctamente, luego vuelve a llamar a producirse si se desea realizar otra simulacion
*/
int main() {
    tCarretera carriles;
    tListaClasificacion listaC;
    char newGame = 'Y';
    srand(time(NULL));
    if (cargaCarretera(carriles)) {
        iniciaListaClasificacion(listaC);
        while (newGame == 'y' || newGame == 'Y') {
            for (int i = 0; i < NUM_CARRILES; i++) {
                iniciaCoche(carriles[i].coche);
            }
            insertaClasificacion(listaC, simulaCarrera(carriles));
            for (int i = 0; i < NUM_CARRILES; i++) {
                cout << "\t Puesto " << i + 1 << ": Coche en el carril " << listaC.lista[listaC.cont].clasificacion[i] << "\n";
            }
            cout << "Quieres jugar otra partida? (y/n): ";
            cin >> newGame;
            limpiaBuffer();
            listaC.cont++;
        }
        if (guardaListaClasificacion(listaC)) {
            cout << "PARTIDA FINALIZADA\n";
        }
        else {
            cout << "Error al guardar el archivo\n";
        }
    }
    else cout << "Error al abrir el archivo\n";
    return 0;
}