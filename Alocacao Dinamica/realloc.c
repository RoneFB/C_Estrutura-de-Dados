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
	
	p = (int *) realloc(p,0);
	//equivale a 
	free(p);
	
	/*Cuidado com Realloc: se n�o houver memoria suficiente
	para alocar a memoria requisitasa
	a funcao realloc retorna null*/
	
	int *p = (int *) malloc(5*sizeof(int));
	int *p1 = (int *) realloc(p, 15*sizeof(int));
	/*Copia os valores de p para p1, garante os dados de *p*/
	if(p1 != NULL){
		p = p1;
	}
	free(p);
	system("pause");
}
