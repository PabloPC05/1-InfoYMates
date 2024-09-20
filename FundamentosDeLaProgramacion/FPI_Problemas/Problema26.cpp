// Problema 26: Primera palabra

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;	
/*
* Comienza pidiendo el numero de palabras, luego toma la primera como minimo y va comparando desde ahí con el resto. 
*/
void calculo() {
	int numWords;
	cin >> numWords;
	string word, shortestword;
	cin >> word;
	shortestword = word;
	for (int i = 1; i < numWords; i++) {
		cin >> word;
		if (word < shortestword) shortestword = word;
	}
	cout << shortestword << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}