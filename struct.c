#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


typedef struct Pessoa{
    char CPF [12];
	char nome[30];
	char dataNascimento[11];
	
	
} Pessoa;

void insere(int n, Pessoa** pessoas);
void inicialize(int n, Pessoa** pessoas);
void imprime(int n, Pessoa** pessoas);
void deleta(int n, Pessoa** pessoas);

int main(){
	Pessoa *b = (Pessoa *)malloc(sizeof(Pessoa));		
	
	
  	int n;
  
  	printf("Informe um numero entre 1 e 100\n");
	scanf("%d", &n);
  
    Pessoa **pessoas = (Pessoa *)malloc(n * sizeof(Pessoa));
    
   inicialize(n, pessoas);
    imprime(n, pessoas);
    insere(n, pessoas);
    imprime(n, pessoas);
    deleta(n, pessoas);
    
    return 0;
}

void inicialize(int n, Pessoa** pessoas){
	int i;
	for(i=0; i<n; i++){
		pessoas[i]= "0"; 
	}
	printf("Vetor inicializado \n");
	
}

void insere(int n, Pessoa** pessoas){

	int i;
	for(i=0; i<n; i++){
		printf("Pessoa %d insira seus dados: ", i+1);
		printf("\nCPF: ");
		
		scanf("%s", pessoas[i]->CPF);
		printf("%s", pessoas[i]->CPF);
		
		printf("\nNome: ");
		scanf("%s", pessoas[i]->nome);
		
		printf("\nData de nascimento (dd/mm/aaaa): ");
		scanf("%s", pessoas[i]->dataNascimento);
		}
	
}

void imprime(int n, Pessoa** pessoas){
	int i;
	for(i=0; i<n; i++){
		printf("Dados da pessoa %d ", i+1);
		printf("\nCPF: %s", pessoas[i]->CPF);
		printf("\nNome: %s", pessoas[i]->nome);
		printf("\nData de nascimento: %s", pessoas[i]->dataNascimento);
		
		
	}
}	

void deleta(int n, Pessoa** pessoas){
	if(pessoas){
		int i;
		for(i=0; i<n; i++){
			if(pessoas[i]){
			 free(pessoas[i]);	
		}
			
		}
		 free(pessoas);
	 printf("\nFoi liberado a memoria de %d registros dinamicos", n);
	}
}