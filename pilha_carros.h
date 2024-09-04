#ifndef PILHA_CARROS_H
#define PILHA_CARROS_H

#include "carro.h" // incluindo a estrutura carro

#define MAX_CARROS 2  // Define o tamanho máximo da pilha

typedef struct {
    Carro carros[MAX_CARROS];  // Vetor para armazenar os carros na pilha
    int topo;  // Índice do topo da pilha
} PilhaCarros;

// Declaração das pilhas de carros (um para cada beco)
extern PilhaCarros ruaA;
extern PilhaCarros ruaB;

// Funções para manipulação das pilhas
void inicializar_pilha();
int pilha_cheia(PilhaCarros* rua);
int pilha_vazia(PilhaCarros* rua);
int push(PilhaCarros* rua, Carro carro);
Carro pop(PilhaCarros* rua);

#endif