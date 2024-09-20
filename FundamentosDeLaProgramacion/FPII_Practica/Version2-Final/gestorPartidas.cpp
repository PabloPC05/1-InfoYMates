//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "gestorPartidas.h"
#include "memoryleaks.h"
using namespace std;


//Funcion que elimina el usuario activo
void GestorPartidas::eliminarUsuarioActivo() {
	if (getNumPartidas() == 0) {
		delete usuarios[usuarioActivo];
		usuarios.erase(usuarioActivo);
	}
}

//Funcion que dada una posicion de la lista de partidas del usuario activo, elimina la partida en esa posicion
//En caso de que sea la unica partida del usuario, tambien elimina al propio usuario
void GestorPartidas::eliminarPartida(const int& pos) {
	delete usuarios[usuarioActivo]->partidas[pos];
	usuarios[usuarioActivo]->partidas.erase(pos);
}

//Destructor de la clase GestorPartidas
GestorPartidas::~GestorPartidas() {
	for (int i = 0; i < usuarios.size(); ++i) {
		for (int j = 0; j < usuarios[i]->partidas.size(); ++j) {
			delete usuarios[i]->partidas[j];
		}
		delete usuarios[i];
	}
}

//Carga los datos de todas las partidas de los usuarios y devuelve false si no se ha podido cargar alguna partida, interrumpiendo la carga total, para volverlo a intentar
bool GestorPartidas::cargar(istream& entrada) {
	if (entrada.fail()) return false;
	int numUsuarios, numPartidas;
	string ID;
	entrada >> numUsuarios;
	for (int i = 0; i < numUsuarios; i++) {
		UsuarioPartidas* user = new UsuarioPartidas;
		entrada >> ID;
		user->user = ID;
		entrada >> numPartidas;
		for (int i = 0; i < numPartidas; i++) {
			Juego* partida = new Juego;
			if (!partida->cargar(entrada)) {
				delete partida;
				return false;
			}
			user->partidas.push_back(partida);
		}
		usuarios.push_back(user);
	}
	return true;
}

//Dada una salida, guarda los datos de todas las partidas de los usuarios y deuvelve false si la salida falla
bool GestorPartidas::salvar(ostream& salida) {
	if(salida.fail()) return false;
	salida << usuarios.size() << endl;
	for (int i = 0; i < usuarios.size(); i++) {
		salida << usuarios[i]->user << '\n';
		salida << usuarios[i]->partidas.size() << '\n';
		for (int j = 0; j < usuarios[i]->partidas.size(); j++) {
			usuarios[i]->partidas[j]->salvar(salida);
		}
	}
	return true;
}

//Dado un Usuario(string), se encarga de buscar a dicho usuario en la lista de los mismos, y en caso de no encontrarlo, lo inserta
//Por ultimo establece su posicion como el usuario activo
void GestorPartidas::login(Usuario const& usuario) {
	int i = buscarUsuario(usuario);
	if (i == usuarios.size() || usuarios[i]->user != usuario) {
		UsuarioPartidas* user = new UsuarioPartidas;
		user->user = usuario;
		usuarios.insert(i, user);
	}
	setUsuarioActivo(i);
}

//Funcion que dado un usuario, busca su posicion en la lista de usuarios a traves de la busqueda binaria, 
// devolviendo la posicion en la que se encuentra o la posicion en la que deberia estar
int GestorPartidas::buscarUsuario(Usuario const& usuario){
	int iz = -1, dr = usuarios.size();
	// 0 <= iz < dr <= N
	// lista[0..iz] < e Y e <= lista[dr..N)
	while (iz + 1 < dr) { // hay elementos sin categorizar
		int mitad = (iz + dr) / 2;
		if (usuarios[mitad]->user == usuario) return mitad;
		else if (usuarios[mitad]->user < usuario) iz = mitad;
		else dr = mitad;
	}
	return dr;
}

//Hace logout de un usuario y en caso de que no le queden partidas, lo elimina
void GestorPartidas::logout() {
	if(usuarios[getUsuarioActivo()]-> partidas.size() == 0) {
		delete usuarios[getUsuarioActivo()];
		usuarios.erase(getUsuarioActivo());
	}
	setUsuarioActivo(NOLOGIN);
}

//Muestra las partidas empezadas del usuario activo segun el formato establecido
void GestorPartidas::mostrarPartidasEmpezadas() const {
	cout << endl;
	for (int i = 0; i < usuarios[getUsuarioActivo()]->partidas.size(); i++) {
		cout << i + 1 << "  ";
		for(int j = 0; j < 40; j++) cout << "-";
		cout << endl << endl;
		usuarios[getUsuarioActivo()]->partidas[i]->mostrar();
	}
}

//Inserta una partida generada aleatoriamente en la lista de partidas del usuario activo, con las caracteristicas introducidas por el usuario
void GestorPartidas::insertarAleatoria(int movimientos, par fichaMeta, par dimension) {
	usuarios[getUsuarioActivo()]->partidas.push_back(new Juego(fichaMeta, dimension, movimientos));
}	