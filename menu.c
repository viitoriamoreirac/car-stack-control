#include "menu.h"

#include <stdio.h>
#include <string.h>




void inicializar_menu() {
    int opcao;

    do {
        printf("\n------ Menu de Estacionamento ------\n");
        printf("1. Adicionar Carro\n");
        printf("2. Remover Carro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("-----------------------------------------");

        switch (opcao) {
            case 1:
                printf("teste opção 1");
                break;
            case 2:
                printf("teste opção 2");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}