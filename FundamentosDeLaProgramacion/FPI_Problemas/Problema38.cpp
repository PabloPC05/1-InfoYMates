// Problema 38: Criba de Eratsotenes

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
const int MAX = 1000000;

int main() {
    bool array[MAX];
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        array[i] = true;
    }
    for (int i = 2; i < sqrt(num); ++i){
        if(array[i]){
            for(int cont = i; cont * i < num; ++cont){
                array[cont * i] = false;
            }
        }
    }
    for (int i = 2; i < num; i++) {
        if (array[i]) {
            cout << i << "\n";
        }
    }
}