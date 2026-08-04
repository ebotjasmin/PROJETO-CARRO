# 🚗 Sistema Automotivo + 💰 Simulador de Poupança

## 📌 Descrição do Projeto

Este projeto apresenta um protótipo de um sistema de simulação desenvolvido para representar duas funcionalidades principais:

1. **Medidor de consumo de combustível**
2. **Simulador de rendimento de poupança**

A ideia inicial foi desenvolver os algoritmos em linguagem C e posteriormente criar uma interface gráfica simples utilizando HTML, CSS e JavaScript para visualizar o funcionamento do sistema.

O protótipo representa a futura integração entre os algoritmos desenvolvidos em C e uma interface amigável para o usuário.


---

# 🎯 Objetivos

## Medidor de combustível

O sistema permite simular o comportamento de um painel de bordo de qualquer veículo.

Principais funcionalidades:

- Cadastro do modelo do veículo;
- Definição da capacidade do tanque;
- Registro do combustível disponível;
- Registro de quilômetros percorridos;
- Cálculo do consumo médio;
- Estimativa da autonomia restante.


## Simulador de poupança

O sistema realiza uma projeção financeira utilizando juros compostos.

Funcionalidades:

- Entrada do valor inicial aplicado;
- Definição do período em meses;
- Aplicação de juros mensal de 0,6%;
- Cálculo do capital final;
- Cálculo do rendimento acumulado.


---

# 🏗️ Estrutura do Projeto

```
Projeto/
│
├── consumo.c
│   └── Algoritmos do medidor de combustível
│
├── poupanca.c
│   └── Algoritmos de juros compostos
│
├── index.html
│   └── Interface principal
│
├── style.css
│   └── Estilização visual
│
├── script.js
│   └── Controle das interações
│
└── README.md
    └── Documentação do projeto
```


---

# ⚙️ Funcionamento do Sistema


## 1. Inicialização

O usuário acessa a interface principal e escolhe uma funcionalidade.


```
                 INÍCIO
                    |
                    ↓
          Abrir Sistema Automotivo
                    |
                    ↓
          Escolher funcionalidade
              /             \
             /               \
            ↓                 ↓

 Medidor combustível      Poupança

```


---

# 🚗 Fluxograma - Medidor de Combustível


```
                 INÍCIO
                    |
                    ↓
          Informar veículo
                    |
                    ↓
        Informar tanque (Litros)
                    |
                    ↓
      Informar combustível atual
                    |
                    ↓
          Inicializar painel
                    |
                    ↓
        Registrar quilômetros
                    |
                    ↓
       Informar litros gastos
                    |
                    ↓
       Atualizar informações
                    |
                    ↓
    +-----------------------------+
    | Calcular funções principais |
    +-----------------------------+
             |
             |
     ----------------------
     |          |          |
     ↓          ↓          ↓

Consumo    Consumo     Autonomia
motor      últimos     tanque
ligado     10 km


             |
             ↓

        Mostrar resultado

             |
             ↓

            FIM
```


---

# 💰 Fluxograma - Simulador de Poupança


```
              INÍCIO

                 |

                 ↓

       Informar valor inicial

                 |

                 ↓

        Informar quantidade
             de meses

                 |

                 ↓

      Aplicar juros mensal
             (0,6%)

                 |

                 ↓

       Atualizar capital

                 |

                 ↓

        Repetir até atingir
          número de meses

                 |

                 ↓

        Mostrar resultado

                 |

                 ↓

                FIM

```


---

# 🔄 Fluxo geral do projeto


```
              Usuário

                 |

                 ↓

          Interface Web

        HTML + CSS + JS

                 |

                 ↓

       Escolha da função


        /                 \


       ↓                   ↓


 consumo.c          poupanca.c


       ↓                   ↓


Algoritmos       Juros compostos


       ↓                   ↓


 Resultado apresentado

```


---

# 🧮 Principais cálculos


## Consumo médio

```
Consumo = quilômetros percorridos / litros gastos
```


## Autonomia

```
Autonomia = combustível restante × consumo médio
```


## Juros compostos

```
Capital_final = Capital_inicial × (1 + 0,006)^meses
```


---

# 🛠️ Tecnologias utilizadas

- Linguagem C
- HTML5
- CSS3
- JavaScript
- Git/GitHub


---

# 🚀 Como executar o protótipo

1. Baixar ou clonar o projeto:

```
git clone URL_DO_PROJETO
```


2. Abrir o arquivo:

```
index.html
```


3. Executar pelo navegador.


---

# 🔮 Próximas melhorias

- Integrar JavaScript com os algoritmos em C;
- Criar banco de dados para armazenar veículos;
- Criar gráficos de consumo;
- Criar histórico de abastecimentos;
- Criar aplicativo mobile.


---

# 👨‍💻 Autor

Projeto desenvolvido como protótipo de estudo e demonstração de integração entre algoritmos e interface gráfica.