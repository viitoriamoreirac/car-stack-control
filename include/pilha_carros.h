#ifndef PILHA_CARROS_H
#define PILHA_CARROS_H

#include "carros.h"

#define MAX_CARROS 10  // diminuir tamanho para facilitar testes


typedef struct {
    Carro carros[MAX_CARROS];
    int topo;
} PilhaCarros;


extern PilhaCarros becoA;
extern PilhaCarros becoB;

void inicializar_pilhas();
int pilha_cheia(PilhaCarros* beco);
int pilha_vazia(PilhaCarros* beco);
int empilhar(PilhaCarros* beco, Carro carro);
Carro desempilhar(PilhaCarros* beco);

#endif
