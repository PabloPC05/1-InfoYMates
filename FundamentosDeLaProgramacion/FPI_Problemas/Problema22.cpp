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
* Además, cada vez que haya un nuevo valor máximo guarda la posición del ultimo caracter. Una vez finalizado el bucle, se encarga de guardar 
* en otro string la parte de la palabra en orden alfabético, para ello guarda desde la posición del último caracter menos el valor maximo menos 1,
* debido a la diferencia entre empezar por 0 y 1. Finalmente la imprime en pantalla. 
*/
void calculo(string strmin2) {
	int length = strmin2.size() - 1, serial = 1, max = 0, aux = 0;
	string serialword; 
	if (length == 0) {
		max = 1;
		serialword = strmin2;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (strmin2[i + 1] > strmin2[i]) {
				serial++;
				if (max < serial) {
					max = serial;
					aux = i + 1;
				}
			}
			else serial = 1;
		}
		serialword = strmin2.substr((aux - (max -1)), max);
	}
	cout << length + 1 << " " << max << ' ' << serialword << "\n";
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