#include "pilha_carros.h"
#include "fila_de_espera.h"
#include "menu.h"

int main() {
    // Inicialize as pilhas e a fila de espera
    inicializar_pilhas(&becoA);
    inicializar_pilhas(&becoB);
    inicializar_fila(&fila);

    // Chama o menu principal
    menu();

    return 0;
}

