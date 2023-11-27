#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct
{
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
    C->elementos = NULL;

    return SUCESSO;
}

int conjuntoVazio(Conjunto *C)
{
    return (C->tamanho == 0);
}

int insereElementoConjunto(int x, Conjunto *C)
{
    for (int i = 0; i < C->tamanho; i++)
    {
        if (C->elementos[i] == x)
        {
            printf("O elemento %d já está no conjunto!\n", x);
            return FALHA;
        }
    }

    C->elementos = (int *)realloc(C->elementos, (C->tamanho + 1) * sizeof(int));

    if (C->elementos == NULL)
    {
        printf("Não foi possível alocar memória para o elemento %d!\n", x);
        return FALHA;
    }

    C->elementos[C->tamanho] = x;
    C->tamanho++;

    return SUCESSO;
}

int excluirElementoConjunto(int x, Conjunto *C)
{
    int i, j;

    for (i = 0; i < C->tamanho; i++)
    {
        if (C->elementos[i] == x)
        {
            for (j = i; j < C->tamanho - 1; j++)
            {
                C->elementos[j] = C->elementos[j + 1];
            }

            C->elementos = (int *)realloc(C->elementos, (C->tamanho - 1) * sizeof(int));

            if (C->elementos == NULL && C->tamanho > 1)
            {
                printf("Não foi possível alocar memória para o conjunto!\n");
                return FALHA;
            }

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

void OrdenarConjunto(int *C, int tamanhoConjunto)
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
        int *C1_Ordenado = (int *)malloc(tamanhoConjuntos * sizeof(int));
        int *C2_Ordenado = (int *)malloc(tamanhoConjuntos * sizeof(int));

        if (C1_Ordenado == NULL || C2_Ordenado == NULL)
        {
            printf("Não foi possível alocar memória para ordenar conjuntos!\n");
            return FALHA;
        }

        for (int i = 0; i < tamanhoConjuntos; i++)
        {
            C1_Ordenado[i] = C1->elementos[i];
            C2_Ordenado[i] = C2->elementos[i];
        }

        OrdenarConjunto(C1_Ordenado, tamanhoConjuntos);
        OrdenarConjunto(C2_Ordenado, tamanhoConjuntos);

        for (int i = 0; i < tamanhoConjuntos; i++)
        {
            if (C1_Ordenado[i] != C2_Ordenado[i])
            {
                free(C1_Ordenado);
                free(C2_Ordenado);
                return FALSE;
            }
        }

        free(C1_Ordenado);
        free(C2_Ordenado);
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
        int *C1_Ordenado = (int *)malloc(tamanhoC1 * sizeof(int));
        int *C2_Ordenado = (int *)malloc(tamanhoC2 * sizeof(int));

        if (C1_Ordenado == NULL || C2_Ordenado == NULL)
        {
            printf("Não foi possível alocar memória para ordenar conjuntos!\n");
            return FALHA;
        }

        for (int i = 0; i < tamanhoC1; i++)
        {
            C1_Ordenado[i] = C1->elementos[i];
        }

        for (int i = 0; i < tamanhoC2; i++)
        {
            C2_Ordenado[i] = C2->elementos[i];
        }

        OrdenarConjunto(C1_Ordenado, tamanhoC1);
        OrdenarConjunto(C2_Ordenado, tamanhoC2);

        for (int i = 0; i < tamanhoC1; i++)
        {
            if (C1_Ordenado[i] != C2_Ordenado[i])
            {
                free(C1_Ordenado);
                free(C2_Ordenado);
                return FALSE;
            }
        }

        free(C1_Ordenado);
        free(C2_Ordenado);
    }

    return TRUE;
}

Conjunto complemento(Conjunto *C1, Conjunto *C2)
{
    Conjunto complemento;
    criaConjunto(&complemento);

    for (int i = 0; i < C2->tamanho; i++)
    {
        if (!pertenceConjunto(C2->elementos[i], C1))
        {
            insereElementoConjunto(C2->elementos[i], &complemento);
        }
    }

    return complemento;
}

Conjunto uniao(Conjunto *C1, Conjunto *C2)
{
    Conjunto uniao;
    criaConjunto(&uniao);

    for (int i = 0; i < C1->tamanho; i++)
    {
        insereElementoConjunto(C1->elementos[i], &uniao);
    }

    for (int i = 0; i < C2->tamanho; i++)
    {
        insereElementoConjunto(C2->elementos[i], &uniao);
    }

    return uniao;
}

Conjunto interseccao(Conjunto *C1, Conjunto *C2)
{
    Conjunto interseccao;
    criaConjunto(&interseccao);

    for (int i = 0; i < C1->tamanho; i++)
    {
        if (pertenceConjunto(C1->elementos[i], C2))
        {
            insereElementoConjunto(C1->elementos[i], &interseccao);
        }
    }

    return interseccao;
}

Conjunto diferenca(Conjunto *C1, Conjunto *C2)
{
    Conjunto diferenca;
    criaConjunto(&diferenca);

    for (int i = 0; i < C1->tamanho; i++)
    {
        if (!pertenceConjunto(C1->elementos[i], C2))
        {
            insereElementoConjunto(C1->elementos[i], &diferenca);
        }
    }

    return diferenca;
}

Conjunto conjuntoPartes(Conjunto *C)
{
    Conjunto partes;
    criaConjunto(&partes);

    int totalSubsets = 1 << C->tamanho;
    for (int i = 0; i < totalSubsets; i++)
    {
        Conjunto subset;
        criaConjunto(&subset);

        for (int j = 0; j < C->tamanho; j++)
        {
            if (i & (1 << j))
            {
                insereElementoConjunto(C->elementos[j], &subset);
            }
        }

        uniao(&partes, &subset);
    }

    return partes;
}

void mostraConjunto(Conjunto *C, int ordem)
{
    if (ordem == CRESCENTE)
    {
        OrdenarConjunto(C->elementos, C->tamanho);
    }
    else if (ordem == DECRESCENTE)
    {
        OrdenarConjunto(C->elementos, C->tamanho);
        int aux;
        for (int i = 0; i < (C->tamanho / 2); i++)
        {
            aux = C->elementos[i];
            C->elementos[i] = C->elementos[C->tamanho - i - 1];
            C->elementos[C->tamanho - i - 1] = aux;
        }
    }

    printf("Conjunto: ");
    for (int i = 0; i < C->tamanho; i++)
    {
        printf("%d ", C->elementos[i]);
    }
    printf("\n");
}

int copiarConjunto(Conjunto *C1, Conjunto *C2)
{
    if (C1 == NULL || C2 == NULL)
    {
        return FALHA;
    }

    criaConjunto(C2);

    for (int i = 0; i < C1->tamanho; i++)
    {
        if (insereElementoConjunto(C1->elementos[i], C2) == FALHA)
        {
            return FALHA;
        }
    }

    return SUCESSO;
}

int destroiConjunto(Conjunto *C)
{
    if (C == NULL)
    {
        return FALHA;
    }

    free(C->elementos);
    C->elementos = NULL;
    C->tamanho = 0;

    return SUCESSO;
}

int main()
{
    Conjunto conjuntoA, conjuntoB, resultado;
    int opcao;

    criaConjunto(&conjuntoA);
    criaConjunto(&conjuntoB);
    criaConjunto(&resultado);

    do
    {
        printf("\n*** Menu de Operações ***\n");
        printf("1. Inserir elemento em conjunto A\n");
        printf("2. Inserir elemento em conjunto B\n");
        printf("3. Excluir elemento de conjunto A\n");
        printf("4. Excluir elemento de conjunto B\n");
        printf("5. Mostrar conjuntos\n");
        printf("6. Realizar operações com conjuntos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a ser inserido em conjunto A: ");
            
            int elementoA;
            scanf("%d", &elementoA);

            insereElementoConjunto(elementoA, &conjuntoA);
            break;

        case 2:
            printf("Digite o elemento a ser inserido em conjunto B: ");
            
            int elementoB;
            scanf("%d", &elementoB);

            insereElementoConjunto(elementoB, &conjuntoB);
            break;

        case 3:
            printf("Digite o elemento a ser excluído de conjunto A: ");
            
            int elementoExcluirA;
            scanf("%d", &elementoExcluirA);

            excluirElementoConjunto(elementoExcluirA, &conjuntoA);
            break;

        case 4:
            printf("Digite o elemento a ser excluído de conjunto B: ");
            
            int elementoExcluirB;
            scanf("%d", &elementoExcluirB);
            
            excluirElementoConjunto(elementoExcluirB, &conjuntoB);
            break;

        case 5:
            printf("Conjunto A:\n");
            mostraConjunto(&conjuntoA, CRESCENTE);

            printf("Conjunto B:\n");
            mostraConjunto(&conjuntoB, CRESCENTE);
            break;

        case 6:
            printf("1. União\n");
            printf("2. Interseção\n");
            printf("3. Diferença\n");
            printf("4. Complemento de A em relação a B\n");
            printf("5. Verificar subconjunto\n");
            printf("Escolha uma operação: ");
            
            int operacao;
            scanf("%d", &operacao);

            switch (operacao)
            {
            case 1:
                resultado = uniao(&conjuntoA, &conjuntoB);
                printf("União de A e B:\n");
                mostraConjunto(&resultado, CRESCENTE);
                destroiConjunto(&resultado);
                break;

            case 2:
                resultado = interseccao(&conjuntoA, &conjuntoB);
                printf("Interseção de A e B:\n");
                mostraConjunto(&resultado, CRESCENTE);
                destroiConjunto(&resultado);
                break;

            case 3:
                resultado = diferenca(&conjuntoA, &conjuntoB);
                printf("Diferença de A e B:\n");
                mostraConjunto(&resultado, CRESCENTE);
                destroiConjunto(&resultado);
                break;

            case 4:
                resultado = complemento(&conjuntoA, &conjuntoB);
                printf("Complemento de A em relação a B:\n");
                mostraConjunto(&resultado, CRESCENTE);
                destroiConjunto(&resultado);
                break;

            case 5:
                if (subconjunto(&conjuntoA, &conjuntoB))
                    printf("A é subconjunto de B.\n");
                else
                    printf("A não é subconjunto de B.\n");
                break;

            default:
                printf("Opção inválida.\n");
            }
            break;

        case 0:
            printf("O programa foi encerrado.\n");
            break;

        default:
            printf("Opção inválida. Escolha novamente.\n");
        }

    } while (opcao != 0);

    destroiConjunto(&conjuntoA);
    destroiConjunto(&conjuntoB);

    return 0;
}