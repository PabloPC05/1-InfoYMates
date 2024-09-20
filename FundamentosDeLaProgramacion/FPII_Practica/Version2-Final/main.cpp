//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "gestorPartidas.h"
#include "memoryleaks.h"
using namespace std;

const int DIMMAX = 10;
const int DIMMIN = 3;

//Dada una respuesta, y las dos posibles, la funcion se encarga de introducir y verificar que la respuesta sea valida
void IntroducirVerificarRespuesta(char& respuesta, const char& respuesta1, const char& respuesta2) {
    bool valido;
    do {
        cin >> respuesta;
        respuesta = tolower(respuesta);
        valido = respuesta == respuesta1 || respuesta == respuesta2;
        if (!valido) cout << RED << "Introduce una respuesta valida: " << RESET;
    } while (!valido);
}

//Funcion encargada de preguntar al jugador si quiere seguir jugando, en caso negativo devuelve false, y se vuelve a la pantalla de escoger un nuevo juego
//En caso negativo se pide la informacion para que ingrese un nuevo usuario
bool continuarJugando() {
    char respuesta;
    cout << "Desea seguir jugando? [S/N]: ";
    IntroducirVerificarRespuesta(respuesta, 's', 'n');
    system("cls");
    return respuesta == 's';
}

//Funcion que se encarga de guardar las partidas en el archivo de donde se cargaron
void guardarPartidas(GestorPartidas& gestor) {
	ofstream archivoPartidas;
	archivoPartidas.open(gestor.getNombreArchivo());
	gestor.salvar(archivoPartidas);
	archivoPartidas.close();
}


//Funcion que se encarga de comprobar si la ficha introducida esta dentro de los limites del tablero
bool EstaDentroDelTablero(const par& f, Juego& Solitario) {
    if (!Solitario.enLimites(f)) {
        cout << RED << "Introduce una ficha dentro de los limites del tablero\n" << RESET;
        return false;
    }
    return true;
}

//Funcion que se encarga de comprobar si la celda introducida es una ficha
bool LaCeldaEsFicha(const par& f, Juego& Solitario) {
    if (!Solitario.fichaValida(f)) {
        cout << RED "Introduce una celda con una ficha\n" << RESET;
        return false;
    }
    return true;
}

//Funcion que se encarga de comprobar si la ficha introducida se puede mover
bool LaFichaSePuedeMover(Movimiento& mov, Juego& solitario) {
    solitario.posiblesMovimientos(mov);
    if (mov.getNumDirs() == 0) {
        cout << RED << "No hay posibles movimientos con esa ficha\n" << RESET;
        return false;
    }
    return true;
}

/*
*   Esta funcion se encarga de leer los movimientos que se realizan desde la consola. Su funcionamiento es:
*       1) Pide al jugador que introduzca una ficha
*       2) Establece las posibles direcciones que puede tomar la ficha
*       3) Si se introduce una ficha invalida por las condiciones se�aladas, se vuelve a pedir una ficha
*          Ademas, advierte al jugador segun el error cometido
*       4) Devuelve el movimiento
*/
Movimiento leerMovimiento(Juego& solitario) {
    Movimiento mov;
    par ficha;
    cout << "Selecciona una FICHA (fila y columna) o introduce 0 0 para salir: ";
    cin >> ficha;
    mov.setFicha(ficha);    //Establece la ficha a mover
    if (ficha != par(-1, -1)) {
        if (!EstaDentroDelTablero(mov.getFicha(), solitario) ||
            !LaCeldaEsFicha(mov.getFicha(), solitario) ||
            !LaFichaSePuedeMover(mov, solitario)) leerMovimiento(solitario);
    }
    return mov;
}


//Funcion que se encarga de ejecutar el juego, es decir, de que el jugador juegue hasta que gane o pierda
bool ejecutarJuego(Juego& solitario) {
    char respuesta;
    system("cls"); // borrar consola
    solitario.mostrar();
    do {
        Movimiento mov = leerMovimiento(solitario);
        if (mov.getFicha() == par(-1, -1)) return false;
        solitario.jugar(mov);
        system("cls"); // borrar consola
        solitario.mostrar();
        solitario.actualizarEstado();
    } while (solitario.getEstado() == JUGANDO);
    if (solitario.getEstado() == GANADOR) {
        cout << GREEN << "Enhorabuena, has ganado\n" << RESET;
    }
    else {
        cout << RED << "No hay mas movimientos posibles\n" << RESET;
        //cout << RED << "Tiene a su disposicion un archivo con las soluciones que usted tendria que haber seguido para ganar\n" << RESET;
    }
    return true;
}

