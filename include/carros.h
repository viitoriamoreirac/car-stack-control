#ifndef CARROS_H
#define CARROS_H

#include <stdbool.h>

typedef struct {
    char placa[8];
    char modelo[20]; 
    int manobras;
    bool fila_espera;
} Carro;

void limpar_buffer();
int valida_placa(const char *placa);
Carro criar_carro();
void imprimir_informacoes_carro(Carro carro);

#endif
