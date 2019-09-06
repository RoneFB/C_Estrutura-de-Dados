#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula cel;

int main(){
     cel * soma_ab(cel *a, cel *b);
	/*Cria 1 lista com cabeça*/
	cel *lst_cabeca;
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;

	printf("add com cabeca\n");

	//lista_com_cabeca(lst_cabeca,15);
	lista_com_cabeca(lst_cabeca,3);
	lista_com_cabeca(lst_cabeca,2);
	lista_com_cabeca(lst_cabeca,5);
	imprime_com_cabeca(lst_cabeca);

	/*segunda lista com cabeça*/
	cel *lst_cabeca2;
	lst_cabeca2 =  malloc(sizeof(cel));
	lst_cabeca2->prox = NULL;
	printf("add com cabeca\n");
	lista_com_cabeca(lst_cabeca2,9);
	lista_com_cabeca(lst_cabeca2,7);
	imprime_com_cabeca(lst_cabeca2);

	/*soma duas listas*/
	printf("Soma duas listas\n");

	cel * lst_soma = soma_ab(lst_cabeca, lst_cabeca2);
    imprime_com_cabeca(lst_soma);

}
cel * cria_celula(int valor){
	cel *nova;
	nova = malloc(sizeof(cel));
	nova->valor = valor;
	nova->prox = NULL;
	return nova;
}
void * adiciona(cel **pp,int valor){
    cel * p;
    if(valor > 9){
        cel * aux;
        aux = cria_celula(valor / 10);
        p = aux;
        aux->prox = cria_celula(valor % 10);
    }else{
        p = cria_celula(valor);
    }
    *pp = p;
}
cel * soma_ab(cel *a, cel *b){
    cel * p1 = a->prox;
    cel * p2 = b->prox;
    cel * p = cria_celula(0);
    int soma;

	for(p1, p2; p1 != NULL, p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if(p1 != NULL && p2 != NULL){
            soma = p1->valor + p2->valor;
            adiciona(&p->prox, soma);
        }
	}

	return p;
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


//imprimindo lista com cabeça
void imprime_com_cabeca(cel *le) {
   cel *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->valor);
}

//imprime lista sem cabeça
void imprime_sem_cabeca(cel *le) {
   cel *p;
   for (p = le; p != NULL; p = p->prox)
      printf ("%d\n", p->valor);
}



