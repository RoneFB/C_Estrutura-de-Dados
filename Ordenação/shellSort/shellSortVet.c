#include<stdio.h>
#include<stdlib.h>
void troca(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void imprimir(int v[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int h = size-1;
        h = (3*h)+1;
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {

                vet[j] = vet [j - h];
                j = j - h;
                printf("%d %d\n",i,j);
            }
            vet [j] = value;
            imprimir(vet, 9);
        }
        h = h/3;
    }
}

int main(){
    int vet[9] = {100,75,92,0,150,12,2,4,1};

    imprimir(vet, 9);
    shellSort(vet, 9);
    imprimir(vet, 9);
}
