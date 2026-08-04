#include <stdio.h>
#include "consumo.h"
#include "poupanca.h"


int main()
{

Painel p;


inicializar_painel(
&p,
"Toyota Corolla",
50,
40);



registrar_km(&p,0.08);



char texto[500];


obter_status(&p,texto);


printf("%s",texto);



return 0;
}