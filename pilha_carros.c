#include "pilha_carros.h"
#include <stdio.h>
#include <string.h>

PilhaCarros becoA;
PilhaCarros becoB;

void inicializar_pilhas(PilhaCarros* pilha) {
    pilha->topo = -1;
}

int pilha_cheia(PilhaCarros* beco) {
    return beco->topo == MAX_CARROS - 1;
}

int pilha_vazia(PilhaCarros* beco) {
    return beco->topo == -1;
}

int empilhar(PilhaCarros* beco, Carro carro) {
    if (pilha_cheia(beco)) {
        printf("Beco cheio! Não é possível adicionar o carro.\n");
        return 0;  // Indica que não foi possível empilhar
    }
    beco->carros[++(beco->topo)] = carro;  // Adiciona o carro à pilha
    return 1;  // Indica sucesso ao empilhar
}


Carro desempilhar(PilhaCarros* beco) {
    Carro carro_vazio = { "", "", 0, false };  // Carro vazio para retornar se a pilha estiver vazia

    if (pilha_vazia(beco)) {
        printf("Beco vazio! Não há carros para remover.\n");
        return carro_vazio;  // Retorna um carro vazio indicando erro
    }

    return beco->carros[(beco->topo)--];  // Retorna o carro removido
}
