#include <stdio.h>
#include <stdlib.h>
#include "fila_encadeada.h"

typedef struct TipoCelula *TipoApontador;
typedef int TipoChave;

typedef struct TipoItem
{
    TipoChave Chave;
    
} TipoItem;
typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;
typedef struct TipoFila
{
    int tamanho;
    TipoApontador Frente, Tras;
} TipoFila;

int Vazia(TipoFila Fila)
{
    //retorna 1 pra vazia
    return (Fila.tamanho == 0);
}
void Enfileira(TipoItem x, TipoFila *Fila)
{

    if (Vazia(*Fila))
    {
        Fila->Frente = (TipoApontador)malloc(sizeof(TipoCelula));
        Fila->Frente->Item = x;
        Fila->Tras = Fila->Frente;
        Fila->Frente->Prox = NULL;
        Fila->tamanho++;
    }
    else if(filaCheia(* Fila)){
        printf("\nErro, novo elemento não iserido. Fila cheia\n");
    }
    else
    {
        Fila->Tras->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
        Fila->Tras = Fila->Tras->Prox;
        Fila->Tras->Item = x;
        Fila->Tras->Prox = NULL;
        Fila->tamanho++;
    }
}
int Desenfileira(TipoFila *Fila)
{
    int q;
    if (Vazia(*Fila))
    {
        printf("Erro fila esta vazia\n");
        return -1;
    }

    q = Fila->Frente->Item.Chave;
    free((Fila->Frente));
    Fila->Frente = Fila->Frente->Prox;
    Fila->tamanho--;
    return q;
}


int filaCheia(TipoFila Fila){

    if(Fila.tamanho==9)
        return 1; 
    else 
        return 0;     
}

TipoItem primeiroElemetno(TipoFila Fila){
    return Fila.Frente->Item;
}
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