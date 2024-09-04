#include "pilha_carros.h"
#include <stdio.h>
#include <string.h>  // Inclua para usar funções de manipulação de strings

PilhaCarros becoA;
PilhaCarros becoB;

// Função para inicializar as pilhas de carros
void inicializar_pilhas(PilhaCarros* pilha) {
    pilha->topo = -1;
}

// Função para verificar se uma pilha está cheia
int pilha_cheia(PilhaCarros* beco) {
    return beco->topo == MAX_CARROS - 1;
}

// Função para verificar se uma pilha está vazia
int pilha_vazia(PilhaCarros* beco) {
    return beco->topo == -1;
}

// Função para adicionar um carro na pilha (no beco)
int empilhar(PilhaCarros* beco, Carro carro) {
    if (pilha_cheia(beco)) {
        printf("Beco cheio! Não é possível adicionar o carro.\n");
        return 0;  // Indica que não foi possível empilhar
    }
    beco->carros[++(beco->topo)] = carro;  // Adiciona o carro à pilha
    return 1;  // Indica sucesso ao empilhar
}

// Função para remover um carro da pilha (do beco)
Carro desempilhar(PilhaCarros* beco) {
    Carro carro_vazio = { "", "", 0, false };  // Carro vazio para retornar se a pilha estiver vazia

    if (pilha_vazia(beco)) {
        printf("Beco vazio! Não há carros para remover.\n");
        return carro_vazio;  // Retorna um carro vazio indicando erro
    }

    return beco->carros[(beco->topo)--];  // Retorna o carro removido
}
