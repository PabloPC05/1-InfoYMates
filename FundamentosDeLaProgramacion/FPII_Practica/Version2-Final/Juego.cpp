//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "Juego.h"
using namespace std;

//FUNCIONES DE JUEGO ********************************************************************************

    /*
    *   Dado un movimiento, almacena una direccion si se cumple:
    *       a) Que la posicion a la que se quiera mover este dentro de los limites del tablero
    * 	    b) Que la ficha esta disponible segun la situacion del juego, esto es que,
    *       la posicion de la celda hacia la direccion que se podria mover
    */
    void Juego::posiblesMovimientos(Movimiento& mov) const {
        for (int i = 0; i < NUMDIR - 1 && tablero.leer(mov.getFicha()) == FICHA; i++) {
            if (tablero.enLimites(mov.getFicha() + 2 * dirToPar(direccion(i))) && disponibleParaMover(mov.getFicha(), direccion(i))) mov.setDireccion(direccion(i));
        }
    }

    //Dada una ficha, f, y una direccion, d, se encarga de ver que hacia dicha direccion exista en primer lugar, una ficha y en 2ºlugar una CELDA, con valor VACIO
    bool Juego::disponibleParaMover(par f, Direccion d) const {
        return tablero.leer(f + dirToPar(d)) == FICHA && tablero.leer(f + 2 * dirToPar(d)) == VACIA;
    }

    /*
    *   Dado un movimiento, la funcion se encarga de:
    *       1) Verificar que el numero de direcciones posibles sea mayor que 1
    *       2) En caso contrario, se establece la unica direccion como activa
    *       3) Por ultimo llama a la direccion EjecutaMovimientoSeleccionado() para que realice
    *       los cambios pertinentes al tablero y al vector de fichas del juego
    */
    void Juego::jugar(Movimiento& mov) {
        int aux = 1;
        if (mov.getNumDirs() > 1) { //Si hay mas de una direccion posible, se pide al jugador que seleccione una
            cout << "Selecciona una direccion: \n";
            for (int i = 0; i < mov.getNumDirs(); i++) {
                cout << i + 1 << " " << dirToString(mov.getDireccion(i)) << '\n';
            }
            cin >> aux;
        }
        //En caso que solo haya una direccion posible, se establece como activa
        mov.setDirActiva(mov.getDireccion(aux - 1)); //Establece la direccion activa del movimiento
        ejecutaMovimientoSeleccionado(mov);
    }

    //Dado un movimiento, la funcion se encarga de realizar los cambios pertinentes al tablero y al vector de fichas del juego
    void Juego::ejecutaMovimientoSeleccionado(Movimiento const& mov) {
        establecerFicha(mov.getFicha(), VACIA); //Modifica la CELDA de la ficha movida por VACIA y elimina la ficha del vector
        establecerFicha(mov.getFicha() + dirToPar(mov.getDirActiva()), VACIA); //Modifica la CELDA de la ficha que se ha comido por VACIA y elimina la ficha del vector
        establecerFicha(mov.getFicha() + 2 * dirToPar(mov.getDirActiva()), FICHA); //Modifica la CELDA de la ficha que se ha movido por FICHA y la añade al vector
    }

    //Esta funcion se encarga de actualizar el estado del juego si se cumplen las condiciones establecidas. 
    void Juego::actualizarEstado() {
        Estado movPosibles = hayMovimientos();  //Comprueba si hay movimientos posibles
        Estado ganador = hayGanador();  //Comprueba si hay ganador
        if (movPosibles == JUGANDO && ganador == JUGANDO) setEstado(JUGANDO);   //Si ambas devuelven JUGANDO, el estado es JUGANDO
        else if (movPosibles == BLOQUEO && ganador == GANADOR) setEstado(GANADOR);  //Si no hay movimientos posibles y hay ganador, el estado es GANADOR
        else setEstado(BLOQUEO);   //Si no hay movimientos posibles y no hay ganador, el estado es BLOQUEO
    }


//FUNCION DE CARGA DE PARTIDA ********************************************************************************

    //Carga el tablero de juego desde una entrada x (archivo o consola) con un formato determinado
    bool Juego::cargar(istream& entrada) {
        int aux;
        entrada >> aux; //Se introduce el numero de filas del tabelro
        tablero.setFilas(aux);  //Se establecen
        entrada >> aux; //Se introduce el numero de columnas del tablero
        tablero.setCols(aux);   //Se establecen
        for (int i = 0; i < tablero.getFilas(); i++) {
            for (int j = 0; j < tablero.getColumnas(); j++) {
                entrada >> aux; //Se lee el valor de la celda
                tablero.escribir(i, j, static_cast<Celda>(aux)); //Se escribe el valor de la celda en el tablero
                if (tablero.leer(i, j) == FICHA) fichas.push_back({ i,j }); //Si la celda es una FICHA, se añade al vector de fichas
            }
        }
        entrada >> aux; //Se introduce la fila de la ficha de meta
        setFilaMeta(aux);   //Se establece
        entrada >> aux; //Se introduce la columna de la ficha de meta
        setColumnaMeta(aux);	//Se establece
        return true;
    }


