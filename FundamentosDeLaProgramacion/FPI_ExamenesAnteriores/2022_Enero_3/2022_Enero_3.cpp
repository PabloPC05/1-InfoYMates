#include <iostream>
#include <fstream>
using namespace std; 
const int MAX_HOSPITALES = 10; 
const int MAX_NINNOS = 50;
struct tCita{
    string CIPA;
    string nombrePeque;
};
struct tListaCitas{
    int cont; 
    tCita cita[MAX_NINNOS];
};
struct tHospital{
    string nombre; 
    char turno; 
    tListaCitas citas;
};
struct tListaHospitales{
    int cont; 
    tHospital hospital[MAX_HOSPITALES];
};

bool buscarCipaCitas()

bool buscarCipaHospitales(tListaHospitales& hospitales, string& cipa){
    
}

bool cargar(tListaHospitales& hospitales){
    ifstream archivo; 
    string fileName;
    cout << "Introduce el nombre del archivo: ";
    cin >> fileName; 
    archivo.open(fileName);
    if(!archivo.is_open()) return false;
    archivo >> hospitales.cont;
    for(int i = 0; i < hospitales.cont; i++){
        archivo >> hospitales.hospital[i].nombre >> hopsitales-hospital[i].turno;
        for(int j = 0; j < MAX_HOSPITALES)
        hospitales.hospital[i].citas[j].cont = 0; 
    }    
}

int main(){
    return 0; 
}