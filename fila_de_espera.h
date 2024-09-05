#ifndef FILA_DE_ESPERA_H
#define FILA_DE_ESPERA_H

#include "carros.h"

#define MAX_FILA_ESPERA 10

typedef struct {
    Carro carros[MAX_FILA_ESPERA];
    int frente;
    int tras;
    int tamanho;
} FilaEspera;

extern FilaEspera fila;

void inicializar_fila(FilaEspera* fila);
int fila_vazia(FilaEspera* fila);
int fila_cheia(FilaEspera* fila);
int enfileirar(FilaEspera* fila, Carro carro);
Carro desenfileirar(FilaEspera* fila);

#endif
