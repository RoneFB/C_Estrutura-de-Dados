#include <stdio.h>
#include <stdlib.h>

int main(){
	/* Realloc: aloca memória durante a execução do porgrama
	faz uma requisião de memória ao coomputador e retorna um ponteiro com o endereço do incio do espaço de memória alocado*/
	/*Permite mudar tamanho de um vetor*/
	
	void* realloc(void* ptr, unsigned int num);//(prévio endereço, Tamanho novo)
	
	
	//cria array de 50 inteiros (200 bytes)
	int *v = (int*) malloc(200);
	
	//aumenta a memória e aloca para 100 inteiros (400 bytes);
	v = (int*) realloc(v, 100 * sizeof(int));
	
	
	
	/*Se o ponteiro para o bloco de memoria
	previamente alocado for NULL, a função realloc() ira alocar memória da mesma forma 
	como a função malloc()*/
	
	int *p;
	
	p = (int *) realloc(NULL, 50*sizeof(int));
	//equivale a 
	p = (int *) malloc(50*sizeof(int));
	
	system("pause");
}
