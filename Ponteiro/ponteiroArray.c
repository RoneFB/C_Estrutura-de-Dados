#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int vet[5] = {1,2,3,4,5};
	int *p = vet;//aponta para a primeita posição do array
	int i;
	
	for(i = 0; i< 5; i++)
		printf("%d \n", p[i]);//*(p+i)
	
	printf("%d \n", vet[2]);
	printf("%d \n", *(vet+2));
	
	/*Array de Ponteiro*/
	int *pvet[5];//cada posição é um ponteiro
	
	int x, y[2] = {20,30};
	
	
	pvet[0] = &x;
	pvet[1] = y;
	
	printf("pvet[0]: %p\n", pvet[0]);//&x
	printf("pvet[0]: %p\n", pvet[1]);//&y[0]
	
	printf("*pvet[0]: %d\n", *pvet[0]);//x
	printf("pvet[0]: %d\n", pvet[1][1]);//y[1] com vertor de ponteiros, se cria uma matriz
	
	system("pause");
}
