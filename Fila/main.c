#include <stdio.h>
#include <stdlib.h>
#include "fila_encadeada.h"

 int tam = 0;

void imprimirFila(TipoFila Fila)
{
    if (Vazia(Fila))
    {
        printf("Erro fila esta vazia\n");
        return -1;
    }
    int auxiliar;
    TipoItem itemAuxiliar;

    int i, tam;
    tam = Fila.tamanho;
    for (i = 0; i < tam; i++)
    {
        auxiliar = Desenfileira(&Fila);
        itemAuxiliar.Chave = auxiliar;
        printf("%d\n", auxiliar);
        Enfileira(itemAuxiliar, &Fila);
    }
}
void inverso(TipoFila *Fila)
{
    TipoFila novaFila;
    novaFila.tamanho = 0;
    TipoItem itemAuxiliar;

    int i, tam, auxiliar, j;

    for (i = tam; i > 0; i--)
    {
        for (j = i - 1; j > 0; j--)
        {
            auxiliar = Desenfileira(Fila);
            itemAuxiliar.Chave = auxiliar;
            Enfileira(itemAuxiliar, &novaFila);
        }
    }
    imprimirFila(*Fila);
}

void inverso2(TipoFila *Fila)
{
    TipoItem novoItem;
    int tam=Fila->tamanho;
    int aux;
    if (tam != 0)
    {
        tam--;
        aux = Desenfileira(Fila);
        novoItem.Chave = aux;
        inverso2(Fila);
        Enfileira(novoItem, Fila);
    }
        
}
int main(int argc, char *argv[])
{
    TipoFila fila;
    fila.tamanho = 0;
    TipoItem item;
    int i, m;

    for(i=1; i<=9;i++){
        printf("\nDigite o número da matrícula: "); 
        scanf("%d", &m);
        item.Chave = m;
        Enfileira(item, &fila);
    }

    printf("\nEnfileirando a fila com os dígitos da matrícula: \n");
    imprimirFila(fila);

    printf("\n Invertendo a fila: \n");
    inverso2(&fila);
    imprimirFila(fila);

    TipoItem primeiro = primeiroElemetno(fila);
    printf("\nPrimeiro elemento da fila atual: %d\n", primeiro.Chave);

    if(filaCheia(fila))
        printf("\nA fila está cheia\n"); 
    else
        printf("\nAinda há espaço na fila\n");

    printf("\nDesinfileirando a fila atual e imprimindo\n");

     for(i=1; i<=9;i++){
         Desenfileira(&fila);
    }
    imprimirFila(fila);


    
}
