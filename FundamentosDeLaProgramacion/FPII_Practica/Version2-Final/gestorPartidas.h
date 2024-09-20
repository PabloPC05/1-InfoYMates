//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "lista.h"
#include "juego.h"
#include "memoryleaks.h"
using Usuario = std::string;

class GestorPartidas {
	public:
		GestorPartidas() : usuarioActivo(0) {} //Constructor de la clase GestorPartidas
		~GestorPartidas(); //Destructor de la clase GestorPartidas

		//Metodos relacionados con el archivo de gestion de los usuarios y sus partidas
		bool cargar(std::istream& entrada);	//Carga los datos de todas las partidas
		bool salvar(std::ostream& salida);	//Guarda los datos de todas las partidas
		void setNombreArchivo(std::string& a) { nombreArchivo = a; }	//Setter del nombre del archivo
		std::string getNombreArchivo() const { return nombreArchivo; }	//Getter del nombre del archivo

		//Metodos relacionados con la afluencia de usuarios
		void login(Usuario const& usuario);	//Hace login de un usuario
		void logout(); //Hace logout de un usuario

		//Metodos para escoger partida
		bool tienePartidas() const{ return usuarios[usuarioActivo]->partidas.size() > 0; }	//Devuelve true si y solo si el usuarioActivo tiene 1 o mas partidas empezadas
		void mostrarPartidasEmpezadas() const;	//Muestra las partidas empezadas del usuario activo
		size_t getNumPartidas()& { return usuarios[usuarioActivo]->partidas.size(); }	//Getter del numero de partidas del usuario activo

		//Inserta una partida generada aleatoriamente en la lista de partidas del usuario activo, con las caracteristicas introducidas por el usuario
		void insertarAleatoria(int movimientos, par fichaMeta, par dimension);	

		//Devuelve la partida en la posicion pos
		Juego& partida(const int& pos) { return *usuarios[usuarioActivo]->partidas[pos]; }

		//Elimina la partida en la posicion pos
		void eliminarPartida(const int& pos);

		//Elimina el usuario activo
		void eliminarUsuarioActivo();

	private:

		//Funcion que dado un usuario, busca su posicion en la lista de usuarios a traves de la busqueda binaria
		int buscarUsuario(Usuario const& usuario);	//Busca un usuario en la lista de usuarios

		//Getter y Setter del indice del usuario activo
		void setUsuarioActivo(int a) { usuarioActivo = a; }
		int getUsuarioActivo() const { return usuarioActivo; }

		//Redefinicion de tipos solo accesibles para la clase GestorPartidas
		struct UsuarioPartidas {
			Usuario user;	//Nombre del usuario
			Lista<Juego*> partidas;	//Lista de partidas
			bool operator< (UsuarioPartidas* const& a) const { return user < a->user; }	//Operador de comparacion
		};
		static const int NOLOGIN = -1;	//Constante que indica que no hay ningun usuario logeado


		//Atributos
		std::string nombreArchivo;	//Nombre del archivo que contiene la informacion sobre las partidas
		int usuarioActivo; //Posición del usuario que ha hecho login
		Lista<UsuarioPartidas*> usuarios; //Lista de usuarios
};