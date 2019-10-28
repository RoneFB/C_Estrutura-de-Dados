#include<stdio.h>
#include<stdlib.h>

void insert(int *vet, int n){
    int i,j, aux;

    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i-1;
        for(;j>=0 && vet[j] > aux; j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}

int main(){
    int vet[6] = {9,7,4,8,5,1,2,6};
    insert(vet, 6);


   for(int i = 0; i < 6; i++){
        printf("\n%d", vet[i]);
   }
}
