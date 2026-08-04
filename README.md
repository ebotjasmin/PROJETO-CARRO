# PROJETO-CARRO

Exercícios de Algoritmos em C
Resolução em linguagem C de dois exercícios de uma lista de algoritmos.
h) Medidor de consumo de combustível (difícil)
Pasta: h_consumo_combustivel/consumo.c
Simula o painel de um automóvel. O consumo é informado a cada km rodado

(litros gastos naquele km) e o programa calcula:
·	a) consumo médio desde que o motor foi ligado pela última vez
·	b) consumo médio desde o último abastecimento
·	c) consumo médio dos últimos 10 km rodados, independente do trecho
·	d) autonomia do tanque (km restantes), considerando tanque de 55 L
Consumo é expresso em km/L. A autonomia usa o consumo médio desde o

último abastecimento como referência, por ser o dado mais representativo

do uso atual do tanque.
Compilar e rodar:
cd h_consumo_combustivel
gcc -Wall -o consumo consumo.c
./consumo

Menu interativo:
1 - Ligar motor (novo trajeto)
2 - Abastecer
3 - Registrar km rodado (informar litros gastos)
4 - Mostrar status / consumos / autonomia
0 - Sair

i) Poupança com juros compostos (médio)
Pasta: i_poupanca_juros_compostos/poupanca.c
Lê o valor aplicado numa poupança e o número de meses desejado, aplica

juros de 0,6% ao mês (compostos — o rendimento de cada mês é incorporado

ao capital antes do cálculo do mês seguinte) e mostra a evolução mês a

mês.
Compilar e rodar:
cd i_poupanca_juros_compostos
gcc -Wall -o poupanca poupanca.c
./poupanca

Estrutura do repositório
.
├── h_consumo_combustivel/
│   └── consumo.c
├── i_poupanca_juros_compostos/
│   └── poupanca.c
├── .gitignore
└── README.md

