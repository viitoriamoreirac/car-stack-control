#include "fila_de_espera.h"
#include <stdio.h>

FilaEspera fila;

void inicializar_fila(FilaEspera* fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

int fila_vazia(FilaEspera* fila) {
    return fila->tamanho == 0;
}

int fila_cheia(FilaEspera* fila) {
    return fila->tamanho == MAX_FILA_ESPERA;
}

int enfileirar(FilaEspera* fila, Carro carro) {
    if (fila_cheia(fila)) {
        printf("Fila de espera cheia! Não é possível adicionar o carro.\n");
        return 0; 
    }
    fila->tras = (fila->tras + 1) % MAX_FILA_ESPERA;
    fila->carros[fila->tras] = carro;
    fila->tamanho++;
    return 1;  // carro foi enfileirado
}

Carro desenfileirar(FilaEspera* fila) {
    Carro carro_removido = {0};  // inicializa um carro vazio
    if (fila_vazia(fila)) {
        printf("Fila de espera vazia! Não há carros para remover.\n");
        return carro_removido;  // retorna um carro vazio
    }
    carro_removido = fila->carros[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_FILA_ESPERA;
    fila->tamanho--;
    return carro_removido;
}

