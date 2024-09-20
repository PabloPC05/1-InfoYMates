#include <iostream>
#include <vector>
using namespace std;

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

void matriz::lectura(istream &entrada){
    int n, m;        
    entrada >> n >> m;
    setFilas(n);
    setCols(m);
    matriz.resize(n);
    for(int i = 0; i < n; i++){
        matriz.at(i).resize(m);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matriz.at(i).at(j);
        }
    }
}

std::istream& operator>>(std::istream& is, matriz& m){
    m.lectura(is);
    return is;
}

void matriz::intercambiarFilas(){
    int fila1, fila2;
    cin >> fila1 >> fila2;
    for(int i = 0; i < getCols(); i++){
        int aux = matriz.at(fila1-1).at(i);
        matriz.at(fila1-1).at(i) = matriz.at(fila2-1).at(i);
        matriz.at(fila2-1).at(i) = aux;
    }
}

void matriz::intercambiarColumnas(){
    int col1, col2;
    cin >> col1 >> col2;
    for(int i = 0; i < getFilas(); i++){
        int aux = matriz.at(i).at(col1-1);
        matriz.at(i).at(col1-1) = matriz.at(i).at(col2-1);
        matriz.at(i).at(col2-1) = aux;
    }
}

void matriz::rellenarCruz(){
    int fila, col, dig;
    cin >> fila >> col >> dig;
    matriz.at(fila-1).at(col-1) = dig;
    int i = fila-1, j = col-1; 
    while(i < getFilas() && j < getCols()){
        matriz.at(i).at(j) = dig;
        i++;
        j++;
    }
    i = fila-1, j = col-1; 
    while(i >= 0 && j >= 0){
        matriz.at(i).at(j) = dig;
        i--;
        j--;
    }
    i = fila-1, j = col-1; 
    while(i >= 0 && j < getCols()){
        matriz.at(i).at(j) = dig;
        i--;
        j++;
    }
    i = fila-1, j = col-1; 
    while(i < getFilas() && j >= 0){
        matriz.at(i).at(j) = dig;
        i++;
        j--;
    }
}

void matriz::rotarCol(){
    int col; 
    cin >> col;
    if(col > 0){    // rotar hacia bajo
        int aux = matriz.at(getFilas()-1).at(col-1);
        for(int i = getFilas()-1; i > 0; i--){
            matriz.at(i).at(col-1) = matriz.at(i-1).at(col-1);
        }
        matriz.at(0).at(col-1) = aux;
    }
    else{
        col = -col;
        int aux = matriz.at(0).at(col-1);
        for(int i = 0; i < getFilas()-1; i++){
            matriz.at(i).at(col-1) = matriz.at(i+1).at(col-1);
        }  
        matriz.at(getFilas()-1).at(col-1) = aux; 
    }
}

void matriz::rotarFila(){
    int fila;
    cin >> fila;
    if(fila > 0){ //rota hacia la derecha  
        int aux1 = matriz.at(fila-1).at(getCols()-1);
        for(int j = getCols()-1; j > 0; j--){
            matriz.at(fila-1).at(j) = matriz.at(fila-1).at(j-1);
        }
        matriz.at(fila-1).at(0) = aux1;
    }
    else{
        fila = -fila;
        int aux1 = matriz.at(fila-1).at(0);
        for(int j = 0; j < getCols()-1; j++){
            matriz.at(fila-1).at(j) = matriz.at(fila-1).at(j+1);
        }
        matriz.at(fila-1).at(getCols()-1) = aux1;
    }
}

void matriz::imprimirMatriz(){
    for(int i = 0; i < getFilas(); i++){
        for(int j = 0; j < getCols(); j++){
            cout << matriz.at(i).at(j) << " ";
        }
        cout << '\n';
    }
    cout << "---" << '\n';
}

std::ostream& operator<<(std::ostream& os, matriz& m){
    m.imprimirMatriz();
    return os;
}

void escogeOpcion(matriz& m){
    int numOpciones;
    string opcion; 
    cin >> numOpciones;
    for(int i = 0; i < numOpciones; i++){
        cin >> opcion;
        if(opcion == "filas") m.intercambiarFilas();
        else if(opcion == "columnas") m.intercambiarColumnas();
        else if(opcion == "cruz") m.rellenarCruz(); 
        else if(opcion == "rotarFila") m.rotarFila();
        else if(opcion == "rotarCol") m.rotarCol();
    }
}
bool resuelveCaso(){
    matriz m;
    cin >> m;
    if(m.getFilas() == 0 || m.getCols() == 0) return false;
    escogeOpcion(m);
    cout << m;
    return true;
}

int main(){
    while(resuelveCaso());
    return 0; 
}
