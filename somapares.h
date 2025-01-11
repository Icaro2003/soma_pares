#ifndef SOMAPARES_H
#define SOMAPARES_H

void somaParesForcaBruta(int *v, int somaAlvo, int tam, int *n1, int *n2);
void somaParesDivideConquista(int *v, int somaAlvo, int tam, int *n1, int *n2);
void quickSort(int *v, int inicio, int fim);
int particionar(int *v, int inicio, int fim);
void troca(int *v1, int *v2);
void verificaAtribuiSomaParesDivideConquista(int *v, int somaAlvo, int inicio, int fim, int *n1, int *n2);
void somaParesProgramacaoDinamica(int *v, int somaAlvo, int tam, int *n1, int *n2);
void gerarValoresAleatorios(int *v, int tam);
void exibirDesempenhoAlgoritmo(void (*func)(int*, int, int, int*, int*), int *v, int somaAlvo, int tam);

#endif