#include <iostream>
#include<fstream>
using namespace std; 
const int MAXMOV = 6; 
const int MAXTEC = 100;
const int MAXJUGADORES = 2; 

struct tSecuencia{
    string movBasics[MAXMOV];
    int numMovimientos; 
};
struct tTecnica{
    string nombre; 
    int causedDamage; 
    tSecuencia secuenciaMovs;
};

struct tListaTec{
    tTecnica tecnica[MAXTEC];
    int cont; 
};

struct tJugadores{
    string nombre; 
    int damage;
};

void cargar(ifstream& file, tSecuencia& secuencia){
    file >> secuencia.numMovimientos;
    for(int j = 0; j < secuencia.numMovimientos; j++){
        file >> secuencia.movBasics[j]; 
    }
}

bool cargar(string fileName, tListaTec& listaTec){
    ifstream archivo; 
    archivo.open(fileName);
    if(!archivo.is_open()) return false;
    archivo >> listaTec.cont; 
    for(int i = 0; i < listaTec.cont; i++){
        archivo >> listaTec.tecnica[i].nombre >> listaTec.tecnica[i].causedDamage;
        cargar(archivo, listaTec.tecnica[i].secuenciaMovs);
    }
    return true; 
}

bool compararSecuencias(const tSecuencia& tecnica, const tSecuencia& secuencia) {
	bool ok = true;
	int pos = 0;
	if (tecnica.numMovimientos != secuencia.numMovimientos)
		ok = false;
	else {
		while ((pos < tecnica.numMovimientos) && (tecnica.movBasics[pos] == secuencia.movBasics[pos]))
			pos++;
		if (pos < tecnica.numMovimientos)
			ok = false;
	}
	return ok;
}

int calcularImpacto(const tTecnica& tecnica, const tListaTec& listaTec){
    int damage = 0; 
    for(int i = 0; i < listaTec.cont; i++){
        if(compararSecuencias(tecnica.secuenciaMovs, listaTec.tecnica[i].secuenciaMovs)) damage = listaTec.tecnica[i].causedDamage;
    }
    return damage; 
}

void verificarMovimientos(tListaTec listaTec, tTecnica& movimientoJugador, tJugadores& jugador1, tJugadores& jugador2, string& jugadorAux, int& j){
    if(!compararSecuencias(listaTec.tecnica[j].secuenciaMovs, movimientoJugador.secuenciaMovs)) cout << "FALLO!\n";
    else{
        if(jugadorAux == jugador1.nombre) jugador2.damage = jugador2.damage + listaTec.tecnica[j].causedDamage;
        else jugador1.damage = jugador1.damage + listaTec.tecnica[j].causedDamage;
        cout << '+' << listaTec.tecnica[j].causedDamage << '\n';
    }
}

string leerJugador(ifstream& archivoPelea, tTecnica& movimientoJugador){
    string jugador;
    archivoPelea >> jugador >> movimientoJugador.nombre >> movimientoJugador.secuenciaMovs.numMovimientos;
    cout << jugador << ": ";
    for(int k = 0; movimientoJugador.secuenciaMovs.numMovimientos > k; k++){
        archivoPelea >> movimientoJugador.secuenciaMovs.movBasics[k];
        cout << movimientoJugador.secuenciaMovs.movBasics[k] << ' ';
    }
    return jugador; 
}

