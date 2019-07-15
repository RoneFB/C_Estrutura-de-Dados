#include <stdio.h>
#include <stdlib.h>

int main(){
	/* Realloc: aloca mem�ria durante a execu��o do porgrama
	faz uma requisi�o de mem�ria ao coomputador e retorna um ponteiro com o endere�o do incio do espa�o de mem�ria alocado*/
	/*Permite mudar tamanho de um vetor*/
	
	void* realloc(void* ptr, unsigned int num);//(pr�vio endere�o, Tamanho novo)
	
	
	//cria array de 50 inteiros (200 bytes)
	int *v = (int*) malloc(200);
	
	//aumenta a mem�ria e aloca para 100 inteiros (400 bytes);
	v = (int*) realloc(v, 100 * sizeof(int));
	
	
	
	/*Se o ponteiro para o bloco de memoria
	previamente alocado for NULL, a fun��o realloc() ira alocar mem�ria da mesma forma 
	como a fun��o malloc()*/
	
	int *p;
	
	p = (int *) realloc(NULL, 50*sizeof(int));
	//equivale a 
	p = (int *) malloc(50*sizeof(int));
	
	system("pause");
}