//Comprueba que la dimension introducida por el usuario es valida para crear un tablero
bool dimensionAdecuada(const par& dimension) {
    return (DIMMIN <= dimension.first && dimension.first <= DIMMAX) && (DIMMIN <= dimension.second && dimension.second <= DIMMAX);
}

/*
*   Se encarga de recopilar la informacion necesaria para generar aleatoriamente un juego, es decir, la dimensaion, la ficha de meta y el numero de movimientos
*   Para pedir la dimension del tablero, se sirve de una recursividad en caso de que el tablero tenga mas de 10 filas o columnas
*   Para la ficha de meta, se pregunta si se quiere que sea aleatoria o que sea introducida por el jugador, y se hace lo propio
*   Finalmente se pide el numero de movimientos y se llama a la funcion insertarAleatoria() que se encargara de insertar el juego al final de la lista de partidas del jugador
*   y de llamar a la funcion encargada de que se genere el tablero aleatoriamente
*/
void generarJuegoAleatorio(GestorPartidas& gestor) {
    par dimension;
    char respuesta;
    cout << "Introduce la dimension del tablero [filas x columnas]: ";
    cin >> dimension;
    dimension = dimension + par(1, 1);
    if (!dimensionAdecuada(dimension)) {
        cout << RED << "El tablero debe tener como minimo 3 filas y columnas  y 10 filas y columnas como maximo \n" << RESET;
        generarJuegoAleatorio(gestor);
    }
    cout << "Desea introducir una ficha de meta o que se genere aleatoriamente? [I/A]:";
    IntroducirVerificarRespuesta(respuesta, 'i', 'a'); //Introduce y verifica una respuesta valida
    par fichaMeta;
    if (respuesta == 'i') {
        do {
            cout << "Introduce la ficha de meta (fila y columna): ";
            cin >> fichaMeta;
            //Si la ficha de meta no esta dentro de los limites del tablero, se le pide al jugador que la introduzca de nuevo
            if (dimension.first < fichaMeta.first || dimension.second < fichaMeta.second) cout << RED << "Introduce una ficha de meta dentro del tablero escogido\n";
        } while (dimension.first < fichaMeta.first || dimension.second < fichaMeta.second);
    }
    else {
        fichaMeta.first = rand() % dimension.first;
        fichaMeta.second = rand() % dimension.second;
    }
    cout << "Seleccione la dificultad" << "[Introduzca el numero de movimientos hasta la meta]\n";
    cout << RED << "Tenga en cuenta que puede que haya errores si se escoge un numero de movimientos entre " << (dimension.first * dimension.second) / 2 << " o mas, con un maximo posible de " << dimension.first * dimension.second << RESET << ": ";
    int numMovimientos;
    cin >> numMovimientos;  //Introduce el numero de movimientos que quiere que haya hasta llegar a la meta
    gestor.insertarAleatoria(numMovimientos, fichaMeta, dimension); //Crea una nueva partida con los datos introducidos
}

//Funcion que imprime en pantalla las partidas comenzadas por el usuario activo y le pide que escoja una o que genere aleatoriamente una nueva
//En caso de que no haya partidas, automaticamente genera una nueva partida aleatoria con las caracteristicas que quiera el usuario, a traves de generarJuegoAleatorio()
int escogerJuego(GestorPartidas& gestor) {
    int indexPartida;
    if (gestor.tienePartidas()) {
        cout << "Tus Partidas empezadas: ";
        gestor.mostrarPartidasEmpezadas();
        cout << "Elige una partida para continuar o introduce '0' para empezar una nueva partida aleatoria: ";
        cin >> indexPartida;
        indexPartida--;
        if (indexPartida == -1) {
            generarJuegoAleatorio(gestor);
            indexPartida = gestor.getNumPartidas();
            indexPartida--;
        }
    }
    else {
        cout << "No tienes partidas. Vamos a crear un juego aleatorio...\n";
        cout << "En todo momento vas a disponer de un archivo con la solucion del tablero que se te genere\n";
        generarJuegoAleatorio(gestor);
        indexPartida = gestor.getNumPartidas();
        indexPartida--;
    }
    return indexPartida;
}

