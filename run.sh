gcc src/carros.c src/fila_de_espera.c src/main.c src/menu.c src/pilha_carros.c -o bin/executar

if [ $? -eq 0 ]; then
    ./bin/executar
else
    echo "Erro na compilação."
fi