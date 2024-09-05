#include "menu.h"
#include "pilha_carros.h"
#include "carros.h"
#include "fila_de_espera.h"
#include <stdio.h>
#include <string.h>


void adicionar_carro() {
    Carro novo_carro = criar_carro();

    if (!pilha_cheia(&becoA)) {
        empilhar(&becoA, novo_carro);
        printf("Carro %s adicionado ao Beco A.\n", novo_carro.placa);
    } else if (!pilha_cheia(&becoB)) {
        empilhar(&becoB, novo_carro);
        printf("Carro %s adicionado ao Beco B.\n", novo_carro.placa);
    } else {
        printf("Estacionamento cheio! Deseja entrar na fila de espera? (1 = Sim, 0 = Não): ");
        int escolha;
        scanf("%d", &escolha);
        if (escolha == 1) {
            novo_carro.fila_espera = true;
            if (enfileirar(&fila, novo_carro)) {
                printf("Carro %s adicionado à fila de espera.\n", novo_carro.placa);
            }
        } else {
            printf("Carro %s não foi adicionado ao estacionamento.\n", novo_carro.placa);
        }
    }
}

void imprimir_becos() {
    printf("\n--- Estado dos Becos ---\n");

    printf("Beco A:\n");
    for (int i = 0; i <= becoA.topo; i++) {
        printf("Posição %d: %s\n", i, becoA.carros[i].placa);
    }

    printf("Beco B:\n");
    for (int i = 0; i <= becoB.topo; i++) {
        printf("Posição %d: %s\n", i, becoB.carros[i].placa);
    }
    printf("-------------------------\n\n");
}

void remover_carro() {
    char placa[8];
    printf("Digite a placa do carro a ser removido: ");
    scanf("%7s", placa);
    while (getchar() != '\n'); // Limpar buffer de entrada

    int encontrou = 0; 
    PilhaCarros* beco_alvo = NULL;  // Beco onde o carro foi encontrado
    PilhaCarros temp_pilha;  // Pilha temporária para armazenar os carros removidos temporariamente
    inicializar_pilhas(&temp_pilha);

    imprimir_becos();

    // Procura no Beco A
    for (int i = 0; i <= becoA.topo; i++) {
        if (strcmp(becoA.carros[i].placa, placa) == 0) {
            encontrou = 1;
            beco_alvo = &becoA;
            break;
        }
    }

    // Se não encontrar no Beco A, procura no Beco B
    if (!encontrou) {
        for (int i = 0; i <= becoB.topo; i++) {
            if (strcmp(becoB.carros[i].placa, placa) == 0) {
                encontrou = 1;
                beco_alvo = &becoB;
                break;
            }
        }
    }

    if (encontrou) {
        // Desempilha carros até encontrar o carro alvo
        while (beco_alvo->topo >= 0 && strcmp(beco_alvo->carros[beco_alvo->topo].placa, placa) != 0) {
            Carro temp_carro = desempilhar(beco_alvo);
            temp_carro.manobras++;
            empilhar(&temp_pilha, temp_carro);
            printf("Carro %s foi manobrado.\n", temp_carro.placa);
        }

        // Remove o carro alvo
        if (beco_alvo->topo >= 0 && strcmp(beco_alvo->carros[beco_alvo->topo].placa, placa) == 0) {
            Carro carro_removido = desempilhar(beco_alvo);
            imprimir_informacoes_carro(carro_removido);
            printf("Carro %s removido com sucesso.\n", placa);
        } else {
            printf("Erro: Não foi possível encontrar o carro no topo da pilha.\n");
            return;
        }

        // Recoloca os carros na pilha original
        while (temp_pilha.topo >= 0) {
            Carro temp_carro = desempilhar(&temp_pilha);
            empilhar(beco_alvo, temp_carro);
        }

        // Verifica a fila de espera
        if (!fila_vazia(&fila)) {
            Carro carro_fila = desenfileirar(&fila);
            carro_fila.manobras++;
            empilhar(beco_alvo, carro_fila);
            printf("Carro %s movido da fila de espera para o beco.\n", carro_fila.placa);
        }
    } else {
        printf("Carro com placa %s não encontrado no estacionamento.\n", placa);
    }
}

void menu() {
    int opcao;

    do {
        printf("\n--- Menu de Estacionamento ---\n");
        printf("1. Adicionar Carro\n");
        printf("2. Remover Carro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_carro();
                break;
            case 2:
                remover_carro();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
