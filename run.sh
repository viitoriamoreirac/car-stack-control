gcc carros.c fila_de_espera.c main.c menu.c pilha_carros.c -o executar

if [ $? -eq 0 ]; then
    ./executar
else
    echo "Erro na compilação."
fi