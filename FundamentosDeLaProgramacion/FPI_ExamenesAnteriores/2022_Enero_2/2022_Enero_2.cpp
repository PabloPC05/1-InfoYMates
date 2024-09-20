#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 
const int MAX_JUGUETES = 10; 
const int MAX_CARTAS = 10;
const int MAX_PEDIDOS = 3;
const string CENTINELA = "XXX"; 
struct tJuguetes{
    string nombre; 
    double peso; 
    int numDisponible; 
};
struct tListaJuguetes{
    tJuguetes juguete[MAX_JUGUETES];
    int cont;
};
struct tRemitente{
    string nombre;
    string ciudad;
};
struct tCarta{
    tRemitente remitente;
    string juguetes[MAX_PEDIDOS];
    bool cargado; 
};
struct tListaCartas{
    tCarta carta[MAX_CARTAS];
    int cont;
};
struct tCiudad{
    string nombre; 
    int pesoDelTrineo;
};
struct tArrayCiudades{ 
    tCiudad ciudad[MAX_CARTAS];
    int cont; 
};


bool cargarJuguetes(tListaJuguetes& juguetes){
    ifstream archivo; 
    string fileName; 
    cout << "Introduce el nombre del archivo: ";
    cin >> fileName; 
    archivo.open(fileName);
    if(!archivo.is_open()) return false;
    juguetes.cont = 0;
    while(!archivo.eof()){
        archivo >> juguetes.juguete[juguetes.cont].nombre >> juguetes.juguete[juguetes.cont].peso >> juguetes.juguete[juguetes.cont].numDisponible;
        juguetes.cont++;
    }
    return true; 
}

bool comprobarPedido(tListaJuguetes& juguetes, tCarta& carta){
    bool returnValue = true; 
    int contJuguetesDisponibles = 0, i = 0; 
    for(int i = 0; i < juguetes.cont; i++){
        for(int j = 0; j < MAX_PEDIDOS; j++){
            if(juguetes.juguete[i].nombre == carta.juguetes[j] && juguetes.juguete[i].numDisponible > 0) contJuguetesDisponibles++;
        }
    }
    if(contJuguetesDisponibles != 3) returnValue = false; 
    return returnValue; 
}


int buscarJuguete(tListaJuguetes& juguetes, string& n){
    int i = 0; 
    while(juguetes.juguete[i].nombre != n && i < juguetes.cont) i++;
    return i;
}


int trineoDestino(string& ciudad, tListaJuguetes& juguetes, tListaCartas& cartas, tArrayCiudades& ciudades){ //queda por añadir que los pedidos que no se hayan enviado se almacenene en en la lista ciudades
    double pesoJuguetes = 0;
    for(int i = 0; i < cartas.cont; i++){
        if(cartas.carta[i].remitente.ciudad == ciudad && comprobarPedido(juguetes, cartas.carta[i])){
            cout << "Carta " << cartas.carta[i].remitente.nombre << ' ' << "Juguetes : ";
            for(int j = 0; j < MAX_PEDIDOS; j++){
                int k = buscarJuguete(juguetes, cartas.carta[i].juguetes[j]);
                cout << juguetes.juguete[k].nombre<<' ';
                juguetes.juguete[k].numDisponible--;
                pesoJuguetes = pesoJuguetes +  juguetes.juguete[k].peso;
            }
            cout << '\n';
            cartas.carta[i].cargado = 1;
        }
        else{
            cartas.carta[i].cargado = 0;
        }
    }
    return pesoJuguetes; 
}

void cargarTrineos(tListaCartas& cartas, tListaJuguetes& juguetes, tArrayCiudades& ciudades, int& i){
    int j = 0;
    string ciudadNoCargada;
    bool encontrado = cartas.carta[i].remitente.ciudad == ciudades.ciudad[j].nombre;
    for(j = 0; j < ciudades.cont && !encontrado; j++){
        if(cartas.carta[i].remitente.ciudad == ciudades.ciudad[j].nombre) encontrado = 1;
     }
    if(encontrado == 0) { ciudadNoCargada = cartas.carta[i].remitente.ciudad;
        cout << "Cargando el trineo con destino " << ciudadNoCargada << '\n';
        ciudades.ciudad[ciudades.cont].pesoDelTrineo = trineoDestino(ciudadNoCargada, juguetes, cartas, ciudades);
        ciudades.ciudad[ciudades.cont].nombre = ciudadNoCargada;
        cout << "Peso del trineo con destino " << ciudadNoCargada << " : " << ciudades.ciudad[ciudades.cont].pesoDelTrineo << '\n';
        ciudades.cont++;
    }
}

void listarJuguetes(const tListaJuguetes& juguetes){
    cout << "Bienvenido a la fabrica de juguetes de Papa Noel\n"; 
    cout << setw(48) << setfill('-') << '-' << '\n'<<"Listado de los juguetes que hay en la fabrica\n"; 
    cout << setw(10) << setfill(' ') << "Nombre" << setw(10) << setfill(' ') << "Peso" << setw(10) << setfill(' ') << "Cant.\n";
    for(int i = 0; i < juguetes.cont; i++){
        cout << setw(10) << setfill(' ') << juguetes.juguete[i].nombre << setw(10) << setfill(' ') << juguetes.juguete[i].peso << setw(10) << setfill(' ') << juguetes.juguete[i].numDisponible << '\n'; 
    }
}

bool cargaCartas(tListaCartas& cartas){
    ifstream archivo; 
    string fileName; 
    cout << "Introduce el archivo de las cartas: ";
    cin >> fileName; 
    archivo.open(fileName);
    if(!archivo.is_open()) return false;
    cartas.cont = 0; 
    archivo >> cartas.carta[cartas.cont].remitente.nombre;
    while(cartas.carta[cartas.cont].remitente.nombre != CENTINELA){
        archivo >> cartas.carta[cartas.cont].remitente.ciudad; 
        for(int i = 0; i < MAX_PEDIDOS; i++) archivo >> cartas.carta[cartas.cont].juguetes[i];
        cartas.cont++;
        archivo >> cartas.carta[cartas.cont].remitente.nombre;
    }
    return true;
}

void inicializar(tListaCartas& cartas, tListaJuguetes& juguetes, tArrayCiudades& ciudades){
    cartas.cont = 0;
    juguetes.cont = 0; 
    ciudades.cont = 0;  
    for(int i = 0; i < MAX_PEDIDOS; i++){
        juguetes.juguete[i].numDisponible = 0; 
        juguetes.juguete[i].peso = 0.0; 
    }
    for(int i = 0; i < MAX_CARTAS; i++){
        ciudades.ciudad[i].pesoDelTrineo = 0; 
    }
}

int main(){
    tListaCartas cartas;
    tListaJuguetes juguetes;
    tArrayCiudades ciudades;
    inicializar(cartas, juguetes, ciudades);
    while(!cargaCartas(cartas)) cout << "Error. Vuelve a intentarlo\n";
    while(!cargarJuguetes(juguetes)) cout << "Error. Vuelve a intentarlo\n";
    listarJuguetes(juguetes);
    cout << "Comenzando a cargar los trineos...\n\n";
    for(int i = 0; i < cartas.cont; i++){
        cargarTrineos(cartas, juguetes, ciudades, i); 
    }
    return 0; 
}