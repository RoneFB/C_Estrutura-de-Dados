#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *v, int n){
    int i, j, min, aux;
    for(i = 0; i < (n-1); i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }if(v[i] != v[min]){
                aux = v[i];
                v[i] = v[min];
                v[min] = aux;
            }
        }
    }
}


int main(){
    int vet[6] = {5,8,12,4,1,0,9};
    selectionSort(vet, 6);


   for(int i = 0; i < 6; i++){
        printf("\n%d", vet[i]);
   }
}
