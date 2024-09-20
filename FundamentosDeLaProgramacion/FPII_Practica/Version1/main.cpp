#include "Juego.h"
using namespace std;

void leerPartida(Juego& solitario) {
    ifstream archivo;
    string nameArchivo;
    do {
        cout << "Introduce el nombre del archivo: ";
        cin >> nameArchivo;
        archivo.open(nameArchivo);
    } while (!archivo.is_open());
    solitario.cargar(archivo);
}

void generarTableroAleatorio(Juego& solitario) {
    cout << "Introduce la dimension del tablero [filas x columnas]: ";
    int filas, columnas;
    cin >> filas >> columnas;
    if (filas > 10 || columnas > 10) {
        cout << RED << "El tablero no puede tener mas de 10 filas o columnas\n" << RESET;
        generarTableroAleatorio(solitario);
    }
    solitario.generarJuegoAleatorio(filas, columnas);
}

void leerTitulo() {
    cout << "Bienvenido al juego del solitario\n";
    cout << "\t El objetivo del juego es que quede una unica ficha en el tablero en la posicion de meta\n";
    cout << "\t Para ello, se deben ir comiendo las fichas igual que en el juego de las damas, pero solo en horizontal y vertical\n";
    cout << "\t\tLas fichas se representan por el color" << colorficha << " ROSA" << RESET << endl;
    cout << "\t\tLos espacios vacios por el color" << colorvacia << " GRIS" << RESET << endl;
    cout << "\t\tLos espacios nulos, i.e.aquellos en los que no se puede colocar una ficha con el color " << BG_WHITE << colornula << "NEGRO" << RESET << RESET;
    cout << "\n\t\tY por ultimo la ficha de meta tiene el color" << colormeta << " VERDE" << RESET << "\n\n";
}

void ejecutarJuego() {
    Juego solitario;
    leerTitulo();
    cout << "Desea jugar con un tablero preestablecido o con un tablero aleatorio? [P/A]: ";
    char respuesta;
    IntroducirVerificarRespuesta(respuesta, 'p', 'a');
    if (respuesta == 'p') leerPartida(solitario);
    else generarTableroAleatorio(solitario);
    solitario.mostrar();
    do {
        Movimiento mov = solitario.leerMovimiento();
        solitario.jugar(mov);
        solitario.mostrar();
        solitario.actualizarEstado();
    } while (solitario.getEstado() == JUGANDO);
    if (solitario.getEstado() == GANADOR) {
        cout << GREEN << "Enhorabuena, has ganado\n" << RESET;
    }
    else {
        cout << RED << "No hay mas movimientos posibles\n" << RESET;
        cout << RED << "Tiene a su disposicion un archivo con las soluciones que usted tendria que haber seguido para ganar\n" << RESET;
    }
    if (respuesta == 'a') cout << CYAN << "Tiene a su disposicion un archivo con el tablero generado, llamado tableroGenerado.txt, para que pueda jugarlo en otra ocasion\n" << RESET;
}

int main() {
    char respuesta;
    do {
        ejecutarJuego();
        cout << "Fin del juego.\n Deseas jugar otra partida? [S/N]: ";
        IntroducirVerificarRespuesta(respuesta, 's', 'n');
    } while (respuesta == 's');
    cout << YELLOW << "Una pena, hasta la proxima\n" << RESET;
    return 0;
}