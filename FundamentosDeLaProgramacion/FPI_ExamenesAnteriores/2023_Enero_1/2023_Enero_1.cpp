#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <algorithm>
using namespace std;

const int NUM_CICLISTAS = 12;
const int NUM_ETAPAS = 20;
const int MAX_TIEMPO = 500;
const int CENTINELA = -1;

struct tCiclista {
    string equipo;
    string nombreCiclista;
    int dorsal;
    bool sigueEnLaCarrera;
    int etapasCompletadas;
    int tiempoTotal;
    int tiempoDeCadaEtapa[NUM_ETAPAS];
};

using tListaCiclistas = tCiclista[NUM_CICLISTAS];

struct tEtapa {
    int dorsal;
    int tiempo;
};

struct tListaEtapa {
    tEtapa lista[NUM_CICLISTAS];
    int cont;
};

void inicializarArrays(tListaCiclistas& ciclistas, tListaEtapa& Etapas){
    for (int i = 0; i < NUM_CICLISTAS; i++) {
        ciclistas[i].dorsal = 0; 
        ciclistas[i].sigueEnLaCarrera = false; 
        ciclistas[i].etapasCompletadas = 0; 
        ciclistas[i].tiempoTotal = 0; 
        for (int j = 0; j < NUM_ETAPAS; j++) {
            ciclistas[i].tiempoDeCadaEtapa[j] = 0;
        }
    }
    Etapas.cont = 0; 
    for (int i = 0; i < NUM_CICLISTAS; i++) {
        Etapas.lista[i].dorsal = 0;
        Etapas.lista[i].tiempo = 0;
    }
}

bool leerSeguimiento(string s, tCiclista& ciclista) {
    bool seguimiento = false;
    if (s == "IN") ciclista.sigueEnLaCarrera = true;
    if (s == "OUT") ciclista.sigueEnLaCarrera = false;
    return seguimiento;
    return seguimiento;
}

string escribirSeguimiento(tCiclista& ciclista) {
    string seguimiento;
    if (ciclista.sigueEnLaCarrera = 1) seguimiento = "IN";
    if (ciclista.sigueEnLaCarrera = 0) seguimiento = "OUT";
    return seguimiento;
}

// administra loas funciones que se encargan de leer el fichero
bool cargaCiclistas(tListaCiclistas& ciclistas) {
    ifstream archivo;
    string s, nombreArchivo;
    cout << "Introduce el nombre del archivo con la informacion de los ciclistas: ";
    cin >> nombreArchivo;
    cin.ignore();
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) return false;
    for (int i = 0; i < NUM_CICLISTAS; i++) {
        archivo >> ciclistas[i].equipo >> ciclistas[i].nombreCiclista >> ciclistas[i].dorsal >> s >> ciclistas[i].etapasCompletadas;
        leerSeguimiento(s, ciclistas[i]);
        for (int j = 0; j < ciclistas[i].etapasCompletadas; j++) {
            archivo >> ciclistas[i].tiempoDeCadaEtapa[j];
        }
    }
    archivo.close();
    return true;
}

bool cargaEtapa(tListaEtapa& ultimasEtapas) {
    ifstream archivo;
    string s, nombreArchivo;
    ultimasEtapas.cont = -1;
    cout << "Introduce el nombre del archivo con la informacion de las ultimas etapas: ";
    cin >> nombreArchivo;
    cin.ignore();
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) return false;
    ultimasEtapas.cont++;
    archivo >> ultimasEtapas.lista[ultimasEtapas.cont].dorsal >> ultimasEtapas.lista[ultimasEtapas.cont].tiempo;
    archivo >> ultimasEtapas.lista[ultimasEtapas.cont].dorsal >> ultimasEtapas.lista[ultimasEtapas.cont].tiempo;
    while (ultimasEtapas.lista[ultimasEtapas.cont].dorsal != CENTINELA) {
        ultimasEtapas.cont++;
        archivo >> ultimasEtapas.lista[ultimasEtapas.cont].dorsal >> ultimasEtapas.lista[ultimasEtapas.cont].tiempo;
    }
    archivo.close();
    return true;
}

