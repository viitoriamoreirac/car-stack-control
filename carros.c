#include "carros.h"
#include <stdio.h>
#include <string.h>

// Função para receber os dados de um carro pelo terminal
Carro criar_carro() {
    Carro novo_carro;

    // Solicita a placa do carro
    printf("Digite a placa do carro (máximo 7 caracteres): ");
    scanf("%7s", novo_carro.placa);
    // Limpa o buffer de entrada
    while(getchar() != '\n');

    // Solicita o modelo do carro
    printf("Digite o modelo do carro (máximo 19 caracteres): ");
    scanf("%19s", novo_carro.modelo);
    // Limpa o buffer de entrada
    while(getchar() != '\n');

    // Inicializa o número de manobras como 0
    novo_carro.manobras = 0;

    // Inicializa a fila de espera como false
    novo_carro.fila_espera = false;

    return novo_carro;
}

void imprimir_informacoes_carro(Carro carro) {
    printf("Carro: %s\n", carro.placa);
    printf("Número de manobras: %d\n", carro.manobras);
    printf("Fila de espera: %s\n", carro.fila_espera ? "Sim" : "Não");
}