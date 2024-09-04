#ifndef FILA_DE_ESPERA_H
#define FILA_DE_ESPERA_H

#include "carros.h"

#define MAX_FILA_ESPERA 10

// Estrutura para representar uma fila de espera
typedef struct {
    Carro carros[MAX_FILA_ESPERA];  // Array de carros na fila de espera
    int frente;  // Índice do carro na frente da fila
    int tras;    // Índice do carro no final da fila
    int tamanho; // Número atual de carros na fila
} FilaEspera;

extern FilaEspera fila;

// Funções para manipulação da fila de espera
void inicializar_fila(FilaEspera* fila);
int fila_vazia(FilaEspera* fila);
int fila_cheia(FilaEspera* fila);
int enfileirar(FilaEspera* fila, Carro carro);
Carro desenfileirar(FilaEspera* fila);

#endif
