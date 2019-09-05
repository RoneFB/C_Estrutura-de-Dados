#include <stdio.h>
#include <stdlib.h>

void pares(int vet[], int n){
	if(n > 0){
		return;
	}if(vet[n] % 2 != 0){
		printf("%d", &vet[n-1]);
	}
	pares(vet,n);
}

int main(){
	
}
