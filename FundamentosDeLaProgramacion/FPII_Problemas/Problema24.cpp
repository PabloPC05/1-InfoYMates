#include <iostream>
#include <vector>
using namespace std;

bool esNumero(char temp){
    return isdigit(temp);
}

bool esOperador(char temp){
    return temp == '+' || temp == '-' || temp == '*' || temp == '/';
}

int resultado(int a, int b, char& op){
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int recursividadOperaciones(int a = 0, int b = 0, char op = '\0'){
    int a1, b1;
    char temp, op1;
    cin >> temp;
    if(esOperador(temp)){
        op1 = temp;
        a1 = recursividadOperaciones();
        b1 = recursividadOperaciones();
    }
    else if(esNumero(temp)){
        return temp - 48;
    }
    return resultado(a1, b1, op1);
}

void resuelveCaso(){
    cout <<  recursividadOperaciones() << '\n';
}

int main(){
    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++) resuelveCaso();
    return 0;
}