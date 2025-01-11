#include <stdio.h>
#include <stdlib.h>
#include "somapares.h"

int main()
{
    int v[100000];
    int somaAlvo = 10;
    int tam = sizeof(v) / sizeof(v[0]);
    int n1, n2;

    printf("Algoritmos:\n");

    printf("Força Bruta:\n");
    exibirDesempenhoAlgoritmo(somaParesForcaBruta, v, somaAlvo, tam);
    
    printf("\nDividir e Conquistar:\n");
    exibirDesempenhoAlgoritmo(somaParesDivideConquista, v, somaAlvo, tam);
    
    printf("\nProgramação Dinâmica:\n");
    exibirDesempenhoAlgoritmo(somaParesProgramacaoDinamica, v, somaAlvo, tam);
}