//Funcion que pide al jugador que introduzca su nombre de usuario y que devuelve true si el jugador quiere seguir jugando y false en caso contrario
bool askForUser(GestorPartidas& gestor) {
    cout << "Introduce tu nombre de usuario (FIN para terminar): ";
    string user;
    cin >> user;
    if (user == "FIN" || user == "fin") return false;
    gestor.login(user);
    return true;
}

/*
*   Dado el gestor de partidas, se encarga de que el usuario introduzca el nombre del archivo,
*   que se abra, y que cargue la informacion contenida en el archivo, en el gestor
*/
void ejecutarGestor(GestorPartidas& gestor) {
    cout << "Introduce el nombre del archivo con las partidas comenzadas: ";
    string nombreArchivo;
    ifstream archivoPartidas;
    do {
        cin >> nombreArchivo;
        gestor.setNombreArchivo(nombreArchivo);
        archivoPartidas.open(nombreArchivo);
        if (!archivoPartidas.is_open()) cout << RED << "No se ha podido abrir el archivo\n" << RESET;
    } while (!archivoPartidas.is_open());
    gestor.cargar(archivoPartidas);
    archivoPartidas.close();
}

//Funcion que imprime en pantalla el titulo del juego
void leerTitulo() {
    cout << "Bienvenido al juego del solitario\n";
    cout << "\t El objetivo del juego es que quede una unica ficha en el tablero en la posicion de meta\n";
    cout << "\t Para ello, se deben ir comiendo las fichas igual que en el juego de las damas, pero solo en horizontal y vertical\n";
    cout << "\t\tLas fichas se representan por el color" << colorficha << " ROSA" << RESET << endl;
    cout << "\t\tLos espacios vacios por el color" << colorvacia << " GRIS" << RESET << endl;
    cout << "\t\tLos espacios nulos, i.e.aquellos en los que no se puede colocar una ficha con el color " << BG_WHITE << colornula << "NEGRO" << RESET << RESET;
    cout << "\n\t\tY por ultimo la ficha de meta tiene el color" << colormeta << " VERDE" << RESET << "\n\n";
}


/*
*   El main comienza leyendo el titulo del juego solitario. Pide el archivo en el que estan ubicadas las partidas comenzadas y sus respectivos usuarios.
*   Para empezar a jugar sigue el siguiente funcionamiento ciclico: 
*       1) Pide al jugador su usuario con la posibilidad de que introduzca FIN o fin para que termine la simulacion
*       2) Pide al jugador que seleccione el juego al que quiere jugar con escogerJuego, en caso de que no tenga juegos, la propia funcion llama a insertarJuegoAleatorio
*          para que cree una nueva partida aleatoria
*       3) Llama a la funcion ejecutarJuego() que se encarga del funcionamiento del juego y que devuelve false si y solo si el jugador introduce la ficha {0, 0}
*          cuando no quiere seguir jugando, en general o en concreto a esa partida. Y en caso de que haya ganador o la partida se haya bloqueao, se elimina la partida.
*       4) Luego se pregunta al jugador si quiere seguir jugando: Si no quiere, se elimina al jugador como usuario activo y en caso de que solo al hacer logout
*          no tenga ninguna partida, elimina al jugador del gestor
*       5) Por ultimo guarda la partida en el mismo archivo del que ha sacado la informacion y vuelve al paso 1) si el jugador quiere seguir jugando
*/
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(time(NULL));
    leerTitulo();
    GestorPartidas gestor;
    ejecutarGestor(gestor);
    bool ContinuarJugando;
    while (askForUser(gestor)) {
        do {
            int indiceJuegoEscogido = escogerJuego(gestor);
            if (ejecutarJuego(gestor.partida(indiceJuegoEscogido)) && 
               (gestor.partida(indiceJuegoEscogido).getEstado() == GANADOR || 
               gestor.partida(indiceJuegoEscogido).getEstado() == BLOQUEO)) {
                gestor.eliminarPartida(indiceJuegoEscogido);
            }
            ContinuarJugando = continuarJugando();
            if (!ContinuarJugando) gestor.eliminarUsuarioActivo();
            guardarPartidas(gestor);
        } while (ContinuarJugando);
    }
	return 0;
}