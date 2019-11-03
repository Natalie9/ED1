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


void Enfileira(TipoItem x, TipoFila *Fila);

int Desenfileira(TipoFila *Fila);
int Vazia(TipoFila Fila);
TipoItem primeiroElemetno(TipoFila Fila);
void FFVazia(TipoFila *Fila);