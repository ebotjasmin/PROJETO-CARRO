/*
 * Exercicio h) - Medidor de consumo de combustivel (versao generica)
 *
 * O programa simula o painel de bordo de QUALQUER automovel: a capacidade
 * do tanque nao e fixa, e informada pelo usuario no inicio (ex: 40L, 55L,
 * 60L, 90L...), assim serve tanto pra um carro popular quanto pra uma
 * picape com tanque grande.
 *
 * O registro de consumo e fornecido a cada 1 km rodado (o usuario informa
 * quantos litros foram gastos naquele km). A partir disso o programa
 * calcula:
 *
 *   a) consumo medio desde que o motor foi ligado pela ultima vez
 *   b) consumo medio desde o ultimo abastecimento
 *   c) consumo medio dos ultimos 10 km rodados, independente do trecho
 *   d) autonomia do tanque (km que ainda da pra rodar com o combustivel
 *      restante), considerando a capacidade do tanque deste carro
 *
 * Consumo medio e expresso em km/litro (quanto maior, mais economico).
 * Autonomia = combustivel restante (L) * consumo medio (km/L)
 *
 * Como compilar:
 *   gcc -Wall -o consumo consumo.c
 * Como rodar:
 *   ./consumo
 */

#include <stdio.h>

#define TAM_JANELA_10KM 10

typedef struct {
    char modelo[50];
    double capacidade_tanque;      /* capacidade do tanque deste carro (L) */
    double combustivel_restante;   /* litros ainda no tanque */

    /* desde que o motor foi ligado */
    double km_desde_ligou;
    double litros_desde_ligou;

    /* desde o ultimo abastecimento */
    double km_desde_abastecimento;
    double litros_desde_abastecimento;

    /* ultimos 10 km, buffer circular */
    double janela_litros[TAM_JANELA_10KM];
    int janela_qtd;      /* quantos km ja registrados (ate 10) */
    int janela_pos;      /* proxima posicao a sobrescrever */

    double km_total_rodado;
} Painel;

/*
 * Inicializa o painel para QUALQUER carro: recebe a capacidade do tanque
 * (dado do veiculo) e quantos litros ele tem agora.
 */
void inicializar_painel(Painel *p, const char *modelo, double capacidade_tanque,
                         double litros_no_tanque) {
    snprintf(p->modelo, sizeof(p->modelo), "%s", modelo);
    p->capacidade_tanque = capacidade_tanque;
    p->combustivel_restante = (litros_no_tanque > capacidade_tanque)
                                   ? capacidade_tanque
                                   : litros_no_tanque;

    p->km_desde_ligou = 0;
    p->litros_desde_ligou = 0;
    p->km_desde_abastecimento = 0;
    p->litros_desde_abastecimento = 0;
    p->janela_qtd = 0;
    p->janela_pos = 0;
    p->km_total_rodado = 0;
    for (int i = 0; i < TAM_JANELA_10KM; i++) p->janela_litros[i] = 0.0;
}

/* liga o motor: zera os contadores do trajeto atual */
void ligar_motor(Painel *p) {
    p->km_desde_ligou = 0;
    p->litros_desde_ligou = 0;
    printf(">> Motor ligado. Contadores de trajeto zerados.\n");
}

/* abastecer: soma litros ao tanque (respeitando a capacidade deste carro)
 * e zera contadores desde o abastecimento */
void abastecer(Painel *p, double litros_abastecidos) {
    p->combustivel_restante += litros_abastecidos;
    if (p->combustivel_restante > p->capacidade_tanque)
        p->combustivel_restante = p->capacidade_tanque;

    p->km_desde_abastecimento = 0;
    p->litros_desde_abastecimento = 0;
    printf(">> Abastecido com %.2f L. Tanque agora com %.2f L de %.1f L.\n",
           litros_abastecidos, p->combustivel_restante, p->capacidade_tanque);
}

/* registra 1 km rodado, informando quantos litros foram gastos nesse km */
void registrar_km(Painel *p, double litros_gastos) {
    if (litros_gastos > p->combustivel_restante) {
        printf(">> Combustivel insuficiente para registrar este km!\n");
        return;
    }

    p->combustivel_restante -= litros_gastos;

    p->km_desde_ligou += 1;
    p->litros_desde_ligou += litros_gastos;

    p->km_desde_abastecimento += 1;
    p->litros_desde_abastecimento += litros_gastos;

    p->km_total_rodado += 1;

    /* atualiza a janela circular dos ultimos 10 km */
    p->janela_litros[p->janela_pos] = litros_gastos;
    p->janela_pos = (p->janela_pos + 1) % TAM_JANELA_10KM;
    if (p->janela_qtd < TAM_JANELA_10KM) p->janela_qtd++;

    printf(">> Km registrado. Gasto: %.3f L. Restam %.2f L no tanque.\n",
           litros_gastos, p->combustivel_restante);
}

