#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"
int main(int argc, char *argv[])
{
    ContaBancaria conta1;
    Inicializa(&conta1,918556,300.00);
    printf("\n Antes da movimentacao: \n");
    Imprime(conta1);
    Deposito(&conta1, 50.00);
    Saque(&conta1, 70.00);
    printf("\n Depois da movimentacao: \n");
    Imprime(conta1);
}
