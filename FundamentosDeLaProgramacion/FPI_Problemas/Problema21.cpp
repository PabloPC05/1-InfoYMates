// Problema 21: ¿Cuantas letras seguidas estan ordenadas?
// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*
* Comprueba que la palabra tiene más de 2 caracteres. En ese caso, cada vez que haya dos letras consecutivas suma 1 a una variable, 
* y cuando ya no ocurra toma nuevamente el valor inicial. Cada vez que termina compara con el valor maximo obtenido. 
*/
void calculo(string strmin2) {
	int length = strmin2.size() -1, serial = 1, max = 0;
	if (length == 0) max = 1; 
	else {
		for (int i = 0; i < length; i++) {
			if (strmin2[i + 1] > strmin2[i]) {
				serial++;
				if (max < serial) max = serial;
			}
			else serial = 1;
		}
	}
	cout << length +1 << " " << max << "\n";
}
/*
* Se encarga de transformar la cadena de caracteres a minuscula
*/
string minusculas(string str) {
	int length = (str.size() - 1);
	string strmin;
	for (int i = 0; i <= length; i++) {
		strmin.push_back(tolower(str[i]));
	}
	return strmin;
}
int main() {
	string str, strmin2;
	cin >> str;
	while (str != "XXX") {
		strmin2 = minusculas(str);
		calculo(strmin2);
		cin >> str;
	}
	return 0;
}