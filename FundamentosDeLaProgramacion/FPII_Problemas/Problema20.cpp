#include <iostream>
#include <string>
using namespace std;

string fraseSinEspacios(string& frase){
    string returnValue; 
    while(frase.size() > 0){
        int i = frase.find(' ');
        if(i == -1){
            returnValue = returnValue + frase;
            frase.clear();
        }
        else{
            returnValue = returnValue + frase.substr(0, i);
            frase.erase(0, i+1);
        }
    }
    return returnValue;
}

string fraseDelReves(string& frase){
    string returnValue;
    int size = frase.size();
    returnValue.reserve(size);
    for(int i = 0; i < size; i++){
        returnValue.push_back(frase[size-i-1]);
    }
    return returnValue;
}

void toLower(string& s){
    for(int i = 0; i< s.size(); i++){
        s[i] = tolower(s[i]);
    }
}

bool comprobarIgualdad(string s1, string s2){
    if(s1 == s2) return true;
    else return false;
}

bool resuelveCaso(){
    string frase;
    getline(cin, frase);
    if(frase == "XXX") return false;
    toLower(frase);
    frase = fraseSinEspacios(frase);
    if(comprobarIgualdad(frase, fraseDelReves(frase))) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}