///FUNCION DE SALVADO DE LA PARTIDA ********************************************************************************

    //Salva el tablero de un juego en una salida x (archivo o consola) con el formato determinado
    void Juego::salvar(ostream& salida) {
        salida << tablero.getFilas() << ' ' << tablero.getColumnas() << '\n';
        for (int i = 0; i < tablero.getFilas(); i++) {
            for (int j = 0; j < tablero.getColumnas(); j++) {
                salida << int(tablero.leer(i, j)) << ' ';
            }
            salida << '\n';
        }
        salida << getFichaMeta() << '\n';
    }


//FUNCIONES DE GENERACION DE TABLERO ********************************************************************************


    /*
    *   Dado el numero de movimientos, esta funcion se encarga de:
    *       1) Introducir la ficha de meta en el vector de fichas, pues es la unica por el momento
    *       2) Abrir el archivo solucion.txt
    *       3) Realizar en bucle la generacion de fichas, con el siguiente funcionamiento:
    *           a) Genera un indice aleatorio del vector de fichas
    *           b) De esa ficha se genera una posible direccion
    *           c) Si la direccion es indeterminada, no se contabiliza el movimiento
    *           d) En caso contrario, se establece el movimiento generado en el tablero y en el vector de fichas
    *       4) Escribe el tablero en el archivo solucion.txt en el mismo formato que el de cargar()
    */
    void Juego::generarMovimientosAleatorios(int N) {
        fichas.push_back({ getFilaMeta(), getColumnaMeta() }); //Introduce como primera ficha la de meta
        int i = 0;
        solucion.open("solucion.txt");  //Abre el archivo solucion.txt
        do {
            int j = rand() % fichas.size(); //Genera un indice aleatorio del vector de fichas
            Direccion d = generarDireccion(fichas.at(j)); //Genera una direccion aleatoria para la ficha seleccionada
            if (d == INDETERMINADA) continue;   //Si la direccion generada es indeterminada, se salta el resto del bucle
            establecerMovimientoGenerado(d, fichas.at(j)); //Establece el movimiento generado
            i++;
            //mostrar();    //Para una posible depuracion para ver si funciona correctamente
        } while (i < N);
        solucion.flush();
        solucion.close();
    }

    /*
    *   Dada una ficha esta funcion se encarga de:
    *       1) Generar un vector en el que se almacenan las direcciones posibles que puede tomar la ficha
    *       2) Comprueba que las fichas que se generaran no esten fuera de los limites del tablero
    *       y que no se hayan establecido previamente movimientos en el tablero que imposibiliten el el juego
    *       3) Se escogen un indice aleatorio del vector de direcciones posibles para devolver una de las posibles direccion de forma aleatoria.
    *       4) En caso de que el vector sea vacio, se devuelve INDETERMINADA
    */
    Direccion Juego::generarDireccion(par ficha) {
        vector <Direccion> dirDisponibles;
        for (int i = 0; i < NUMDIR; i++) {
            //Si la ficha + 2 * dirToPar(direccion(i) esta dentro de los limites del tablero y es posible generar un movimiento, añade la direccion al vector
            if (tablero.enLimites(ficha + 2 * dirToPar(direccion(i))) && disponibleGenerar(ficha, direccion(i))) dirDisponibles.push_back(direccion(i));
        }
        if (dirDisponibles.size() == 0) return direccion(4);    //Si el vector es vacio, devuelve INDETERMINADA
        int i = rand() % dirDisponibles.size();     //Genera un indice aleatorio del vector de direcciones posibles
        return dirDisponibles.at(i);    //Devuelve la direccion aleatoria
    }

    //Se encarga de ver aquellas condiciones favorables en las que se podria generar un movimiento
    bool Juego::disponibleGenerar(par ficha, Direccion d) const {
        return tablero.leer(ficha + dirToPar(d)) != FICHA && tablero.leer(ficha + 2 * dirToPar(d)) != FICHA;
    }

    //Dada una direccion y una ficha, la funcion se encarga de establecer el movimiento generado en el tablero y en el vector de fichas
    void Juego::establecerMovimientoGenerado(Direccion d, par ficha) {
        establecerFicha(ficha + dirToPar(d), FICHA);    //Escribe la futura ficha que sera movida por FICHA
        establecerFicha(ficha + 2 * dirToPar(d), FICHA);  //Escribe en la CELDA de la futura ficha que se movera para comer por FUCHA
        establecerFicha(ficha, VACIA);  //Escribe en la CELDA donde se situara la ficha despues de comer a la otra, por VACIA
        //En dichas llamadas tambien se modifican el vector de fichas
        solucion << (1 + (ficha + 2 * dirToPar(d))) << ' ' << dirToStringSol(d) << '\n'; //Escribe el movimiento en el archivo solucion
    }


