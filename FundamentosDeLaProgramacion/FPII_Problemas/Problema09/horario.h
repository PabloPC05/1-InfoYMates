#include <vector>
#include "tHora.h"
const int MAX_TRENES = 100;
struct tHorarioTrenes {
    tHora horario[MAX_TRENES];
    int num_trenes;
};

void inicia(tHorarioTrenes &trenes);

void inserta(tHorarioTrenes &trenes, tHora const& h);

bool busca(tHorarioTrenes const& trenes, tHora const& h, tHora &sig);