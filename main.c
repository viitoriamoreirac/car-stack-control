#include "pilha_carros.h"
#include "fila_de_espera.h"
#include "menu.h"

int main() {
    inicializar_pilhas(&becoA);
    inicializar_pilhas(&becoB);
    inicializar_fila(&fila);

    menu();
    return 0;
}

