#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;


// Prototipos
int menu();
void cargar(ifstream& file, tSecuencia& secuencia);
bool cargar(string fileName, tListaTec& listaTec);
void mostrar(const tListaTec& listaTec);
void mostrar(const tListaTec& listaTec, int impacto);
bool compararSecuencias(const tSecuencia& tecnica, const tSecuencia& move);
int calcularImpacto(const tTecnica& move, const tListaTec& listaTec);
void lucha(string fileName, const tListaTec& listaTec);

int main() {
 
  

   return 0;
}


bool compararSecuencias(const tSecuencia& tecnica, const tSecuencia& secuencia) {
	bool ok = true;
	int pos = 0;

	if (tecnica.contador != secuencia.contador)
		ok = false;
	else {
		while ((pos < tecnica.contador) && (tecnica.movs[pos] == secuencia.movs[pos]))
			pos++;
		if (pos < tecnica.contador)
			ok = false;
	}

	return ok;
}

