#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *conteudo;
} Texto;

Texto *criarTexto(char *t)
{
    Texto *novoTexto = (Texto *)malloc(sizeof(Texto));
    if (novoTexto == NULL)
    {
        return NULL;
    }

    novoTexto->conteudo = strdup(t);

    return novoTexto;
}

void liberarTexto(Texto *t)
{
    if (t != NULL)
    {
        free(t->conteudo);
        free(t);
    }
}

unsigned int tamanhoTexto(Texto *t)
{
    return (t != NULL) ? strlen(t->conteudo) : 0;
}

char *obterTexto(Texto *t)
{
    return (t != NULL) ? t->conteudo : NULL;
}

void mostrarTexto(Texto *t, unsigned int colunas)
{
    if (t == NULL)
    {
        return;
    }

    unsigned int tamanho = strlen(t->conteudo);
    for (unsigned int i = 0; i < tamanho; ++i)
    {
        putchar(t->conteudo[i]);

        if ((i + 1) % colunas == 0 || (i + 1) == tamanho)
        {
            putchar('\n');
        }
    }
}

Texto *copiarTexto(Texto *t)
{
    if (t == NULL)
    {
        return NULL;
    }

    return criarTexto(t->conteudo);
}

void substituirTexto(Texto *t, char *alteracao)
{
    if (t != NULL && alteracao != NULL)
    {
        free(t->conteudo);
        t->conteudo = strdup(alteracao);
    }
}

Texto *concatenarTextos(Texto *t1, Texto *t2)
{
    if (t1 == NULL || t2 == NULL)
    {
        return NULL;
    }

    char *novoConteudo = (char *)malloc(strlen(t1->conteudo) + strlen(t2->conteudo) + 1);
    if (novoConteudo == NULL)
    {
        return NULL;
    }

    strcpy(novoConteudo, t1->conteudo);
    strcat(novoConteudo, t2->conteudo);

    Texto *novoTexto = criarTexto(novoConteudo);
    free(novoConteudo);

    return novoTexto;
}

char *obterSubtexto(Texto *t, unsigned int inicio, unsigned int tamanho)
{
    if (t == NULL || inicio < 1 || inicio > tamanhoTexto(t) || tamanho == 0)
    {
        return NULL;
    }

    char *subtexto = (char *)malloc(tamanho + 1);
    if (subtexto == NULL)
    {
        return NULL;
    }

    strncpy(subtexto, t->conteudo + inicio - 1, tamanho);
    subtexto[tamanho] = '\0';

    return subtexto;
}

unsigned int encontrarSubtexto(Texto *t, char *subtexto, unsigned int ocorrencia)
{
    if (t == NULL || subtexto == NULL || ocorrencia == 0)
    {
        return 0;
    }

    char *ocorrenciaEncontrada = strstr(t->conteudo, subtexto);
    while (ocorrenciaEncontrada != NULL && --ocorrencia > 0)
    {
        ocorrenciaEncontrada = strstr(ocorrenciaEncontrada + 1, subtexto);
    }

    return (ocorrenciaEncontrada != NULL) ? (ocorrenciaEncontrada - t->conteudo) + 1 : 0;
}

int compararTextos(Texto *t1, Texto *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return 0;
    }

    if (t1 == NULL)
    {
        return -1;
    }

    if (t2 == NULL)
    {
        return 1;
    }

    return strcmp(t1->conteudo, t2->conteudo);
}