void leerArchivoLucha(string fileName, const tListaTec& listaTec){
    tJugadores jugador1, jugador2;
    tTecnica movimientoJugador; 
    ifstream archivoPelea;
    int numMovimientos = 0, contJugadores = 0, j = 0; 
    string jugadorAux;
    archivoPelea.open(fileName);
    archivoPelea >> numMovimientos;
    jugador1.nombre = leerJugador(archivoPelea, movimientoJugador);
    jugadorAux = jugador1.nombre;
    while(movimientoJugador.nombre != listaTec.tecnica[j].nombre) j++;
    verificarMovimientos(listaTec, movimientoJugador, jugador1, jugador2, jugadorAux, j);
    for(int i = 0; i < numMovimientos-1 && contJugadores <= 1; i++){
        jugadorAux = leerJugador(archivoPelea, movimientoJugador);
        if(jugadorAux != jugador1.nombre && contJugadores == 0){
            contJugadores++;
            jugador2.nombre = jugadorAux;
            j = 0; 
            while(movimientoJugador.nombre != listaTec.tecnica[j].nombre) j++;
            verificarMovimientos(listaTec, movimientoJugador, jugador1, jugador2, jugadorAux, j);   
        }
        else{
            j = 0; 
            while(movimientoJugador.nombre != listaTec.tecnica[j].nombre) j++;
            verificarMovimientos(listaTec, movimientoJugador, jugador1, jugador2, jugadorAux, j);
        }
    }
    if(contJugadores >= 2){
        cout << "Error: Hay un tercer jugador!\n";
    }
    else{
        cout << "Resultado: " << jugador1.nombre << " causa " << jugador2.damage << " puntos de daño - " << jugador2.nombre << " causa " << jugador1.damage << " puntos de daño\n";
        if(jugador1.damage < jugador2.damage) cout << jugador1.nombre << " gana!\n";
        if(jugador1.damage > jugador2.damage) cout << jugador2.nombre << " gana!\n";
        else cout << "Empate\n";
    }
}

void inicializar(tListaTec& listaTec){
    listaTec.cont = 0; 
    for(int i = 0; i < MAXTEC; i++){
        listaTec.tecnica[i].causedDamage = 0; 
        listaTec.tecnica[i].secuenciaMovs.numMovimientos = 0;
    }
}

int menu(){
    int chosenOption; 
    cout << "Luchador Callejero Dos`: The revenge!\n 1.- Mostrar todas las tecnicas\n 2.-Mostrar las tecnicas por impacto\n 3.- Lucha entre dos jugadores\n 0,- Salir\n Opcion: "; 
    cin >> chosenOption;
    return chosenOption; 
}

void mostrar(const tListaTec& listaTec, int impacto){
    for(int i = 0; i < listaTec.cont; i++){
        if(listaTec.tecnica[i].causedDamage == impacto){
            cout << listaTec.tecnica[i].nombre << " [" << listaTec.tecnica[i].causedDamage << "]  -> ";
            for(int j = 0; j < listaTec.tecnica[i].secuenciaMovs.numMovimientos; j++){
            cout << listaTec.tecnica[i].secuenciaMovs.movBasics[j] << ' ';
            }
            cout << '\n';
        }
    }
}

void mostrarMovimientos(const tListaTec& listaTec){
    cout << "Listado de tecnicas\n";
    for(int i = 0; i < listaTec.cont; i++){
        cout << listaTec.tecnica[i].nombre << " [" << listaTec.tecnica[i].causedDamage << "]  -> ";
        for(int j = 0; j < listaTec.tecnica[i].secuenciaMovs.numMovimientos; j++){
            cout << listaTec.tecnica[i].secuenciaMovs.movBasics[j] << ' ';
        }
        cout << '\n';
    }   
}

int main(){
    tListaTec listaTec;
    string fileName;
    int chosenOption = 0; 
    cout << "Introduce el nombre del archivo: "; 
    cin >> fileName;
    inicializar(listaTec);
    while(!cargar(fileName, listaTec)){
        cout << "Error al cargar el archivo, vuelve a intentarlo: ";
        cin >> fileName; 
    }
    chosenOption = menu();
    while(chosenOption != 0){ 
        if(chosenOption == 1) mostrarMovimientos(listaTec);
        else if(chosenOption == 2) {
            int impacto;
            cout << "Impacto: ";
            cin >> impacto;
            mostrar(listaTec, impacto);
        }
        else if(chosenOption == 3){
            cout << "Porfavor introduce el nombre del archivo con la lucha: ";
            cin >> fileName;
            leerArchivoLucha(fileName, listaTec);
        }
        chosenOption = menu();
        cout << '\n';
    } 
    return 0; 
}