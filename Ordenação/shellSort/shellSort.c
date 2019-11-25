#include <stdio.h>
#include <stdlib.h>

#define SIZE 9


void imprimir(int arr[], int len)
{
    int i;

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void shellSort(int array[], int size)
{
    int i, j, gap, aux;

    //gap = (3*size)-1;gap > 0 ;gap = gap / 3
    for (gap = size / 2; gap > 0; gap = gap / 2)
        for (i = gap; i < size; i++){
            aux = array[i];
            j = i;
            while (j > gap-1 && aux <= array[j - gap]) {
                array[j] = array[j - gap];
                j = j-gap;
            }array[j] = aux;
        }
}


int main()
{

    int array[SIZE] = {100,75,92,0,150,12,2,4,1};
    imprimir(array, SIZE);
    shellSort(array, SIZE);
    imprimir(array, SIZE);
}
