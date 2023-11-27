#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0
#define TOP 1
#define BASE 0

typedef struct
{
    unsigned long int *elementos;
    long int tamanho;
    long int capacidade;
} Pilha;

int create(Pilha *P, long int capacidade)
{
    P->elementos = (unsigned long int *)malloc(capacidade * sizeof(unsigned long int));

    if (P->elementos == NULL)
    {
        return FALHA;
    }

    P->tamanho = 0;
    P->capacidade = capacidade;

    return SUCESSO;
}

int isEmpty(Pilha *P)
{
    return (P->tamanho == 0);
}

int push(Pilha *P, unsigned long int x)
{
    if (P->tamanho == P->capacidade)
    {
        return FALHA;
    }

    P->elementos = (unsigned long int *)realloc(P->elementos, sizeof(unsigned long int) + 1);
    if (P->elementos == NULL)
    {
        return FALHA;
    }

    P->elementos[P->tamanho] = x;
    P->tamanho++;

    return SUCESSO;
}

unsigned long int pop(Pilha *P)
{
    if (isEmpty(P))
    {
        return FALHA;
    }

    P->elementos = (unsigned long int *)realloc(P->elementos, sizeof(unsigned long int) - 1);
    unsigned long int elemento = P->elementos[P->tamanho - 1];
    P->tamanho--;

    return elemento;
}

long int size(Pilha *P)
{
    return P->tamanho;
}

int isEqual(Pilha *P1, Pilha *P2)
{
    if (P1->tamanho != P2->tamanho)
    {
        return FALSE;
    }

    for (long int i = 0; i < P1->tamanho; i++)
    {
        if (P1->elementos[i] != P2->elementos[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}

void show(Pilha *P, int ordem)
{
    if (ordem == TOP)
    {
        for (long int i = P->tamanho - 1; i >= 0; i--)
        {
            printf("%lu\n", P->elementos[i]);
        }
    }
    else if (ordem == BASE)
    {
        for (long int i = 0; i < P->tamanho; i++)
        {
            printf("%lu\n", P->elementos[i]);
        }
    }
}

int copy(Pilha *P1, Pilha *P2)
{
    if (P1->tamanho > P2->capacidade)
    {
        P2->capacidade = P1->tamanho;
        P2->elementos = (unsigned long int *)realloc(P2->elementos, P2->capacidade * sizeof(unsigned long int));

        if (P2->elementos == NULL)
        {
            return FALHA;
        }
    }

    P2->tamanho = P1->tamanho;

    for (long int i = 0; i < P1->tamanho; i++)
    {
        P2->elementos[i] = P1->elementos[i];
    }

    return SUCESSO;
}

int main()
{
    Pilha pilhaA, pilhaB;
    long int capacidade = 5; // Exemplo inicial de capacidade

    if (create(&pilhaA, capacidade) == FALHA || create(&pilhaB, capacidade) == FALHA)
    {
        printf("Falha ao criar as pilhas.\n");
        return 1;
    }

    int opcao;
    unsigned long int elemento;

    do
    {
        printf("\n*** Menu de Operações ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. isEqual\n");
        printf("5. Show\n");
        printf("6. Copy\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a ser inserido: ");
            scanf("%lu", &elemento);
            if (push(&pilhaA, elemento) == FALHA)
            {
                printf("Falha ao inserir elemento na pilha.\n");
            }
            break;

        case 2:
            if (!isEmpty(&pilhaA))
            {
                elemento = pop(&pilhaA);
                printf("Elemento removido: %lu\n", elemento);
            }
            else
            {
                printf("A pilha está vazia.\n");
            }
            break;

        case 3:
            printf("Tamanho da pilha: %ld\n", size(&pilhaA));
            break;

        case 4:
            if (isEqual(&pilhaA, &pilhaB))
            {
                printf("As pilhas são iguais.\n");
            }
            else
            {
                printf("As pilhas não são iguais.\n");
            }
            break;

        case 5:
            printf("Mostrar pilha (TOPO ou BASE): ");
            int ordem;
            scanf("%d", &ordem);
            show(&pilhaA, ordem);
            break;

        case 6:
            if (copy(&pilhaA, &pilhaB) == FALHA)
            {
                printf("Falha ao copiar pilha.\n");
            }
            else
            {
                printf("Pilha copiada com sucesso.\n");
            }
            break;

        case 0:
            printf("Encerrando o programa. Obrigado!\n");
            break;

        default:
            printf("Opção inválida. Escolha novamente.\n");
        }

    } while (opcao != 0);

    free(pilhaA.elementos);
    free(pilhaB.elementos);

    return 0;
}