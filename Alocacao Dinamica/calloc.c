#include <stdio.h>
#include <stdlib.h>

int main(){
	/*Calloc - Faz pedido de memória ao computador e retorna um ponteiro com o endereço 
	do inicio do espaço de memória alocado*/
	
	/*Coloca zero "0" em todos os bits da memória*/
	
	void* calloc(unsigned int num, unsigned int size);//(Quantidade de posições, tamanho de cada posição)
	
	//Cria um array de 50 inteiros (4 bytes cada)
	int *v = (int*) calloc(50,4);
	
	//cria array de 200 char(1 byte cada)
	char *c = (char*) calloc(200,1);
	
	//Sizeof
	int *v = (int*) calloc(50, sizeof(int));
	char *c = (char*) calloc(50, sizeof(char));
	
	
	int *p;
	p = (int *) calloc(5, sizeof(int));
	if(p == NULL){
		printf("Sem memoria\n");
	}	
	
	int i;
	for(i = 0; i<5; i++){
		printf("Digite p[%d]:", i);
		scanf("%d", &p[i]);
	}
	
	free(p);
	system("pause");
}
