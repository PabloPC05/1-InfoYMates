//Pablo Pardo Cotos 
//FP2-DG25
//Version 2.0

#include "memoryleaks.h"
template <typename T>
class Lista {
	public:
		//Constructor de la lista
		Lista() : numElems(0), capacidad(1), datos(new T[1]){}

		//Destructor de la lista
		~Lista() { delete[] datos; }

		//Operadores []
		T& operator[](int i) { return datos[i]; } //Operador de acceso a un elemento de la lista
		T const& operator[](int i) const { return datos[i]; }

		//Funcion push_back, que inserta un elemento dado al final de la lista
		void push_back(T const& elem) {
			if (numElems == capacidad) { // hacer sitio si el vector est� lleno
				redimensionar(capacidad == 0 ? 1 : 2 * capacidad);
			}
			datos[numElems] = elem;
			++numElems;
		}

		//Funcion insert, que dada una posicion, se encarga de desplazar el resto de elementos e insertar el dado en la posicion indicada
		void insert(const int pos, const T& elem) {
			if (pos == numElems) {
				push_back(elem);
			}
			else {
				desplazarDerecha(pos);
				datos[pos] = elem;
			}
		}

		//Elimina el ultimo elemento de la lista
		void pop_back() {if (numElems > 0) numElems--;}

		//Devuelve el numero de elementos de la lista
		size_t size() const { return numElems;}

		//Dada una posicion de un elemento de la lista, elimina el elemento que esta en esa posicion
		//Da por hecho que la posicion de la lista es correcta y dentro de sus limites
		void erase(int pos) {
			for (int i = pos; i < numElems - 1; i++) {
				datos[i] = datos[i + 1];
			}
			numElems--;
		}

	private:
		//Atributos
		T* datos;	//Puntero que apunta a la primera poscion de la lista del array en memoria dinamica
		int numElems; 	//Numero de posiciones ocupadas en la lista
		int capacidad;	//Size actual de la lista

		//Dada un nuevo size de la lista, lo redimensiona para adaptarlo a dicha dimension
		void redimensionar(int nueva_cap) {
			T* viejo = datos;
			capacidad = nueva_cap;
			datos = new T[capacidad];
			for (int i = 0; i < numElems; ++i) {
				datos[i] = viejo[i];
			}
			delete[] viejo;
		}

		//Dada una posicion desplaza los elementos de la lista a la derecha
		void desplazarDerecha(const int& pos) {
			for (int i = numElems; i > pos; i--) {
				datos[i] = datos[i - 1];
			}
			numElems++;
		}
};