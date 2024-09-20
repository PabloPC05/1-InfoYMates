#include "ListaClientes.h"
#include "ListaPartes.h"
#include <iostream>
#include <string>
#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
using namespace std;

bool darNuevoParte(ListaClientes& lista, string const& nif) {
   Cliente* cliente = lista.buscar_cliente(nif);
   if(cliente == nullptr) return false;
   else{
      cliente->nuevo_parte();
      if(cliente->num_partes() > 5) lista.eliminar_cliente(nif);
      else{
         cliente->actualiza_precio(cliente->precio_seguro()*1.1);
      }
      return true;
   }
}

void bonificacionAnual(ListaClientes& lista) {
   for(int i = 0; i < lista.num_clientes(); i++){
      if(lista.cliente(i)->num_partes() <= 1){
         lista.cliente(i)->actualiza_precio(lista.cliente(i)->precio_seguro()*0.95);
      }
   }
}

int main() {
   // Si est�s ejecutando el programa en tu ordenador, las siguientes l�neas
   // redirigir�n cualquier lectura de cin al fichero 'entrada.txt'. Esto es
   // �til para no tener que teclear los casos de prueba por teclado cada vez
   // que ejecutas el programa.
   //
   // Si prefieres teclear la entrada por teclado en tu ordenador,
   // comenta las l�neas comprendidas entre los #ifndef y #endif
#ifndef DOMJUDGE
   std::ifstream in("entrada.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

#ifndef DOMJUDGE
      _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

   ListaClientes lc;
   lc.cargar();
   cout << "LISTA DE CLIENTES\n";
   lc.mostrar();

   ListaPartes lp;

   lp.cargar();

   for (int i = 0; i < lp.num_partes(); i++) {
      string nif = lp.parte(i);
      if (!darNuevoParte(lc, nif))
         cout << "\nEl cliente " << nif << " no existe\n";
   }

   cout << "\nLISTA DE CLIENTES TRAS DAR LOS PARTES\n";
   lc.mostrar();

   bonificacionAnual(lc);
   cout << "\nLISTA DE CLIENTES TRAS APLICAR LA BONIFICACION\n";
   lc.mostrar();


   return 0;
}
