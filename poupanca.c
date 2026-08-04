/*
 * Exercício i) - Projeção de rendimento de poupança (juros compostos)
 *
 * Lê o valor aplicado na poupança, aplica juros de 0,6% ao mês e mostra
 * a evolução mês a mês durante o período informado pelo usuário.
 * Como os juros são compostos, o rendimento de um mês é incorporado
 * ao capital antes de calcular o juro do mês seguinte.
 *
 * Como compilar:
 *   gcc -Wall -o poupanca poupanca.c
 * Como rodar:
 *   ./poupanca
 */

#include <stdio.h>
#include "poupanca.h"



double calcular_capital_final(
        double valor,
        int meses)
{

for(int i=0;i<meses;i++)
{

valor = valor + valor*TAXA_JUROS_MENSAL;

}

return valor;

}



double calcular_rendimento(
        double valor,
        int meses)
{

return calcular_capital_final(valor,meses)-valor;

}



void gerar_relatorio_poupanca(
        double valor,
        int meses,
        char *saida)
{


double final =
calcular_capital_final(valor,meses);


double rendimento =
final-valor;



sprintf(saida,

"Investimento inicial: R$ %.2f\n"
"Periodo: %d meses\n\n"
"Capital final: R$ %.2f\n"
"Rendimento: R$ %.2f",

valor,
meses,
final,
rendimento);


}