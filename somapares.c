#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "somapares.h"

void somaParesForcaBruta(int *v, int somaAlvo, int tam, int *n1, int *n2)
{
    if (v == NULL || tam == 0)
    {
        printf("Vetor vazio!\n");
        *n1 = -1;
        *n2 = -1;
        return;
    }

    int encontrado = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (v[i] + v[j] == somaAlvo)
            {
                *n1 = v[i];
                *n2 = v[j];
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado)
    {
        printf("Par não encontrado!\n");
        *n1 = -1;
        *n2 = -1;
    }
}

void somaParesDivideConquista(int *v, int somaAlvo, int tam, int *n1, int *n2)
{
    if (v == NULL || tam == 0)
    {
        printf("Vetor vazio!\n");
        *n1 = -1;
        *n2 = -1;
        return;
    }

    quickSort(v, 0, tam - 1);
    verificaAtribuiSomaParesDivideConquista(v, somaAlvo, 0, tam - 1, n1, n2);
}

void quickSort(int *v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = particionar(v, inicio, fim);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int particionar(int *v, int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i + 1], &v[fim]);

    return i + 1;
}

void troca(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void verificaAtribuiSomaParesDivideConquista(int *v, int somaAlvo, int inicio, int fim, int *n1, int *n2)
{
    if (inicio >= fim)
    {
        printf("Par não econtrado!\n");
        *n1 = -1;
        *n2 = -1;
        return;
    }

    int soma = v[inicio] + v[fim];

    if (soma == somaAlvo)
    {
        *n1 = v[inicio];
        *n2 = v[fim];
        return; 
    }

    if (soma < somaAlvo)
    {
        verificaAtribuiSomaParesDivideConquista(v, somaAlvo, inicio + 1, fim, n1, n2);
    }
    else
    {
        verificaAtribuiSomaParesDivideConquista(v, somaAlvo, inicio, fim - 1, n1, n2);
    }
}

void somaParesProgramacaoDinamica(int *v, int somaAlvo, int tam, int *n1, int *n2)
{
    int *complementar = (int *)malloc(tam * sizeof(int));
    int tamanhoComplementar = 0;
    int complemento;
    int encontrado = 0;

    if (complementar == NULL || tam == 0 || v == NULL)
    {
        printf("Vetor vazio!\n");
        *n1 = -1;
        *n2 = -1;
        return;
    }

    for (int i = 0; i < tam; i++)
    {
        complemento = somaAlvo - v[i];

        for (int j = 0; j < tamanhoComplementar; j++)
        {
            if (complementar[j] == complemento)
            {
                *n1 = complemento;
                *n2 = v[i];
                encontrado = 1;
            }
        }

        complementar[tamanhoComplementar++] = v[i];
    }

    if (!encontrado)
    {
        printf("O par não foi encontrado!\n");
        *n1 = -1;
        *n2 = -1;
    }

    free(complementar);
}

void gerarValoresAleatorios(int *v, int tam)
{
    srand((int)time(NULL));

    for (int i = 0; i < tam; i++)
    {
        v[i] = rand() % 1000;
    }
}

void exibirDesempenhoAlgoritmo(void (*func)(int *, int, int, int *, int *), int *v, int somaAlvo, int tam)
{
    gerarValoresAleatorios(v, tam);

    int n1, n2;
    clock_t inicio, fim;
    double tempoExecucao;

    inicio = clock();
    func(v, somaAlvo, tam, &n1, &n2);
    fim = clock();

    tempoExecucao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;

    printf("Par encontrado: %d e %d\n", n1, n2);
    printf("Tempo de execução: %.3f ms\n", tempoExecucao);

    printf("Eficiência: ");
    if (tempoExecucao > 1000)
    {
        printf("Muito Baixa\n");
    }
    else if (tempoExecucao > 500)
    {
        printf("Baixa\n");
    }
    else if (tempoExecucao > 100)
    {
        printf("Moderada\n");
    }
    else if (tempoExecucao > 50)
    {
        printf("Boa\n");
    }
    else if (tempoExecucao > 10)
    {
        printf("Alta\n");
    }
    else
    {
        printf("Muito Alta\n");
    }
}