#include <stdio.h>
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct {
    int *elementos;
    int tamanho;
} Conjunto;

int insereElementoConjunto(int x, Conjunto *C)
{
    for (int i = 0, tamanhoConjunto = C->tamanho; i < tamanhoConjunto; i++)
    {
        if (C->elementos[i] == x)
        {
            printf("O elemento já está no conjunto!\n");
            
            return FALHA;
        }
    }
    
}

int main()
{
    Conjunto C;
    C.elementos[0] = 2;
    C.tamanho = 1;
    insereElementoConjunto(2, &C);

    return 0;
}