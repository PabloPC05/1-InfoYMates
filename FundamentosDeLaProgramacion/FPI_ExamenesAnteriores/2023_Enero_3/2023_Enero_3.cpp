#include <iostream>
#include <fstream>
using namespace std;
const int MAXEMPRESAS = 3; 
const int MAXCLIENTES = 5;
const int MAXOPS = 20;  
const string CENTINELA = "XXX";

struct tEmpresa{
    string nombre; 
    int numAcciones;
};
struct tCartera{
    string nombreCliente;
    tEmpresa empresa[MAXEMPRESAS];
    int cont; 
};
struct tBroker{
    tCartera cartera[MAXCLIENTES];
    int cont; 
};
struct tOperacion{
    char tipo;
    tEmpresa empresa; 
    string nombreCliente;
};
struct tOpList{
    tOperacion operacion[MAXOPS];
    int cont; 
};

int buscarCliente(tBroker& listaClientes, string& nombreCliente){
    int i = 0;
    while(listaClientes.cartera[i].nombreCliente != nombreCliente && i < listaClientes.cont) i++;
    if(listaClientes.cartera[i].nombreCliente != nombreCliente) i = -1; 
    return i; 
}

int buscarActivo(tCartera& cartera, tEmpresa& empresa){
    int i = 0; 
    while(cartera.empresa[i].nombre != empresa.nombre && i < cartera.cont) i++;
    if(cartera.empresa[i].nombre != empresa.nombre) i = -1; 
    return i; 
}

void eliminar(tCartera& cartera, tEmpresa& empresa){
    int i = buscarActivo(cartera, empresa);
    cartera.empresa[i].nombre = "";
    cartera.empresa[i].numAcciones = 0; 
    cartera.cont--;
}

int nuevoCliente(tBroker& listaClientes, string& nombreCliente){
    int i = 0; 
    if(listaClientes.cont < MAXCLIENTES){
        while(listaClientes.cartera[i].nombreCliente != "") i++;
        listaClientes.cartera[i].nombreCliente = nombreCliente;
        listaClientes.cont++;
    }
    else if(listaClientes.cont == MAXCLIENTES) i = -1; 
    return i; 
}

void nuevaOp (tOpList& operacionesNoValidas, tOperacion& operacion){
    operacionesNoValidas.operacion[operacionesNoValidas.cont] = operacion;
    operacionesNoValidas.cont++;
}

void mostrarOp(const tOperacion& operacion){
    cout << operacion.tipo << ' ' << operacion.empresa.numAcciones << ' ' << operacion.empresa.nombre<< ' ' << operacion.nombreCliente<<'\n'; 
}

int indice (tCartera& cartera){
    int i = 0; 
    while(cartera.empresa[i].nombre != "") i++;
    return i; 
}

void operar(tOperacion& operacion, tCartera& cartera, tOpList& operacionesNoValidas){
    int i = buscarActivo(cartera, operacion.empresa); 
    if(operacion.tipo == 'B'){ // operacion de compra
        if(i != -1){
            cartera.empresa[i].numAcciones = cartera.empresa[i].numAcciones + operacion.empresa.numAcciones; 
        }
        else{
            if(cartera.cont < MAXEMPRESAS){
                int j = indice(cartera);
                cartera.empresa[j].nombre = operacion.empresa.nombre; 
                cartera.empresa[j].numAcciones = operacion.empresa.numAcciones; 
                cartera.cont++;

            }
            else{
                nuevaOp(operacionesNoValidas, operacion); 
            }
        }
    }
    else { //operacion de venta
        if(i != -1){
            while(operacion.empresa.numAcciones > 0 && cartera.empresa[i].numAcciones > 0){
                cartera.empresa[i].numAcciones--;
                operacion.empresa.numAcciones--;
            }
            if(operacion.empresa.numAcciones > 0) nuevaOp(operacionesNoValidas, operacion);
            else if (cartera.empresa[i].numAcciones == 0) eliminar(cartera, operacion.empresa);
        }
        else{
            nuevaOp(operacionesNoValidas, operacion);
        }
    } 
}


void mostrarCli(const tCartera& cartera){
    cout << cartera.nombreCliente<<": "; 
    for(int i = 0; i < MAXEMPRESAS; i++){
        if(cartera.empresa[i].numAcciones != 0 && cartera.empresa[i].nombre != "") cout << cartera.empresa[i].numAcciones << 'x' << cartera.empresa[i].nombre<<'\t';
    }
    cout << '\n';
}

void inicializar(tBroker& listaClientes, tOpList& operacionesNoValidas){
    listaClientes.cont = 0; 
    for(int i = 0; i < MAXCLIENTES; i++){
        listaClientes.cartera[i].cont = 0;
        for(int j = 0; j < MAXEMPRESAS; j++){
            listaClientes.cartera[i].empresa[j].numAcciones = 0; 
        }
    }
    operacionesNoValidas.cont = 0; 
    for(int i = 0; i < MAXOPS; i++){
        operacionesNoValidas.operacion[i].empresa.numAcciones = 0; 
    }
}

int main(){
    ifstream archivo;
    string fileName;
    tOperacion operacion;
    tBroker listaClientes;
    tOpList operacionesNoValidas;   
    cout << "Introduce el nombre del archivo con las operaciones: "; 
    cin >> fileName; 
    archivo.open(fileName);
    while(!archivo.is_open()) {
        cout << "Error, vuela a introducir el nombre: "; 
        cin >> fileName;
    }
    inicializar(listaClientes, operacionesNoValidas);
    archivo >> operacion.nombreCliente >> operacion.tipo >> operacion.empresa.nombre >> operacion.empresa.numAcciones;
    while(operacion.nombreCliente != CENTINELA){
        int i = buscarCliente(listaClientes, operacion.nombreCliente);
        mostrarOp(operacion);
        if(i == -1) i = nuevoCliente(listaClientes, operacion.nombreCliente);
        operar(operacion, listaClientes.cartera[i], operacionesNoValidas);
        for(int j = 0; j < listaClientes.cont; j++){
            mostrarCli(listaClientes.cartera[j]);
        }
        archivo >> operacion.nombreCliente >> operacion.tipo >> operacion.empresa.nombre >> operacion.empresa.numAcciones;
    }
    return 0; 
}