tEtapa ganadorEtapa(tListaEtapa& ultimasEtapas) {
    int min = 10000, contador = 0;
    for (int i = 0; i < ultimasEtapas.cont; i++) {
        if (ultimasEtapas.lista[i].tiempo < min) {
            min = ultimasEtapas.lista[i].tiempo;
            contador = i;
        }
    }
    return ultimasEtapas.lista[contador];
}

void mostrarCiclista(tListaCiclistas& ciclistas) {
    cout << setw(55) << setfill('-') << '-' << '\n';
    cout << setw(10) << setfill(' ') << "EQUIPO";
    cout << setw(10) << setfill(' ') << "NOMBRE";
    cout << setw(10) << setfill(' ') << "DORSAL";
    cout << setw(10) << setfill(' ') << "IN/OUT";
    cout << setw(10) << setfill(' ') << "TOTAL";
    cout << setw(10) << setfill(' ') << "TIEMPOS";
    cout << '\n';
    for (int i = 0; i < NUM_CICLISTAS; i++) {
        cout << setw(10) << setfill(' ') << ciclistas[i].equipo;
        cout << setw(10) << setfill(' ') << ciclistas[i].nombreCiclista;
        cout << setw(10) << setfill(' ') << ciclistas[i].dorsal;
        cout << setw(10) << setfill(' ') << escribirSeguimiento(ciclistas[i]);
        cout << setw(10) << setfill(' ') << ciclistas[i].tiempoTotal;
        cout << setw(10) << setfill(' ');
        for (int j = 0; j < ciclistas[i].etapasCompletadas; j++) {
            cout << ciclistas[i].tiempoDeCadaEtapa[j] << " ";
        }
        cout << '\n';
    }
}

void sumarTiempoEtapas(tListaCiclistas& ciclistas) {
    int dorsal = 0;
    for (int i = 0; i < NUM_CICLISTAS; i++) {
         for (int j = 0; j < ciclistas[i].etapasCompletadas && ciclistas[i].sigueEnLaCarrera; j++) {
            ciclistas[i].tiempoTotal = ciclistas[i].tiempoTotal + ciclistas[i].tiempoDeCadaEtapa[j];
        }
    }
}

int buscaCiclistas(int d, tListaCiclistas& ciclistas) {
    int i = 0;
    while (ciclistas[i].dorsal != d && i < NUM_CICLISTAS) i++;
    if (i > NUM_CICLISTAS) i = -1;
    return i;
}

void actualizaCiclistas(tListaCiclistas& ciclistas, tListaEtapa& etapas) {
    for (int i = 0; i < etapas.cont; i++) {
        int posicionEnArray = buscaCiclistas(etapas.lista[i].dorsal, ciclistas);
        if (posicionEnArray != -1 && etapas.lista[i].tiempo <= MAX_TIEMPO) {
            ciclistas[posicionEnArray].tiempoTotal = ciclistas[posicionEnArray].tiempoTotal + etapas.lista[i].tiempo;
        }
        if (etapas.lista[i].tiempo > MAX_TIEMPO) ciclistas[posicionEnArray].sigueEnLaCarrera = false;
    }
}

void mostrarCiclistas(tListaEtapa& ultimasEtapas, tListaCiclistas& ciclistas) {
    tEtapa ganador = ganadorEtapa(ultimasEtapas);
    cout << "El ganador de la ultima etapa es el dorsal " << ganador.dorsal << " con un tiempo de " << ganador.tiempo << '\n';
    sumarTiempoEtapas(ciclistas);
    cout << "Clasificacion de la carrera antes de la ultima etapa\n";
    mostrarCiclista(ciclistas);
    actualizaCiclistas(ciclistas, ultimasEtapas);
    cout << "Clasificacion de la carrera despues de la ultima etapa\n";
    mostrarCiclista(ciclistas);
}

int main() {
    tListaCiclistas ciclistas;
    tListaEtapa ultimasEtapas;
    inicializarArrays(ciclistas, ultimasEtapas);
    if (cargaCiclistas(ciclistas) && cargaEtapa(ultimasEtapas)) {
        mostrarCiclistas(ultimasEtapas, ciclistas); 
    }
    else {
        cout << "No se encontraron los arhchivos\n";
    }
    return 0;
}