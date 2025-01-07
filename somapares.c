#include <stdio.h>
#include <stdlib.h>
#include "somapares.h"

void somaParesForcaBruta(int *v, int somaAlvo, int tam, int *n1, int *n2)
{
    if (v == NULL || tam == 0)
    {
        *n1 = -1;
        *n2 = -1;
        return;
    }
    

    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (v[i] + v[j] == somaAlvo)
            {
                *n1 = v[i];
                *n2 = v[j];
                return;
            }
        }
    }

    *n1 = -1;
    *n2 = -1;
}

void somaParesDivideConquista(int *v, int somaAlvo, int tam, int *n1, int *n2)
{
    if (v == NULL || tam == 0)
    {
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
        *n1 = -1;
        *n2 = -1;
    }

    free(complementar);
}