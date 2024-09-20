//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "movimiento.h"
#include "tablero.h"
#include "colores.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>


enum Estado { JUGANDO, GANADOR, BLOQUEO };


class Juego {
private:
    //Atributos
    Tablero tablero;  //Tablero de juego
    par fichaMeta;  //Ficha meta
    Estado estadoInt;  //Estado del juego
    pares fichas;  //Vector de fichas
    std::ofstream solucion; //Archivo de solucion

    //Funcion generalizada que dada una ficha y una celda, se encarga de actualizar el tablero y el vector de fichas
    void establecerFicha(par ficha, Celda cel);

    //Funcion que dado un movimiento, se encarga de actualizar el tablero y el vector de fichas segun el mismo
    void ejecutaMovimientoSeleccionado(Movimiento const& mov);

    //Comprueba si hay ganador
    Estado hayGanador() const;

    //Comprueba si hay movimientos posibles i.e. si hay bloqueo
    Estado hayMovimientos() const;

    //Metodos que se encargan de generar el tablero aleatoriamente
    void generarMovimientosAleatorios(int N);  //Genera movimientos aleatorios
    void establecerMovimientoGenerado(Direccion d, par ficha);  //Escribe  el movimiento en el tablero y en el vector de fichas
    Direccion generarDireccion(par ficha);  //Dada una ficha genera una direccion aleatoria que puede tomar
    bool disponibleGenerar(par f, Direccion d) const; //Devuelve si y solo si se puede generar un movimiento en la direccion d, segun las circunstancias del tablero generado

    bool disponibleParaMover(par f, Direccion d) const;  //Devuelve si y solo si la ficha f puede moverse en la direccion d, segun las circunstancias del juego

    //Setter del estado del juego
    void setEstado(Estado e) { estadoInt = e; }

    //Getter y setter de la ficha de meta
    int getFilaMeta() const { return fichaMeta.first; }
    int getColumnaMeta() const { return fichaMeta.second; }
    par getFichaMeta() const { return fichaMeta; }
    void setFichaMeta(par& ficha) { fichaMeta = ficha;  }
    void setFilaMeta(int f) { fichaMeta.first = f; }
    void setColumnaMeta(int c) { fichaMeta.second = c; }


    int indiceFicha(par d) const;  //Devuelve el indice de la ficha

    //Funciones que se encargan de mostrar el tablero
    void color_fondo(int color);
    void pinta_cabecera();
    void pinta_linea(char esquinaIzda, char cruce, char esquinaDer);
    void pinta_borde_celda(int fila);
    void pinta_centro_celda(int fila);

public:
    //Constructor de la clase Juego con inicializacion a 0 de todos los atributos
    Juego() : tablero({ 0, 0 }), estadoInt(JUGANDO), fichaMeta({0, 0}) {}

    //Constructor de la clase Juego con inicializacion aleatoria de los atributos
    Juego(par fM, par d, int numMovimientos ) : tablero(d), estadoInt(JUGANDO), fichaMeta(fM) {
        generarMovimientosAleatorios(numMovimientos);
    } //Constructor

    //Getter del estado del juego
    Estado getEstado() { return estadoInt; }

    bool cargar(std::istream& entrada); //Funcion directora de la carga el tablero de una entrada x

    void posiblesMovimientos(Movimiento& mov) const;   //Se encarga de generar las posibles direcciones que puede tomar una ficha

    //Metodos de juego
    void jugar(Movimiento& mov); //Juega un movimiento
    void actualizarEstado();  //Actualiza el estado del juego
    void salvar(std::ostream& salida); //Salva el tablero en una salida x

    void mostrar(); //Funcion directora de la impresion del tablero

    bool enLimites(par f) const { return tablero.enLimites(f); }  //Devuelve true si y solo si esta en los limites del tablero
    bool fichaValida(par f) const { return (tablero.leer(f) == FICHA); }  //Devuelve true si y solo si la celda es una ficha
};