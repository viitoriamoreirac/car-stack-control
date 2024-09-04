#include "carros.h"
#include "pilha_carros.h"
#include "fila_de_espera.h"

#include <regex.h>
#include <stdio.h>
#include <string.h>


int valida_placa(const char *placa) {
    // Validação do formato da placa usando regex
    regex_t regex;
    int retorno_regex;
    const char *padrao = "^[A-Z]{3}[0-9][0-9A-Z][0-9]{2}$";

    retorno_regex = regcomp(&regex, padrao, REG_EXTENDED | REG_NOSUB);
    if (retorno_regex) {
        printf("Erro ao compilar regex.\n");
        return 0;
    }

    retorno_regex = regexec(&regex, placa, 0, NULL, 0);
    regfree(&regex);

    if (retorno_regex == REG_NOMATCH) {
        printf("Placa inválida.\n");
        return 0;
    }

    // Verificação se a placa já existe no beco A
    for (int i = 0; i < becoA.topo; i++) {
        if (strcmp(becoA.carros[i].placa, placa) == 0) {
            printf("Carro %s já está no beco A.\n", placa);
            return 0;
        }
    }

    // Verificação se a placa já existe no beco B
    for (int i = 0; i < becoB.topo; i++) {
        if (strcmp(becoB.carros[i].placa, placa) == 0) {
            printf("Carro %s já está no beco B.\n", placa);
            return 0;
        }
    }

    // Verificação se a placa já existe na fila de espera
    for (int i = 0; i < fila.tamanho; i++) {
        if (strcmp(fila.carros[i].placa, placa) == 0) {
            printf("Carro %s já está na fila de espera.\n", placa);
            return 0;
        }
    }

    return 1; // Placa válida e não duplicada
}


// Função para receber os dados de um carro pelo terminal
Carro criar_carro() {
    Carro novo_carro;

    // Solicita a placa do carro
    printf("Digite a placa do carro (máximo 7 caracteres): ");
    scanf("%7s", novo_carro.placa);
    // Limpa o buffer de entrada
    while(getchar() != '\n');

    if (valida_placa(novo_carro.placa)) {
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

        } else {
            printf("Erro: Placa inválida ou duplicada.\n");
        }
    }


void imprimir_informacoes_carro(Carro carro) {
    printf("Carro: %s\n", carro.placa);
    printf("Número de manobras: %d\n", carro.manobras);
    printf("Fila de espera: %s\n", carro.fila_espera ? "Sim" : "Não");
}