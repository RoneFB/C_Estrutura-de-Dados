#include <stdio.h>
#include <stdlib.h>

int main(){
	/*FUNÇÃO malloc(): aloca memória durante a execução do porgrama
	faz uma requisião de memória ao coomputador e retorna um ponteiro com o endereço do incio do espaço de memória alocado*/
	
	void* malloc(unsigned int num);//ponteiro genérico
	
	/*array de 50 inteiros (200bytes)*/
	int *v = malloc(50 * sizeof(int));
	
	//cria array de 50 char (50bytes)
	char *c = malloc(50 * sizeof(char));
	
	/*se não houver memmória sufucientre para alocar a memória requisitada a função malloc retorna null*/
	
	int *p;
	
	p = (int *) malloc(5*sizeof(int));
	
	if(p == NULL){
		pirntf("erro: sem memória\n");
		exit(1);
	}
	
	/*utilizando como vetor*/
	int i 
	for(i = 0 ; i< 5;i++){
		printf("Digite p[%d]:", i);
		scanf("%d", &p[i]);
	}
	
	//liberar a memória alocada
	free(p);
	
	system("pause");
}
