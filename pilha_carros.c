#include "pilha_carros.h"
#include <stdio.h>
#include <string.h>


PilhaCarros ruaA;
PilhaCarros ruaB;

void inicializar_pilha(){
    ruaA.topo = -1;
    ruaB.topo = -1;
}

// Função para verificar se uma pilha está cheia
int pilha_cheia(PilhaCarros* rua) {
    return rua->topo == MAX_CARROS - 1;
}

// Função para verificar se uma pilha está vazia
int pilha_vazia(PilhaCarros* rua) {
    return rua->topo == -1;
}

PilhaCarros* push(PilhaCarros* rua, Carro carro) {
    if (pilha_cheia(rua)) {
        printf("Rua cheio! Não é possível adicionar o carro.\n");
        return rua;  // Indica que não foi possível empilhar
    }
    rua->carros[++(rua->topo)] = carro;  // Adiciona o carro à pilha
    return rua;  // Indica sucesso ao empilhar
}