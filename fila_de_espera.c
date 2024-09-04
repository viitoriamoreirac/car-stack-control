#include "fila_de_espera.h"
#include <stdio.h>

FilaEspera fila;

// Função para inicializar a fila de espera
void inicializar_fila(FilaEspera* fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

// Função para verificar se a fila de espera está vazia
int fila_vazia(FilaEspera* fila) {
    return fila->tamanho == 0;
}

// Função para verificar se a fila de espera está cheia
int fila_cheia(FilaEspera* fila) {
    return fila->tamanho == MAX_FILA_ESPERA;
}

// Função para adicionar um carro à fila de espera
int enfileirar(FilaEspera* fila, Carro carro) {
    if (fila_cheia(fila)) {
        printf("Fila de espera cheia! Não é possível adicionar o carro.\n");
        return 0;  // Indica que não foi possível enfileirar
    }
    fila->tras = (fila->tras + 1) % MAX_FILA_ESPERA;
    fila->carros[fila->tras] = carro;
    fila->tamanho++;
    return 1;  // Indica sucesso ao enfileirar
}

// Função para remover um carro da fila de espera
Carro desenfileirar(FilaEspera* fila) {
    Carro carro_removido = {0};  // Inicializa um carro vazio
    if (fila_vazia(fila)) {
        printf("Fila de espera vazia! Não há carros para remover.\n");
        return carro_removido;  // Retorna um carro vazio
    }
    carro_removido = fila->carros[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_FILA_ESPERA;
    fila->tamanho--;
    return carro_removido;
}

