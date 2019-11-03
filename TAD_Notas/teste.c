#include<stdio.h> 
#include "teste.h"


void soma(Variaveis* aux, int a, int b){
    (*aux).a = a;
    (*aux).b = b; 
    printf("\nSoma: %d", (*aux).a + (*aux).b);
}

void subtracao(Variaveis* aux, int a, int b){
    (*aux).a = a;
    (*aux).b = b; 
    printf("\nSubtração: %d\n", (*aux).a - (*aux).b);
}