int main()
{
    Texto *texto1 = NULL;
    Texto *texto2 = NULL;
    int opcao;

    do
    {
        printf("\n*** Menu de Operações ***\n");
        printf("1. Criar Texto\n");
        printf("2. Liberar Texto\n");
        printf("3. Tamanho do Texto\n");
        printf("4. Obter Texto\n");
        printf("5. Mostrar Texto\n");
        printf("6. Copiar Texto\n");
        printf("7. Substituir Texto\n");
        printf("8. Concatenar Textos\n");
        printf("9. Obter Subtexto\n");
        printf("10. Encontrar Subtexto\n");
        printf("11. Comparar Textos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            char buffer[100];
            printf("Digite o texto: ");
            scanf(" %[^\n]", buffer);
            texto1 = criarTexto(buffer);
            if (texto1 != NULL)
            {
                printf("Texto criado com sucesso!\n");
            }
            else
            {
                printf("Falha ao criar o texto.\n");
            }
            break;
        }

        case 2:
            liberarTexto(texto1);
            texto1 = NULL;
            printf("Texto liberado com sucesso!\n");
            break;

        case 3:
            printf("Tamanho do texto: %u\n", tamanhoTexto(texto1));
            break;

        case 4:
            printf("Texto: %s\n", obterTexto(texto1));
            break;

        case 5:
        {
            unsigned int colunas;
            printf("Número de colunas por linha: ");
            scanf("%u", &colunas);
            mostrarTexto(texto1, colunas);
            break;
        }

        case 6:
            texto2 = copiarTexto(texto1);
            if (texto2 != NULL)
            {
                printf("Texto copiado com sucesso!\n");
            }
            else
            {
                printf("Falha ao copiar o texto.\n");
            }
            break;

        case 7:
        {
            char buffer[100];
            printf("Digite o novo texto para substituição: ");
            scanf(" %[^\n]", buffer);
            substituirTexto(texto1, buffer);
            printf("Texto substituído com sucesso!\n");
            break;
        }

        case 8:
        {
            char buffer[100];
            printf("Digite o segundo texto para concatenação: ");
            scanf(" %[^\n]", buffer);
            texto2 = criarTexto(buffer);
            Texto *concatenado = concatenarTextos(texto1, texto2);
            if (concatenado != NULL)
            {
                printf("Textos concatenados com sucesso!\n");
                mostrarTexto(concatenado, 80);
                liberarTexto(concatenado);
            }
            else
            {
                printf("Falha ao concatenar os textos.\n");
            }
            liberarTexto(texto2);
            texto2 = NULL;
            break;
        }

        case 9:
        {
            unsigned int inicio, tamanho;
            printf("Digite a posição inicial: ");
            scanf("%u", &inicio);
            printf("Digite o tamanho do subtexto: ");
            scanf("%u", &tamanho);
            char *subtexto = obterSubtexto(texto1, inicio, tamanho);
            if (subtexto != NULL)
            {
                printf("Subtexto: %s\n", subtexto);
                free(subtexto);
            }
            else
            {
                printf("Falha ao obter o subtexto.\n");
            }
            break;
        }

        case 10:
        {
            char subtexto[100];
            unsigned int ocorrencia;
            printf("Digite o subtexto a ser encontrado: ");
            scanf(" %[^\n]", subtexto);
            printf("Digite a ocorrência desejada: ");
            scanf("%u", &ocorrencia);
            unsigned int posicao = encontrarSubtexto(texto1, subtexto, ocorrencia);
            if (posicao != 0)
            {
                printf("Subtexto encontrado na posição: %u\n", posicao);
            }
            else
            {
                printf("Subtexto não encontrado.\n");
            }
            break;
        }

        case 11:
        {
            if (texto2 == NULL)
            {
                printf("Crie um segundo texto para comparação.\n");
                break;
            }
            int resultado = compararTextos(texto1, texto2);
            if (resultado < 0)
            {
                printf("Texto 1 é menor que o Texto 2.\n");
            }
            else if (resultado == 0)
            {
                printf("Texto 1 é igual ao Texto 2.\n");
            }
            else
            {
                printf("Texto 1 é maior que o Texto 2.\n");
            }
            break;
        }

        case 0:
            printf("O programa foi encerrado.\n");
            break;

        default:
            printf("Opção inválida. Escolha novamente.\n");
        }

    } while (opcao != 0);

    liberarTexto(texto1);
    liberarTexto(texto2);

    return 0;
}