#ifndef POUPANCA_H
#define POUPANCA_H


#define TAXA_JUROS_MENSAL 0.006



double calcular_rendimento(
        double valor,
        int meses);



double calcular_capital_final(
        double valor,
        int meses);



void gerar_relatorio_poupanca(
        double valor,
        int meses,
        char *saida);



#endif