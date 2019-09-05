#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula celula;

struct fila{
	celula * i;
	celula * t;
};typedef struct fila fila;


void renovaFila(celula **pi, celula **pt){
	celula * lixo;
	lixo = *pi;
	*pi = lixo->prox;
	free(lixo);
}

void addFila(celula **pt, int valor){
	celula * nova = (celula*) malloc(sizeof(celula));
	celula * aux = (*pt);
	nova->valor = valor;
	nova->prox = NULL;
    if(aux != NULL){
        aux->prox = nova;
    }
}

void imprimirFila(fila *f)
{
    celula *p = f->i;
    for(p; p != NULL; p = p->prox)
        printf("| %x | %d | %x |", p, p->valor, p->prox);
}
int main(){

	fila *f = malloc(sizeof(fila));
	f->i = 0;
	f->t = 0;

	addFila(f->t,10);

	imprimirFila(f);
}
