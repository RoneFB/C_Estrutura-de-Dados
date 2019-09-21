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
	lista_com_cabeca(lst_cabeca,7);
	lista_com_cabeca(lst_cabeca,9);
	lista_com_cabeca(lst_cabeca,5);
	imprime_com_cabeca(lst_cabeca);

	/*segunda lista com cabeça*/
	cel *lst_cabeca2;
	lst_cabeca2 =  malloc(sizeof(cel));
	lst_cabeca2->prox = NULL;
	printf("add com cabeca\n");
	lista_com_cabeca(lst_cabeca2,1);
	lista_com_cabeca(lst_cabeca2,2);
	lista_com_cabeca(lst_cabeca2,3);
	lista_com_cabeca(lst_cabeca2,4);
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
cel * adiciona(cel *p,int valor){
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
cel * soma_ab(cel *a, cel *b){
    cel * p1 = a->prox;
    cel * p2 = b->prox;
    cel * p = malloc(sizeof(cel));
    p->prox = NULL;
    int soma;

	for(p1, p2; p1 != NULL, p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if(p1 != NULL && p2 != NULL){
            soma = p1->valor + p2->valor;
            lista_com_cabeca(p->prox, soma);
        }

	}
	imprime_com_cabeca(p);
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



