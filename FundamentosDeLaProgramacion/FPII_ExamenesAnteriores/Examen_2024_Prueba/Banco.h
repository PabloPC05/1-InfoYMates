#include "Cliente.h"
#include <string>
#include <iostream>


class Banco {
public:
	Banco() : listaClientes(new Cliente* [1]), numClientes(0), capacidad(1)  {}
	~Banco(){
		delete[] listaClientes;
	}
	void redimensionar(size_t nuevaCap);
	void cargar_clientes();
	bool buscar_cliente(std::string NIF, int& pos);
	bool insertar_cliente(std::string NIF, int& pos);
	void eliminar_cliente(int pos) {
		delete listaClientes[pos];
		for (int i = pos; i < numClientes - 1; i++) {
			listaClientes[i] = listaClientes[i + 1];
		}
		numClientes--;
	}
	Cliente* cliente(int pos) { return listaClientes[pos]; }
	void mostrar_clientes() {
		for (int i = 0; i < numClientes; i++) {
			listaClientes[i]->mostrar_cliente();
		}
	}
	
private:
	Cliente** listaClientes;
	size_t numClientes;
	size_t capacidad;
	void desplazarDerecha(int pos);
};



