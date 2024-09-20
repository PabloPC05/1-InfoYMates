/*Esta funcion se encarga de coprobar si un punto es de silla, con la definicion de que un punto de silla es el menor de su fila y el maximo de su columna*/
int esMatrizSillaA(int* m, int DIM) {
    int returnValue = 0;
    for (int i = 0; i < DIM && returnValue == 0; i++) {
        for (int j = 0; j < DIM && returnValue == 0; j++) {
            int minF = m[i * DIM + j], maxC = m[i * DIM + j];
            for (int k = 0; k < DIM && returnValue == 0; k++) {
                if (m[i * DIM + k] < minF) minF = m[i * DIM + k];
            }
            if (minF == m[i * DIM + j]) returnValue = 1;
            for (int k = 0; k < DIM && returnValue; k++) {
                if (m[k * DIM + j] > maxC) maxC = m[k * DIM + j];
            }
            if (returnValue == 1 && maxC == m[i * DIM + j]) returnValue = 1;
            else returnValue = 0;
        }
    }
    return returnValue;
}

/*Por otro lado esta funcion se encarga de la otra definicion de punto de silla, que sea el mayor de su fila y el menor de su columna*/
int esMatrizSillaB(int* m, int DIM) {
    int returnValue = 0;
    for (int i = 0; i < DIM && returnValue == 0; i++) {
        for (int j = 0; j < DIM && returnValue == 0; j++) {
            int minC = m[i * DIM + j], maxF = m[i * DIM + j];
            for (int k = 0; k < DIM && returnValue == 0; k++) {
                if (m[i * DIM + k] > maxF) maxF = m[i * DIM + k];
            }
            if (maxF == m[i * DIM + j]) returnValue = 1;
            for (int k = 0; k < DIM && returnValue == 1; k++) {
                if (m[k * DIM + j] < minC) minC = m[k * DIM + j];
            }
            if (returnValue == 1 && minC == m[i * DIM + j]) returnValue = 1;
            else returnValue = 0;
        }
    }
    return returnValue;
}

int esMatrizSilla(int* m, int DIM) {
    return (esMatrizSillaA(m, DIM) + esMatrizSillaB(m, DIM));
}
