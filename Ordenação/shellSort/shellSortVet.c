#include<stdio.h>
#include<stdlib.h>

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
            }
            vet [j] = value;
        }
        h = h/3;
    }
}

int main(){
    int vet[12] = {9,7,4,8,3,5,7,9,2,12,15,23,45};
    shellSort(vet, 12);


   for(int i = 0; i < 12; i++){
        printf("\n%d", vet[i]);
   }
}
