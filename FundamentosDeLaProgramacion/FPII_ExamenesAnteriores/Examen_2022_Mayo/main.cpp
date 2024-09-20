#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
#include <iostream>
#include <fstream>
#include "Jugadoras.h"
#include "Liga.h"
using namespace std;

void fichar_nuevas_jugadoras(Liga& liga, Jugadoras& jugadoras) {
    int numFichajes;
    cin >> numFichajes;
    for (int i = 0; i < numFichajes; i++) {
        string equipo, nombre, apellido; 
        int id, goles;
        cin >> equipo >> id >> nombre >> apellido >> goles;
        if (!liga.insertar(equipo, id)) cout << '\n' << equipo << " no puede fichar mas jugadoras\n\n";
        else{
            Jugadora* jugadora = new Jugadora(id, nombre, apellido, goles);
            jugadoras.insertar(jugadora);
        }
    }
}

int main() {
// Si estás ejecutando el programa en tu ordenador, las siguientes líneas
// redirigirán cualquier lectura de cin al fichero 'entrada.txt'. Esto es
// útil para no tener que teclear los casos de prueba por teclado cada vez
// que ejecutas el programa.
//
// Si prefieres teclear la entrada por teclado en tu ordenador,
// comenta las líneas comprendidas entre los #ifndef y #endif
#ifndef DOMJUDGE
   std::ifstream in("entrada.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

#ifndef DOMJUDGE
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

      Jugadoras jugadoras;
      jugadoras.cargar(cin);
      Liga liga;
      liga.cargar(cin);

      jugadoras.mostrar(cout);
      cout << '\n';
      liga.mostrar(cout, jugadoras);
      cout << '\n';

      string nombre; cin >> nombre;
      cout << "Se aumenta el presupuesto de " << nombre << "\n";
      liga.aumentar_presupuesto(nombre);

      fichar_nuevas_jugadoras(liga, jugadoras);

      jugadoras.mostrar(cout);
      cout << '\n';
      liga.mostrar(cout, jugadoras);
      cout << '\n';

      Equipo const* campeon = liga.campeon_liga(cin);
      cout << "El campeon de la liga es " << campeon->nombre() << " con " << campeon->puntos() << " puntos\n";

      cin >> nombre;
      cout << "\nDesciende el equipo " << nombre << "\n\n";
      liga.descenso_equipo(nombre, jugadoras);

      jugadoras.mostrar(cout);
      cout << '\n';
      liga.mostrar(cout, jugadoras);
      cout << '\n';

}
