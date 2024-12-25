#include <stdio.h>
#include <stdlib.h>

void somaParesForcaBruta(int *v, int soma, int tam, int *n1, int *n2)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (v[i] + v[j] == soma)
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

void exibirParesAlgoritmo(int n1, int n2)
{
    printf("Força bruta: %d %d\n", n1, n2);
}

int main()
{
    int v[] = {1, 2, 3, 4};
    int somaAlvo = 5;
    int tam = sizeof(v) / sizeof(v[0]);
    int n1, n2;

    somaParesForcaBruta(v, somaAlvo, tam, &n1, &n2);
    exibirParesAlgoritmo(n1, n2);
}