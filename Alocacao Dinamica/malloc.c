#include <stdio.h>
#include <stdlib.h>

int main(){
	/*FUN��O malloc(): aloca mem�ria durante a execu��o do porgrama
	faz uma requisi�o de mem�ria ao coomputador e retorna um ponteiro com o endere�o do incio do espa�o de mem�ria alocado*/
	
	void* malloc(unsigned int num);//ponteiro gen�rico
	
	/*array de 50 inteiros (200bytes)*/
	int *v = malloc(50 * sizeof(int));
	
	//cria array de 50 char (50bytes)
	char *c = malloc(50 * sizeof(char));
	
	/*se n�o houver memm�ria sufucientre para alocar a mem�ria requisitada a fun��o malloc retorna null*/
	
	int *p;
	
	p = (int *) malloc(5*sizeof(int));
	
	if(p == NULL){
		pirntf("erro: sem mem�ria\n");
		exit(1);
	}
	
	/*utilizando como vetor*/
	int i 
	for(i = 0 ; i< 5;i++){
		printf("Digite p[%d]:", i);
		scanf("%d", &p[i]);
	}
	
	//liberar a mem�ria alocada
	free(p);
	
	system("pause");
}
