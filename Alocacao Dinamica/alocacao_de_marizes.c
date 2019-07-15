#include <stdio.h>
#include <stdlib.h>

int main(){
	/*Alocação de arrays multidimensionais
	ponteiro de ponteiro*/
	
	//ponteiro (1 nivel): cria um vetor
	int *p  = (int *)malloc(5*sizeof(int));
	
	//ponteiro para ponteiro (2 nivel): permite criar matriz
	int **m;
	
	/*-----------------------------------------------------*/
	
	int **p 
	int i, j, N = 2;
	
	//cria um array de ponteiros (int*)
	p  = (int **) malloc(N * sizeof(int *));
	
	for(i = 0; i < N; i++){
		//cria um array de int
		p[i] = (int * malloc(N * sizeof(int)));
		
		for(j = 0; j< N; j++){
			scanf("%d", &p[i][j];
		}
	}
	
	/*liberar matriz*/
	
	for(i = 0; i < N; i++){
		free(p[i]);
	}
	free(p);
	system("pause");
}
