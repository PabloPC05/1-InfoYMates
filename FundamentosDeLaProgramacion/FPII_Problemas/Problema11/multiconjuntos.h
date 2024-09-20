#include <iostream>
#include <vector>
using tResultado = std::vector<char>;
class multiconjunto {
    private: 
        //atributos
        struct elem{
            //Atribuos
            int valor;  //valor del elemento
            int multiplicidad; //multiplicidad del mismo en el multiconjunto
            
            elem(int v = 0, int m = 0) {valor = v; multiplicidad = m;} //Constructor de cada elemento
            bool operator==(const elem e) const{return e.valor == valor;}

            //Metodos de escrirtura de la estructura elemento
            void setMultiplicidad(int m) {multiplicidad = m;} //Modifica la multiplicidad de un elemento
            void setValor(int v) {valor = v;} //Modifica el valor de un elemento
     
            //Metodos de lectura de la estructura elemento
            int getMultiplicidad() const {return multiplicidad;} //Devuelve la multiplicidad de un elemento
            int getValor() const {return valor;} //Devuelve el valor de un elemento
        };
        std::vector<int> secuencia;
        std::vector<elem> elems;
        int num_elems; //Numero de elementos distintos

    public:
        multiconjunto(int n = 0) {num_elems = n;} //Constructor del multiconjunto con n elementos

        //Metodos de lectura
        int getNumElems() const {return num_elems;} //Devuelve el numero de elementos distintos
        int getSecuencia(int i) const {return secuencia.at(i);} //Devuelve el valor de la secuencia en la posicion i
        int getSecuenciaSize() const {return secuencia.size();} //Devuelve el tamaño de la secuencia
        int getValorEnSecuencia(int i) const {return secuencia.at(i);} //Devuelve el valor de la secuencia en la posicion i
        int getElem(int i) const {return elems.at(i).getValor();} //Devuelve el valor del elemento en la posicion i

        //Metodos de escritura
        void setNumElems(int n) {num_elems = n;} //Modifica el numero de elementos distintos
        void setValorEnSecuencia(int v) {secuencia.push_back(v);} //Modifica el valor de la secuencia en la posicion i

        //Metodos generales
        void insertar(int elem); //Inserta un elemento en el multiconjunto
        void eliminar(int elem); //Elimina un elemento del multiconjunto, si esta varias veces, lo elimina una vez
        int pertenece(int elem); //Devuelve si un elemento pertenece al multiconjunto

        //Metodos de comparacion
        void comparar(const multiconjunto& mIntento, tResultado& r);
        void comparar1a1(const multiconjunto& mIntento, tResultado& r);
        void compararTodosConTodos (const multiconjunto& mIntento, tResultado& r);

};

    void inicializarResultado(tResultado& r, int n); //Inicializa el vector de resultados con n elementos
    std::ostream& operator<<(std::ostream& os, const tResultado& r);