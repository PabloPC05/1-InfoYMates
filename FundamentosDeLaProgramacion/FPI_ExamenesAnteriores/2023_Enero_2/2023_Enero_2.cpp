#include <iostream>
#include <fstream>
using namespace std;
const int CENTINELAi = -1;
const string CENTINELAs = "XX";
const int MAXASIENTOSPORVUELO = 100;
const int MAXASIENTOSCOMPANY = 1000;
const int MAXVUELOS = 10;
struct tAsientos {
    string NIF[MAXASIENTOSPORVUELO];
};
struct tVuelo {
    string identificador;
    tAsientos asientos;
    int cont; // numero de pasajeros de un vuelo
};
struct tListaVuelos {
    tVuelo vuelo[MAXVUELOS];
    int cont; // numero de vuelos
};
struct tListaPasajeros {
    int cont;   // numero de pasajeros de la compania completa
    string NIF[MAXASIENTOSCOMPANY];
};

bool cargaInfoVuelos(tListaVuelos& vuelos) {
    ifstream archivo;
    string nombreArchivo;
    vuelos.cont = 0;
    int indice = 0;
    cout << "Introduce el nombre del archivo: ";
    cin >> nombreArchivo;
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) return false;
    archivo >> vuelos.vuelo[vuelos.cont].identificador >> indice;
    while (indice != CENTINELAi) {
        archivo >> vuelos.vuelo[vuelos.cont].asientos.NIF[indice] >> indice;
        vuelos.vuelo[vuelos.cont].cont++;
    }
    while (vuelos.vuelo[vuelos.cont].identificador != CENTINELAs) {
        vuelos.cont++;
        archivo >> vuelos.vuelo[vuelos.cont].identificador >> indice;
        while (indice != CENTINELAi) {
            archivo >> vuelos.vuelo[vuelos.cont].asientos.NIF[indice] >> indice;
            vuelos.vuelo[vuelos.cont].cont++;
        }
    }
    return true;
}

void muestraListaVuelos(tListaVuelos& vuelos) {
    cout << "INFORMACION ACTUAL DE LOS VUELOS (" << vuelos.cont << " VUELOS)\n";
    for (int i = 0; i < vuelos.cont; i++) {
        cout << "Vuelo: " << vuelos.vuelo[i].identificador << "\n asientos reservados:\n";
        for (int j = 0; j < MAXASIENTOSPORVUELO; j++) {
            if (vuelos.vuelo[i].asientos.NIF[j] != "") cout << "\tnumero: " << j << " nif: " << vuelos.vuelo[i].asientos.NIF[j] << '\n';
        }
    }
}

void muestraListaPasajeros(const tListaPasajeros& pasajerosTotales) {
    cout << "EL NUMERO DE PASAJEROS ES: " << pasajerosTotales.cont<<'\n';
    for (int i = 0; i < pasajerosTotales.cont; i++) {
        cout << "\tnif: " << pasajerosTotales.NIF[i]<<'\n';
    }
}


int buscaVuelo(const tListaVuelos& vuelos, string identificador) {
    int i = 0;
    while (vuelos.vuelo[i].identificador != identificador && i < vuelos.cont) i++;
    if (vuelos.vuelo[i].identificador != identificador) i = -1;
    return i;
}


bool reservaAsiento(tAsientos& asientos, string& NIF, int& nA) {
    bool returnValue = false;
    if (asientos.NIF[nA] == "") {
        returnValue = true;
        asientos.NIF[nA] = NIF;
    }
    else {
        int i = 1;
        while (asientos.NIF[i] != "" && i < MAXASIENTOSPORVUELO) i++;
        returnValue = asientos.NIF[i] == "";
        if (returnValue) {
            nA = i;
            asientos.NIF[nA] = NIF;
        }
    }
    return returnValue;
}

bool pertenece(const tListaPasajeros& pasajerosTotales, string NIF) {
    int i = 0;
    while (pasajerosTotales.NIF[i] != NIF && i < pasajerosTotales.cont) i++;
    return pasajerosTotales.NIF[i] == NIF;
}

tListaPasajeros creaListaPasajeros(const tListaVuelos& vuelos) {
    tListaPasajeros pasajerosTotales;
    pasajerosTotales.cont = 0;
    for (int i = 0; i < vuelos.cont; i++) {
        for (int j = 0; j < MAXASIENTOSPORVUELO; j++) {
            if (vuelos.vuelo[i].asientos.NIF[j] != "") {
                pasajerosTotales.NIF[pasajerosTotales.cont] = vuelos.vuelo[i].asientos.NIF[j];
                pasajerosTotales.cont++;
            }
        }
    }
    return pasajerosTotales;
}

bool hacerReserva(tListaVuelos& vuelos, tListaPasajeros& pasajerosTotales) {
    string nif;
    int i = 0;
    bool returnValue = true;
    cout << "Introduce su NIF, porfavor: ";
    cin >> nif;
    if (pertenece(pasajerosTotales, nif)) {
        returnValue = false;
        cout << "Lo siento ya ha realizado previamente una reserva\n";
    }
    else {
        string identificador;
        cout << "Introduzca el numero del vuelo del que desea hacer la reserva: ";
        cin >> identificador;
        int indiceVuelo = buscaVuelo(vuelos, identificador);
        if (indiceVuelo == -1) {
            returnValue = false;
            cout << "Lo lamentamos, pero ese identificador no existe\n"
        }
        else {
            int numeroAsiento;
            cout << "Introduzca el numero de asiento del que desea hacer la reserva: ";
            cin >> numeroAsiento;
            if (!reservaAsiento(vuelos.vuelo[indiceVuelo].asientos, nif, numeroAsiento)) cout << "Lo lamentamos pero el vuelo introducido esta completo\n";
            else {
                cout << "Reserva realizada en el vuelo " << vuelos.vuelo[indiceVuelo].identificador << " Asiento: " << numeroAsiento<<'\n';
                pasajerosTotales.NIF[pasajerosTotales.cont + 1] = nif; 
            }
        }
    }
    return returnValue;
}


int main() {
    tListaVuelos vuelos;
    tListaPasajeros pasajerosTotales;
    while (!cargaInfoVuelos(vuelos)) cout << "introduzca, nuevamente el nombre del archivo: ";
    muestraListaVuelos(vuelos);
    pasajerosTotales = creaListaPasajeros(vuelos);
    muestraListaPasajeros(pasajerosTotales);
    if (hacerReserva(vuelos, pasajerosTotales)) {
        muestraListaVuelos(vuelos);
        muestraListaPasajeros(pasajerosTotales);
    }
    return 0;
}