#ifndef CONSUMO_H
#define CONSUMO_H


#define TAM_JANELA_10KM 10


typedef struct {

    char modelo[50];

    double capacidade_tanque;

    double combustivel_restante;


    double km_desde_ligou;
    double litros_desde_ligou;


    double km_desde_abastecimento;
    double litros_desde_abastecimento;


    double janela_litros[TAM_JANELA_10KM];

    int janela_qtd;

    int janela_pos;


    double km_total_rodado;


} Painel;



void inicializar_painel(
        Painel *p,
        const char *modelo,
        double capacidade,
        double litros);



void ligar_motor(Painel *p);



void abastecer(
        Painel *p,
        double litros);



void registrar_km(
        Painel *p,
        double litros);



double consumo_medio_desde_ligou(Painel *p);



double consumo_medio_desde_abastecimento(Painel *p);



double consumo_medio_ultimos_10km(Painel *p);



double autonomia_tanque(Painel *p);



void obter_status(
        Painel *p,
        char *saida);



#endif