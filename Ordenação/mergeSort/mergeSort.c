#include <stdio.h>
#include <stdlib.h>

#define SIZE 9


void imprimir(int v[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void intercala(int v[], int ini, int meio, int fim)
{
   int *aux = malloc(sizeof(int));

    int i = ini, j = meio+1, k = 0;
    while(i<=meio && j<=fim)
        if(v[i] < v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    while(i<=meio) aux[k++] = v[i++];
    while(j<=fim)aux[k++] = v[j++];
    for(k = 0; k<=fim-ini; k++) v[ini+k] = aux[k];
    free(aux);

}
void mergeSort(int *v,int ini,int fim)
{
    if(ini == fim)return;
    int meio = (ini+fim)/2;
    mergeSort(v, ini,meio);
    mergeSort(v,meio+1,fim);
    intercala(v,ini,meio,fim);
}


int main()
{
    int array[SIZE] = {4,3,92,12,8,12,2,1,44};
    imprimir(array, SIZE);
    mergeSort(array,0,SIZE-1);
    imprimir(array, SIZE);
}

