/*  Estudante: Natalie Tolentino Serafim 
    Matrícula: 201802697
    Turma: A
    Disciplina: Estrutura de Dados 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    int CPF;
    char nome[40];
    double notas[3];

} Aluno;

int main()
{
    lerEntradas();

    return 0;
}

void lerEntradas()
{

    int n, i;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    Aluno *a = (Aluno *)malloc(n * sizeof(Aluno));

    for (i = 0; i < n; i++)
    {

        printf("\t\n\nAluno %i: \n\nDigite seu nome:", i + 1);
        scanf("%s", &a[i].nome);

        printf("\nCPF:");
        scanf("%i", &a[i].CPF);

        printf("\nDigite a Nota 1: ");
        scanf("%lf", &a[i].notas[0]);

        printf("\nDigite a Nota 2: ");
        scanf("%lf", &a[i].notas[1]);

        printf("\nDigite a Nota 3: ");
        scanf("%lf", &a[i].notas[2]);
    }

    imprimir_dados(a, n);
}

void calcular_media(Aluno *a, int n, int i)
{
    double media;

    media = (a[i].notas[0] + a[i].notas[1] + a[i].notas[2]) / 3;
    printf("\n A média final é de %.2f", media);
    if (media >= 7.0)
    {
        printf("\tAPROVADO\n");
    }
    else if (media < 3.0)
    {
        printf("\tREPROVADO\n");
    }
    else if ((media >= 3.0) && (media < 7.0))
    {
        printf("\tPROVA FINAL\n");
    }
}

void imprimir_dados(Aluno *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n Nome: %s \n CPF: %i \n Notas: %.2f - %.2f - %.2f", a[i].nome, a[i].CPF, a[i].notas[0], a[i].notas[1], a[i].notas[2]);
        calcular_media(a, n, i);
    }
}