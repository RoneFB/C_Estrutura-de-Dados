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
	lista_com_cabeca(lst_cabeca,20);
	//lista_com_cabeca(lst_cabeca,15);
	lista_com_cabeca(lst_cabeca,3);
	imprime_com_cabeca(lst_cabeca);

	/*segunda lista com cabeça*/
	cel *lst_cabeca2;
	lst_cabeca2 =  malloc(sizeof(cel));
	lst_cabeca2->prox = NULL;
	printf("add com cabeca\n");
	lista_com_cabeca(lst_cabeca2,20);
	lista_com_cabeca(lst_cabeca2,15);
	lista_com_cabeca(lst_cabeca2,3);
	imprime_com_cabeca(lst_cabeca2);

	/*cria lista sem cabeça*/
	printf("add sem cabeca\n");
	cel *lst_sem_cabe = NULL;

	lista_sem_cabeca(&lst_sem_cabe, 14);
	lista_sem_cabeca(&lst_sem_cabe, 25);
	lista_sem_cabeca(&lst_sem_cabe, 21);
	imprime_sem_cabeca(lst_sem_cabe);

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

cel * soma_ab(cel *a, cel *b){

	cel *p1 = a->prox;
	cel *p2 = b->prox;
	cel * p = cria_celula(0);
	cel * aux;
	aux = p;
	while(p1 != NULL){
        aux->prox = cria_celula(p1->valor);
        p1 = p1->prox;
        aux = aux->prox;
	}
	aux = p;
	while(p2 != NULL){
        if(aux == NULL){
            aux->prox = cria_celula(p2->valor);
        }else{
            aux->valor = aux->valor + p2->valor;
        }
        p2 = p2->prox;
        aux = aux->prox;
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



