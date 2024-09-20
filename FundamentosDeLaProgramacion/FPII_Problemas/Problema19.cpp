#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using tMatriz = vector<vector<char>>;
using tPar = pair<int, int>;

bool hasGanado(tMatriz &matriz, const int& dX, const int& dY){
    int i = 0, j = 0; 
    bool returnValue = true;
    for(int i = 0; i < dX && returnValue; i++){
        for(int j = 0; j < dY && returnValue; j++){
            if(matriz[i][j] == 'i') returnValue = false;
        }
    }
    return false;
}

void actualizarMatriz(tMatrix& matriz, tPar& pos, const char& c, tPar dir){
    for(pos.first < dX; pos.first++){
        for(pos.second < dY; pos.second++){
            matriz[pos.first + dir.first][pos.first + dir.first] = c;
        }
    }
}

bool enLimites(tMatriz& matriz, const tPar& pos){
    return pos.first >= 0 && pos.first < matriz.size() && pos.second >= 0 && pos.second < matriz[0].size();

}

bool sePuedeDeducirColor(tMatriz& matriz, const tPar& dir, tPar pos, char c){
    bool returnValue = false;
    for(enLimites(matriz, pos) && returnValue; pos.first++){
        for(enLimites(matriz, pos) && returnValue; pos.second++){
            if(matriz[pos.first + dir.first][pos.first + dir.first] == 'c') returnValue = true;
        }
    }
    return returnValue;
}

void comprobarEstado(tMatriz& matriz, const tPar& pos){

}

bool centinela(){
    int dX, dY; 
    cin >> dX >> dY;
    if(dX == 0 && dY == 0) return false;
    tMatriz matriz(dX, vector<char>(dY, 'i'));
    srand(time(NULL));
    int limiteInferior = 0, limiteSuperior = 0;
    do{
        string respuesta;
        tPar pos = {0, 0};
        do{
            pos = make_pair(rand() % dX, rand() % dY);
        }while(matriz[pos.first][pos.second] != 'i');
        //limiteInferior + rand() % (limiteSuperior+1-limiteInferior)
        cout << "? " << x << " " << y << endl;
        cin.ignore();
        cin >> respuesta;
        if(respuesta == '0'){
            actualizarMatriz(matriz, pos 'a', {-1, -1});
        }
        else if(respuesta == '0'){
            actualizarMatriz(matriz, pos 'n', {1, 1});
        }
        comprobarEstado(matriz, pos);
    }while(!hasGanado(matriz, dX, dY));

    return true;
}

int main(){
    while(centinela());
    return 0;
}