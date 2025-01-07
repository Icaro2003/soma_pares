#include <stdio.h>
#include <stdlib.h>
#include "somapares.h"

int main()
{
    int v[] = {1, 2, 3, 4};
    int somaAlvo = 7;
    int tam = sizeof(v) / sizeof(v[0]);
    int n1, n2;

    somaParesForcaBruta(v, somaAlvo, tam, &n1, &n2);
    printf("Força bruta:\nPar: %d %d\n\n", n1, n2);

    somaParesDivideConquista(v, somaAlvo, tam, &n1, &n2);
    printf("Dividir e conquistar:\nPar: %d %d\n\n", n1, n2);

    somaParesProgramacaoDinamica(v, somaAlvo, tam, &n1, &n2);
    printf("Programação dinâmica:\nPar: %d %d\n\n", n1, n2);
}