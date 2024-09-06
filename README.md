# Controle de pilha de carros

Este programa foi construído por [Vitória Cabral](github.com/viitoriamoreirac) como forma de obtenção de nota na matéria de **Estrutura de Dados**, lecionada pela professora **Cledja Rolim** e simula um *sistema de gerenciamento de duas pilhas de carros em um estacionamento* que controla os carros que estão estacionados, gerencia fila de espera e também traz informações sobre quantidade de manobras feitas em cada carro e se foi necessário aguardar na fila de espera ou não.

### Situação problema:

Um estacionamento é composto por dois becos que guarda até 10 carros cada. Existe apenas uma entrada/saída para acessar cada beco. Se chegar um cliente para retirar um carro que não seja o que está na saída, todos os carros bloqueando seu caminho sairão do estacionamento, o carro é removido, e os outros carros voltam para mesma sequência. O programa deverá informar toda vez que um carro entrar ou sair.
Quando um carro chegar, o programa deverá informar se tem ou não vaga e em qual beco. Se não houver vaga, o usuário pode escolher se quer ou não ficar numa fila de espera. Quando abrir vaga, os carros que estão na fila, serão alocados no beco que houver vaga. Quando o carro sair, o programa deverá informar quantas vezes o carro foi manobrado, se ele ficou na fila de espera.

### Os requisitos para avaliação são:

1. Uso da linguagem C;
2. Uso de pilhas;
3. Mini tutorial explicando funcionamento;
4. Justificativa das estruturas utilizadas;
5. Modularidade de código, documentação, adequação e eficiência;

## Como rodar o projeto? 
#### Certifique-se de que o script run.sh tenha permissões de execução. Se não tiver, defina com o comando:
  ```bash
  chmod +x run.sh
  ```
#### Execute o script para compilar e rodar o programa:
  ```bash
  ./run.sh
  ```

## Funcionamento do programa

### Menu Principal

Quando o programa é iniciado, o menu principal é exibido com as seguintes opções:

1. Adicionar carro
2. Remover carro
3. Consultar ocupação do estacionamento e fila de espera
4. Sair

#### 1. Adicionar carro
Esta opção chama a função adicionar_carro(), que permite ao usuário inserir um novo carro no estacionamento. O programa solicitará a placa do carro, que será validada pela função valida_placa(). Caso a placa seja válida e não esteja duplicada nos becos ou na fila de espera, o carro será inserido no primeiro beco disponível. Se ambos os becos estiverem cheios, o carro será adicionado à fila de espera. Caso a placa seja inválida ou duplicada, o carro não será adicionado.

* *As placas são validadas por meio de um REGEX, então para facilitar os testes, recomendo utilizar os exemplos de placas [geradas](https://www.4devs.com.br/gerador_de_placa_automoveis) que estão dispostas abaixo:*

  NEH0446 MXF2596 LSD3686 NEL3815 NAJ0187 JUH5229 JZJ0454 MIL5822 MLH0045 LKG6604 JJE4342 JUT2170 MGG9835 EWH7499 MUH3123 HZZ8936 ILR9975 MST6396 FLM4023 LZT3505 HZU2771 LBH7820 MVB9079 JYH0912 MXD3534

* *Novamente, visando facilitar os testes, recomendo realizar a alteração do número máximo de carros no beco, dentro do arquivo `include/pilha_carros.h`, assim é possível testar a fila de espera inserindo menos carros nos becos.*
  ```c
  #define MAX_CARROS 2
  ```

#### 2. Remover carro
Esta opção chama a função remover_carro(), que permite remover um carro de um dos becos. O usuário deverá fornecer a placa do carro a ser removido. Se o carro estiver em um dos becos, ele será removido e, caso haja carros na fila de espera, o primeiro da fila será movido para o beco liberado. Os carros que estiverem bloqueando a passagem do carro alvo, serão adicionados em uma pilha temporária para após a remoção do carro alvo, serem reempilhados no beco de origem. A função também incrementa a quantidade de manobras que os carros sofrem.

#### 3. Consultar ocupação do estacionamento e fila de espera
Esta opção chama a função exibir_ocupacao(), que exibe o estado atual dos dois becos e da fila de espera. Para cada carro estacionado nos becos, a função mostra sua posição e sua placa. Além disso, todos os carros na fila de espera são listados em ordem, da frente até o final da fila.

#### 4. Sair
Esta opção encerra a execução do programa sem se importar com os carros que ainda estão nos becos. Todos os dados são perdidos ao finalizar a execução, pois o programa não mantém estado persistente entre execuções.

## Estrutura do projeto

```bash
  /car-stack-control
├── /bin
│   └── executar
├── /include
│   ├── carros.h
│   ├── fila_de_espera.h
│   ├── menu.h
│   └── pilha_carros.h
├── /src
│   ├── carros.c
│   ├── fila_de_espera.c
│   ├── main.c
│   ├── menu.c
│   └── pilha_carros.c
├── LICENSE
├── run.sh
├── .gitignore
└── README.md
```
  ### Estruturas utilizadas

1. Carro: estrutura responsável por armazenar as informações essenciais de cada veículo que passa pelo estacionamento, permitindo fácil rastreamento das manobras e status de fila de espera.
```c
typedef struct {
    char placa[8];
    char modelo[20]; 
    int manobras;
    bool fila_espera;
} Carro;
```

2. PilhaCarros: estrutura que gerencia a pilha de carros em cada beco do estacionamento. Utiliza o conceito de LIFO (último a entrar, primeiro a sair) para organizar a entrada e saída dos carros.
```c
  typedef struct {
      Carro carros[MAX_CARROS];
      int topo;
  } PilhaCarros;
```

3. FilaEspera: estrutura que implementa a fila de espera quando os becos estão cheios. Utiliza o conceito FIFO (primeiro a entrar, primeiro a sair) para a gestão dos carros em espera.
```c
  typedef struct {
      Carro carros[MAX_FILA_ESPERA];
      int frente;
      int tras;
      int tamanho;
  } FilaEspera;
  ```

