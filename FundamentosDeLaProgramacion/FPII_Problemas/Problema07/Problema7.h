#include <iostream>
#include <vector>
const int CENTINELA = 0;
class matriz{
    public:
        //Metodos de escritura
        void setFilas(int n){filas = n;}
        void setCols(int m){cols = m;}
        void setValor(int j, int valor){matriz.at(j).push_back(valor);}
        void imprimirMatriz();

        //Metodos de lectura
        int getValor(int i, int j){return matriz.at(i).at(j);}
        int getFilas(){return filas;}
        int getCols(){return cols;}
        void lectura(std::istream &entrada);

        //Metodos de opcion
        void intercambiarFilas();
        void intercambiarColumnas();
        void rellenarCruz();
        void rotarFila();
        void rotarCol();
        
    private:
        //Atributos
        std::vector<std::vector<int>> matriz;
        int filas, cols;
};
std::istream& operator>>(std::istream& is, matriz& m);
std::ostream& operator<<(std::ostream& os, matriz& m);
