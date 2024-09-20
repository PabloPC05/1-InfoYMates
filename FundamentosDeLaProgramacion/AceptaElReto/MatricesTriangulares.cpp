#include <iostream>
using namespace std;
const int MAX = 50; 

bool resuelveCaso(){
    int n; 
    cin >> n; 
    if(n == 0) return false; 
    int matriz[MAX][MAX]; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j]; 
        }
    }
    bool esTriangularSuperior = true; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(matriz[i][j] != 0) esTriangularSuperior = false; 
        }
    }
    bool esTriangularInferior = true; 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(matriz[i][j] != 0) esTriangularInferior = false; 
        }
    }
    if(esTriangularSuperior || esTriangularInferior) cout << "SI\n"; 
    else cout << "NO\n"; 
    return true; 

}
int main(){
    while(resuelveCaso());
    return 0; 
}