/* a) consumo medio desde que ligou o motor (km/L) */
double consumo_medio_desde_ligou(Painel *p) {
    if (p->litros_desde_ligou == 0) return 0.0;
    return p->km_desde_ligou / p->litros_desde_ligou;
}

/* b) consumo medio desde o ultimo abastecimento (km/L) */
double consumo_medio_desde_abastecimento(Painel *p) {
    if (p->litros_desde_abastecimento == 0) return 0.0;
    return p->km_desde_abastecimento / p->litros_desde_abastecimento;
}

/* c) consumo medio dos ultimos 10 km (km/L) */
double consumo_medio_ultimos_10km(Painel *p) {
    double soma_litros = 0.0;
    for (int i = 0; i < p->janela_qtd; i++) soma_litros += p->janela_litros[i];
    if (soma_litros == 0 || p->janela_qtd == 0) return 0.0;
    return p->janela_qtd / soma_litros;
}

/*
 * d) autonomia do tanque com o combustivel restante, usando a capacidade
 * de tanque DESTE carro (nao um valor fixo).
 * Usa o consumo medio desde o ultimo abastecimento como referencia,
 * por ser o historico mais representativo do uso atual do tanque.
 */
double autonomia_tanque(Painel *p) {
    double consumo_medio = consumo_medio_desde_abastecimento(p);
    if (consumo_medio == 0.0) return 0.0;
    return p->combustivel_restante * consumo_medio;
}

void mostrar_status(Painel *p) {
    printf("\n----- STATUS DO PAINEL (%s) -----\n", p->modelo);
    printf("Combustivel no tanque: %.2f L (de %.1f L)\n",
           p->combustivel_restante, p->capacidade_tanque);
    printf("Km total rodado: %.0f km\n", p->km_total_rodado);
    printf("a) Consumo medio desde que ligou o motor: %.3f km/L\n",
           consumo_medio_desde_ligou(p));
    printf("b) Consumo medio desde o ultimo abastecimento: %.3f km/L\n",
           consumo_medio_desde_abastecimento(p));
    printf("c) Consumo medio dos ultimos %d km: %.3f km/L\n",
           p->janela_qtd, consumo_medio_ultimos_10km(p));
    printf("d) Autonomia estimada do tanque: %.2f km\n", autonomia_tanque(p));
    printf("-----------------------------------\n\n");
}

int main(void) {
    Painel painel;
    int opcao;
    double valor, capacidade;
    char modelo[50];

    /* Dados do veiculo -- e aqui que o programa deixa de ser fixo em
     * um unico carro e passa a funcionar pra qualquer um */
    printf("===== CONFIGURACAO DO VEICULO =====\n");
    printf("Modelo/apelido do carro: ");
    scanf(" %49[^\n]", modelo);

    printf("Capacidade do tanque deste carro (L): ");
    scanf("%lf", &capacidade);
    if (capacidade <= 0) {
        printf("Capacidade invalida.\n");
        return 1;
    }

    printf("Quantos litros o tanque tem agora (max %.1f): ", capacidade);
    scanf("%lf", &valor);

    inicializar_painel(&painel, modelo, capacidade, valor);

    do {
        printf("\n===== MEDIDOR DE CONSUMO - %s =====\n", painel.modelo);
        printf("1 - Ligar motor (novo trajeto)\n");
        printf("2 - Abastecer\n");
        printf("3 - Registrar km rodado (informar litros gastos)\n");
        printf("4 - Mostrar status / consumos / autonomia\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ligar_motor(&painel);
                break;
            case 2:
                printf("Litros abastecidos: ");
                scanf("%lf", &valor);
                abastecer(&painel, valor);
                break;
            case 3:
                printf("Litros gastos neste km: ");
                scanf("%lf", &valor);
                registrar_km(&painel, valor);
                break;
            case 4:
                mostrar_status(&painel);
                break;
            case 0:
                printf("Encerrando.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}

void obter_status(Painel *p, char *saida)
{

sprintf(saida,

"Veiculo: %s\n\n"
"Tanque: %.2f L / %.2f L\n"
"Km total: %.0f km\n\n"

"Consumo desde motor: %.2f km/L\n"
"Consumo abastecimento: %.2f km/L\n"
"Ultimos 10 km: %.2f km/L\n\n"

"Autonomia: %.2f km",

p->modelo,

p->combustivel_restante,

p->capacidade_tanque,

p->km_total_rodado,


consumo_medio_desde_ligou(p),

consumo_medio_desde_abastecimento(p),

consumo_medio_ultimos_10km(p),

autonomia_tanque(p)

);

}