//FUNCIONES DE MOSTRAR EL JUEGO ********************************************************************************

    void Juego::mostrar() {
        cout << RESET;
        // borde superior
        pinta_cabecera();
        pinta_linea(char(218), char(194), char(191));
        // para cada fila
        for (int fil = 0; fil < tablero.getFilas(); fil++) {
            // primera linea
            pinta_borde_celda(fil);
            // segunda linea, con la meta posiblemente
            pinta_centro_celda(fil);
            // tercera linea
            pinta_borde_celda(fil);
            // separacion entre filas
            if (fil < tablero.getFilas() - 1) {
                pinta_linea(char(195), char(197), char(180));
            }
            else {
                pinta_linea(char(192), char(193), char(217));
            }
        }
    }

    void Juego::color_fondo(int color) {
        if (color == DEFAULT_COLOR)
            cout << RESET;
        else if (color == NULA)
            cout << COLORNULA;
        else if (color == FICHA)
            cout << COLORFICHA;
        else // color == VACIA
            cout << COLORVACIA;
    }

    void Juego::pinta_cabecera() {
        cout << setw(2) << "    "; // margen inicial
        cout << setw(5) << 1;
        for (int i = 2; i <= tablero.getColumnas(); i++) {
            cout << setw(7) << i;
        }
        cout << endl;
    }

    void Juego::pinta_linea(char esquinaIzda, char cruce, char esquinaDer) {
        cout << "    "; // margen inicial
        cout << esquinaIzda;
        for (int i = 0; i < tablero.getColumnas() - 1; i++) {
            cout << string(6, char(196)) << cruce;
        }
        cout << string(6, char(196)) << esquinaDer << endl;
    }

    void Juego::pinta_borde_celda(int fila) {
        cout << "    "; // margen inicial
        for (int k = 0; k < tablero.getColumnas(); k++) { // cada columna
            cout << char(179);
            color_fondo(tablero.leer(fila, k));
            cout << "      ";
            color_fondo(DEFAULT_COLOR);
        }
        cout << char(179) << endl; // lateral derecho
    }

    void Juego::pinta_centro_celda(int fila) {
        cout << "  " << setw(2) << fila + 1; // margen inicial
        for (int k = 0; k < tablero.getColumnas(); k++) { // cada columna
            cout << char(179);
            // el color de fondo depende del contenido
            color_fondo(tablero.leer(fila, k));

            if (fila == fichaMeta.first && k == fichaMeta.second) { // meta
                cout << COLORMETA;
                cout << "  " << char(219) << char(219) << "  ";
            }
            else {
                cout << "      ";
            }
            color_fondo(DEFAULT_COLOR);
        }
        cout << char(179) << endl; // lateral derecho
    }


//FUNCIONES DE COMPROBACION DE ESTADO ********************************************************************************

    //Devuelve GANADOR si queda una sola ficha en el vector y es la ficha de meta.
    //En caso contrario, devuelve JUGANDO
    Estado Juego::hayGanador() const {
        if (fichas.size() == 1 && fichas.at(0) == fichaMeta) return GANADOR;
        else return JUGANDO;
    }

    /*
    *   La funcion se encarga de comprobar si hay movimientos posibles, siguiendo el funcionamiento:
    *       a) Se genera un movimiento con una ficha del vector de fichas
    *       b) Se llama a funcion posiblesMovimientos() para ver si puede haber movimientos con esa ficha
    *       c) Se repite el proceso hasta que se termine el vecto de fichas o se encuentre un movimiento posible
    *       d) Si no se encuentra ningun movimiento posible, devuelve BLOQUEO
    *       e) En caso contrario, devuelve JUGANDO
    */
    Estado Juego::hayMovimientos() const {
        int i = 0;
        Movimiento mov;
        do {
            mov.setFicha(fichas.at(i));
            posiblesMovimientos(mov);
            i++;
        } while (i < fichas.size() && mov.getNumDirs() == 0);
        if (mov.getNumDirs() == 0) return BLOQUEO;
        return JUGANDO;
    }

    //Dada una ficha, f, la funcion se encarga de devolver el indice de dicha ficha en el vector de fichas
    int Juego::indiceFicha(par f) const {
        int i = 0;
        while (i < fichas.size() && fichas.at(i) != f) i++;
        return i;
    }


//FUNCIONES DE ESTABLECIMIENTO DE CAMBIOS EN EL JUEGO ********************************************************************************

    //Funcion general que se encarga de establecer las fichas en el tablero y en el vector de fichas
    void Juego::establecerFicha(par ficha, Celda cel) {
        tablero.escribir(ficha, cel);  //Escribe el nuevo valor de la celda en el tablero 
        if (cel == FICHA) fichas.push_back(ficha);  //Añade la ficha al vector de fichas
        else if (cel == VACIA) fichas.erase(fichas.begin() + indiceFicha(ficha));  //Borra la ficha del vector de fichas
    }