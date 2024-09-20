#include <iostream>
#include <fstream>
#include <iomanip>
const int CENTINELA = -1;
const int NUMRIDERS = 7;
const int NUMPEDIDOS = 50;

struct tTiempo {
	int horas;
	int minutos;
};
struct tRider {
	double ganancias;
	tTiempo disponibilidad;
};
struct tPedido {
	tTiempo solicitud;
	int gestionEnvio;
	bool prioritario;

	tTiempo salidaEnvio;
	int riderEncargado;
	bool procesado;
};
struct tListaPedidos {
	tPedido pedido[NUMPEDIDOS];
	int cont;
};
using tArrayRider = tRider[NUMRIDERS];
using namespace std;


int siguiente(tListaPedidos& listaPedidos) {
	int i = 0, aux = 0;
	bool caca = false; 
	for (int i = listaPedidos.cont-1; i >= 0 ; i--) {
		if (!listaPedidos.pedido[i].procesado && listaPedidos.pedido[i].prioritario) {
			aux = i;
			caca = true; 
		}
	}
	while (!caca) {
		if (!listaPedidos.pedido[i].procesado) {
			aux = i;
			caca = true;
		}
		i++;
	}
	return aux;
}

tTiempo operator+(tTiempo const& tiempo, int min) {
	tTiempo resultadoSuma;
	resultadoSuma.horas = tiempo.horas; 
	resultadoSuma.minutos = tiempo.minutos;
	resultadoSuma.minutos = resultadoSuma.minutos + min;
	while (resultadoSuma.minutos >= 60) {
		resultadoSuma.horas++;
		resultadoSuma.minutos = resultadoSuma.minutos - 60;
	}
	return resultadoSuma;
}

bool operator<(tTiempo const& tiempoIzq, tTiempo const& tiempoDer) {
	return (tiempoIzq.horas < tiempoDer.horas) || (tiempoIzq.horas == tiempoDer.horas && tiempoIzq.minutos < tiempoDer.minutos);
}

int eligeRider(const tArrayRider& riders) {
	int i = 0, aux = 0;
	tTiempo minimo;
	minimo = riders[i].disponibilidad;
	while (i < NUMRIDERS) {
		i++;
		if (operator<(riders[i].disponibilidad, minimo)) {
			minimo = riders[i].disponibilidad;
			aux = i;
		}
	}
	return aux;
}

ostream& operator<< (std::ostream& out, tTiempo const& tiempo) {
	return cout << setfill('0') << setw(2) << tiempo.horas << ':' << setfill('0') << setw(2) << tiempo.minutos;
}

void planifica(tListaPedidos& listaPedidos, tArrayRider& riders) {
	int j = 0;
	tTiempo mayor; 
	mayor.horas = 0; 
	mayor.minutos = 0;
	while (j < listaPedidos.cont) {
		int i = siguiente(listaPedidos);
		listaPedidos.pedido[i].riderEncargado = eligeRider(riders);
		listaPedidos.pedido[i].procesado = true;
		if (j <= NUMRIDERS) listaPedidos.pedido[i].salidaEnvio = operator+(listaPedidos.pedido[i].solicitud, listaPedidos.pedido[i].gestionEnvio);
		else {
			if (operator<(riders[listaPedidos.pedido[i].riderEncargado].disponibilidad, listaPedidos.pedido[i].solicitud)) mayor = listaPedidos.pedido[i].solicitud; 
			else mayor = riders[listaPedidos.pedido[i].riderEncargado].disponibilidad;
			listaPedidos.pedido[i].salidaEnvio = operator+(mayor, listaPedidos.pedido[i].gestionEnvio);
		}
		riders[listaPedidos.pedido[i].riderEncargado].disponibilidad = listaPedidos.pedido[i].salidaEnvio;
		riders[listaPedidos.pedido[i].riderEncargado].ganancias = riders[listaPedidos.pedido[i].riderEncargado].ganancias + listaPedidos.pedido[i].gestionEnvio * 0.25;
		cout << "Pedido a las ";
		operator<<(cout, listaPedidos.pedido[i].solicitud);
		cout << " - Prioridad: " << " - " << listaPedidos.pedido[i].gestionEnvio << "' - Rider " << listaPedidos.pedido[i].riderEncargado << " - Envio: ";
		operator<<(cout, listaPedidos.pedido[i].salidaEnvio);
		cout << '\n';
		j++;
	}
}

void mostrar(tListaPedidos& listaPedidos, tArrayRider& riders) {
	cout << "Se asignan a los riders...\n";
}

bool carga(tListaPedidos& listaPedidos, tArrayRider& riders) {
	ifstream archivo;
	string nombreArchivo;
	int i = 0;
	cout << "Introduce el nombre del archivo: ";
	cin >> nombreArchivo;
	archivo.open(nombreArchivo);
	if (!archivo.is_open()) return false;
	archivo >> listaPedidos.pedido[listaPedidos.cont].solicitud.horas >> listaPedidos.pedido[listaPedidos.cont].solicitud.minutos >> listaPedidos.pedido[listaPedidos.cont].gestionEnvio >> listaPedidos.pedido[listaPedidos.cont].prioritario;
	while (listaPedidos.pedido[listaPedidos.cont].solicitud.horas != CENTINELA) {
		listaPedidos.cont++;
		archivo >> listaPedidos.pedido[listaPedidos.cont].solicitud.horas >> listaPedidos.pedido[listaPedidos.cont].solicitud.minutos >> listaPedidos.pedido[listaPedidos.cont].gestionEnvio >> listaPedidos.pedido[listaPedidos.cont].prioritario;
	}
	return true;
}

void inicializacion(tListaPedidos& listaPedidos, tArrayRider& riders) {
	listaPedidos.cont = 0;
	for (int i = 0; i < NUMPEDIDOS; i++) {
		listaPedidos.pedido[i].solicitud.horas = 0;
		listaPedidos.pedido[i].solicitud.minutos = 0;
		listaPedidos.pedido[i].gestionEnvio = 0;
		listaPedidos.pedido[i].prioritario = 0;
		listaPedidos.pedido[i].salidaEnvio.horas = 0;
		listaPedidos.pedido[i].salidaEnvio.minutos = 0;
		listaPedidos.pedido[i].riderEncargado = 0;
		listaPedidos.pedido[i].procesado = 0;
	}
	for (int i = 0; i <= NUMRIDERS; i++) {
		riders[i].ganancias = 0;
		riders[i].disponibilidad.horas = 0;
		riders[i].disponibilidad.minutos = 0;
	}
}

int main() {
	tListaPedidos listaPedidos;
	tArrayRider riders;
	inicializacion(listaPedidos, riders);
	carga(listaPedidos, riders);
	planifica(listaPedidos, riders);
	mostrar(listaPedidos, riders);
	return 0;
}