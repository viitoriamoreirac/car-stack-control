#ifndef CARROS_H
#define CARROS_H

#include <stdbool.h>

// Estrutura para representar um carro
typedef struct {
    char placa[8];      // Placa do carro (ID)
    char modelo[20];    // Modelo do carro
    int manobras;       // Número de vezes que o carro foi manobrado
    bool fila_espera;   // Indica se o carro ficou na fila de espera (true = sim, false = não)
} Carro;

// Função para receber os dados de um carro pelo terminal
Carro criar_carro();
void imprimir_informacoes_carro(Carro carro);

#endif
