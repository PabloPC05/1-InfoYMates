// Pablo Pardo Cotos
// FP1-DG25
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*
*El bucle comprueba que las letas estan ordenadas empezando por el final,
*terminando cuando la i es 0, cuando ha terminado de analizarlas todas o cuando 2 no estan ordenadas
*/
void calculo(string strmin2) {
	int i = (strmin2.size() - 1);
	while (0 < i && strmin2[i] > strmin2[i-1]) {
		i--;
	}
	if (i == 0) cout << "SI\n";
	else cout << "NO\n";
}
/*
* Se encarga de transformar la cadena de caracteres a minuscula
*/
string minusculas(string str) {
	int lenght = (str.size() - 1);
	string strmin;
	for (int i = 0; i <= lenght; i++) {
		strmin.push_back(tolower(str[i]));
	}
	return strmin;
}
/*
* Comprueba si los caracteres introducidos son letras
*/
bool isAlpha(string str) {
	int i = 0, lenght = (str.size() - 1);
	while (lenght == i) {
		if (!isalpha(str[i])) return false;
		i++;
	}
	return true;
}
int main() {
	string str, strmin2;
	cin >> str;
	while (str != "XXX" && isAlpha(str)) {
		strmin2 = minusculas(str);
		calculo(strmin2);
		cin >> str;
	}
	return 0;
}