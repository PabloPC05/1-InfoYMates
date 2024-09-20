// Problema 39: Descomponer un numero en factores primos

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
const int MAX = 10000;

void factoresPrimos(int num) {
    bool boleanoPrimos[MAX];
    for (int i = 0; i < num; i++){
        boleanoPrimos[i] = true;
    }
    for (int i = 2; i < sqrt(num); ++i){
        if(boleanoPrimos[i]){
            for(int cont = i; cont * i <= num; ++cont){
                boleanoPrimos[cont * i] = false;
            }
        }
    }
    int primos[MAX];
    int j = 0; 
    for (int i = 2; i < num; ++i) {
        if (boleanoPrimos[i]){
            primos[j] = i;
            ++j;
        }
    }
    int i = 0, num2 = num;
    while (i < j){
        if((num%primos[i]) == 0){
            num = num / primos[i];
            cout << primos[i] << " ";
        }
        else ++i;
    }
    if (num2 == num) cout << num;
    cout << "\n";
}

int main() {
    int num;
    cin >> num;
    while (num != 0) {
        factoresPrimos(num);
        cin >> num;
        }
    return 0;
}
