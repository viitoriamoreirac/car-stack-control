#include "../include/carros.h"
#include "../include/pilha_carros.h"
#include "../include/fila_de_espera.h"

#include <regex.h>
#include <stdio.h>
#include <string.h>

void limpar_buffer() {
    int c;
    // Descartar todos os caracteres até encontrar um '\n' ou o fim do arquivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF);
}

int valida_placa(const char *placa) {
    // Validação usando regex
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
        return 0;
    }

    // Verificar se placa já existe no beco A
    for (int i = 0; i <= becoA.topo; i++) {
        if (strcmp(becoA.carros[i].placa, placa) == 0) {
            return 0;
        }
    }

    // Verificar se placa já existe no beco B
    for (int i = 0; i <= becoB.topo; i++) {
        if (strcmp(becoB.carros[i].placa, placa) == 0) {
            return 0;
        }
    }

    // Verificar se placa já existe na fila de espera
    for (int i = 0; i < fila.tamanho; i++) {
        if (strcmp(fila.carros[i].placa, placa) == 0) {
            return 0;
        }
    }

    return 1; // Placa válida e não duplicada
}


Carro criar_carro() {
    Carro novo_carro;
    int placa_valida = 0;  // Variável para controlar a validade da placa

    // Continua pedindo até que a placa seja válida e não duplicada
    while (!placa_valida) {
        printf("Digite a placa do carro (máximo 7 caracteres): ");
        scanf("%7s", novo_carro.placa);
        limpar_buffer();

        if (valida_placa(novo_carro.placa)) {
            placa_valida = 1;  // Placa foi validada
        } else {
            printf("Erro: Placa inválida ou duplicada.\n");
        }
    }

    printf("Digite o modelo do carro (máximo 19 caracteres): ");
    scanf("%19s", novo_carro.modelo);
    limpar_buffer();

    novo_carro.manobras = 0;
    novo_carro.fila_espera = false;

    return novo_carro;
}

void imprimir_informacoes_carro(Carro carro) {
    printf("Carro: %s\n", carro.placa);
    printf("Número de manobras: %d\n", carro.manobras);
    printf("Fila de espera: %s\n", carro.fila_espera ? "Sim" : "Não");
}