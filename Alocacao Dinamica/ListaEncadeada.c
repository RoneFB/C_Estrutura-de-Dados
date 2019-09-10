#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula cel;

int main(){
     cel * soma_ab(cel *a, cel *b);
	/*Cria 1 lista com cabe�a*/
	cel *lst_cabeca;
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;

	printf("add com cabeca\n");

	//lista_com_cabeca(lst_cabeca,15);
	lista_com_cabeca(lst_cabeca,7);
	lista_com_cabeca(lst_cabeca,9);
	lista_com_cabeca(lst_cabeca,5);
	imprime_com_cabeca(lst_cabeca);

	/*segunda lista com cabe�a*/
	cel *lst_cabeca2;
	lst_cabeca2 =  malloc(sizeof(cel));
	lst_cabeca2->prox = NULL;
	printf("add com cabeca\n");
	lista_com_cabeca(lst_cabeca2,1);
	lista_com_cabeca(lst_cabeca2,2);
	lista_com_cabeca(lst_cabeca2,3);
	lista_com_cabeca(lst_cabeca2,4);
	imprime_com_cabeca(lst_cabeca2);
}
cel * cria_celula(int valor){
	cel *nova;
	nova = malloc(sizeof(cel));
	nova->valor = valor;
	nova->prox = NULL;
	return nova;
}
void * adiciona(cel *p,int valor){
    cel * nova;
    if(valor > 9){
        nova = cria_celula(valor / 10);
        nova->prox = cria_celula(valor % 10);
        nova->prox->prox = p->prox;
    }else{
        nova = cria_celula(valor);
        nova->prox = p->prox;

    }
     p->prox = nova;
}

void lista_sem_cabeca(cel **p, int n){
	cel *aux;
	if (*p == NULL)
      *p = cria_celula(n);
    else {
      for (aux = *p; aux->prox != NULL; aux = aux->prox);
      aux->prox = cria_celula(n);
    }
}


void lista_com_cabeca(cel *p, int n){
	cel *nova;
	nova = malloc(sizeof(cel));
	nova->valor = n;
	nova->prox = p->prox;
	p->prox = nova;
}


//imprimindo lista com cabe�a
void imprime_com_cabeca(cel *le) {
   cel *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->valor);
}

//imprime lista sem cabe�a
void imprime_sem_cabeca(cel *le) {
   cel *p;
   for (p = le; p != NULL; p = p->prox)
      printf ("%d\n", p->valor);
}



