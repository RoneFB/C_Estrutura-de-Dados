#include <stdio.h>
#include <stdlib.h>

/*
Criando uma Lista C/ Cabeça utilizando como base os elementos de um vetor
*/

struct cel 
{
    int valor;
    struct cel *prox;
};

typedef struct cel celula;

celula * criaCelula(int valor){
	celula *p;
	p = malloc(sizeof(celula));
	p->valor = valor;
	p->prox = NULL;
	return p;
}

celula * criaList(celula * cel, int valor){
	celula *lst;
	cel = criaCelula(valor);
	lst = cel;
	
	return lst;
}
void imp(celula *cel){
	if(cel->prox != NULL)
		printf("%d", cel->valor);
}

int main(){
	celula* criaList(celula *cel, int valor);
	void imp(celula *cel);
	
	
	imp(criaList(criaCelula(0), 1));
}
