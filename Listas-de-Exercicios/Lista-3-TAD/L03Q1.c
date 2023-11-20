#include <stdio.h>
#include <limits.h>
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

int criaConjunto(Conjunto *C)
{
    if (C == NULL)
    {
        return FALHA;
    }

    C->tamanho = 0;

    return SUCESSO;
}

int conjuntoVazio(Conjunto *C)
{
    if (C->tamanho == 0)
    {
        return TRUE;
    }

    return FALSE;
}

int insereElementoConjunto(int x, Conjunto *C)
{
    int i, tamanhoConjunto = C->tamanho;

    for (i = 0; i < tamanhoConjunto; i++)
    {
        if (C->elementos[i] == x)
        {
            printf("O elemento já está no conjunto!\n");
            
            return FALHA;
        }
    }

    C->elementos[i] = x;

    if (C->elementos[i] == NULL)
    {
        printf("Não foi possível adicionar o elemento %d ao conjunto!\n", x);
        return FALHA;
    }
    
    C->tamanho++;

    return SUCESSO;
}

int excluirElementoConjunto(int x, Conjunto *C)
{
    int i, j, tamanhoConjunto = C->tamanho;

    for (i = 0; i < tamanhoConjunto; i++)
    {
        if (C->elementos[i] == x)
        {
            for (j = i; j < tamanhoConjunto - 1; j++)
            {
                C->elementos[j] = C->elementos[j + 1];
            }

            C->elementos[j] == NULL;
            C->tamanho--;

            return SUCESSO;
        }
    }

    printf("O elemento %d não pertence ao conjunto para ser excluído!\n", x);
    
    return FALHA;
}

int tamanhoConjunto(Conjunto *C)
{
    return C->tamanho;
}

int maior(int x, Conjunto *C)
{
    int qtdeMaiores = 0;

    for (int i = 0; i < C->tamanho; i++)
    {
        if (C->elementos[i] > x)
        {
            qtdeMaiores++;
        }
    }

    return qtdeMaiores;
}

int menor(int x, Conjunto *C)
{
    int qtdeMenores = 0;

    for (int i = 0; i < C->tamanho; i++)
    {
        if (C->elementos[i] < x)
        {
            qtdeMenores++;
        }
    }

    return qtdeMenores;
}

int pertenceConjunto(int x, Conjunto *C)
{
    for (int i = 0; i < C->tamanho; i++)
    {
        if (C->elementos[i] == x)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// Função própria para ajudar na lógica de algumas das questões
int OrdenarConjunto(int *C, int tamanhoConjunto)
{
    int aux;

    for (int i = 0; i < tamanhoConjunto; i++)
    {
        for (int j = i + 1; j < tamanhoConjunto; j++)
        {
            if (C[i] > C[j])
            {
                aux = C[i];
                C[i] = C[j];
                C[j] = aux;
            }
        }
    }
}

int conjuntosIdenticos(Conjunto *C1, Conjunto *C2)
{
    if (C1->tamanho != C2->tamanho)
    {
        return FALSE;
    }
    else
    {
        int tamanhoConjuntos = C1->tamanho;
        int C1_Ordenado[tamanhoConjuntos], C2_Ordenado[tamanhoConjuntos];

        for (int i = 0; i < tamanhoConjuntos; i++)
        {
            C1_Ordenado[i] = C1->elementos[i];
            C2_Ordenado[i] = C2->elementos[i];
        }

        OrdenarConjunto(&C1_Ordenado, tamanhoConjuntos);
        OrdenarConjunto(&C2_Ordenado, tamanhoConjuntos);

        for (int i = 0; i < tamanhoConjuntos; i++)
        {
            if (C1_Ordenado[i] != C2_Ordenado[i])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

int subconjunto(Conjunto *C1, Conjunto *C2)
{
    if (C1->tamanho == 0)
    {
        return TRUE;
    }
    else if (C1->tamanho > C2->tamanho)
    {
        return FALSE;
    }
    else
    {
        int tamanhoC1 = C1->tamanho, tamanhoC2 = C2->tamanho;
        int C1_Ordenado[tamanhoC1], C2_Ordenado[tamanhoC2];

        for (int i = 0; i < tamanhoC1; i++)
        {
            C1_Ordenado[i] = C1->elementos[i];
        }
        
        for (int i = 0; i < tamanhoC2; i++)
        {
            C2_Ordenado[i] = C2->elementos[i];
        }

        OrdenarConjunto(&C1_Ordenado, tamanhoC1);
        OrdenarConjunto(&C2_Ordenado, tamanhoC2);

        for (int i = 0; i < tamanhoC1; i++)
        {
            if (C1_Ordenado[i] != C2_Ordenado[i])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

Conjunto complemento(Conjunto *C1, Conjunto *C2)
{
    // for (int i = 0; i < SIZE; i++)
    // {
    //     not_unique = 0;
    //     repeat = 0;

    //     for (int j = 0; j < SIZE; j++)
    //     {
    //         if (A[i] == B[j])
    //         {
    //             not_unique++;
    //             break;
    //         }
    //     }

    //     if (!not_unique)
    //     {
    //         for (int k = 0; k < D_size; k++)
    //         {
    //             if (A[i] == D[k])
    //             {
    //                 repeat++;
    //                 break;
    //             }
    //         }

    //         if (!repeat)
    //         {
    //             D[D_size] = A[i];
    //             D_size++;
    //         }
    //     }
    // }
}

int main()
{
    

    return 0;
}