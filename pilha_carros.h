#ifndef PILHA_CARROS_H
#define PILHA_CARROS_H

#include "carros.h"  // Inclui a definição da estrutura Carro

#define MAX_CARROS 2  // Define o tamanho máximo da pilha

// Estrutura de dados para representar uma pilha de carros em um beco
typedef struct {
    Carro carros[MAX_CARROS];  // Vetor para armazenar os carros na pilha
    int topo;  // Índice do topo da pilha
} PilhaCarros;

// Declaração das pilhas de carros (um para cada beco)
extern PilhaCarros becoA;
extern PilhaCarros becoB;

// Funções para manipulação das pilhas
void inicializar_pilhas();
int pilha_cheia(PilhaCarros* beco);
int pilha_vazia(PilhaCarros* beco);
int empilhar(PilhaCarros* beco, Carro carro);
Carro desempilhar(PilhaCarros* beco);

#endif
