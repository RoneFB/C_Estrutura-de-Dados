#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula cel;

int main(){
	cel *lst_cabeca;	
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;
	printf("add com cabeca\n\n");
	lista_com_cabeca(lst_cabeca,20);
	lista_com_cabeca(lst_cabeca,15);
	lista_com_cabeca(lst_cabeca,3);
	imprime_com_cabeca(lst_cabeca);
	inverter(lst_cabeca);
	imprime_com_cabeca(lst_cabeca);
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

//void inverter(cel *p){
//    cel *aux;
//    cel *nova;
//    for(aux = p; aux != NULL; aux = aux->prox){
//        aux->
//    }
// 
//}
void inverter(cel *p){
	cel *aux;
	if(p->prox != NULL){
		inverter(p);
	}else{
		aux = p;
	}
}

