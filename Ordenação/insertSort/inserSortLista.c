#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula cel;


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
void insertSort(cel * le){
    cel *p,*q,*min;
    p = le;
    for(p = p->prox; p!=NULL; p = p->prox){
       q = le->prox;
       while(p != q && q->valor > p->valor){
            min = p->prox;
       }if(min != p){
            m
            p->prox = min;
       }
    }

}


int main(){

	/*Cria 1 lista com cabeça*/
	cel *lst_cabeca;
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;

	printf("add com cabeca\n");

	//lista_com_cabeca(lst_cabeca,15);
	lista_com_cabeca(lst_cabeca,7);
	lista_com_cabeca(lst_cabeca,9);
	lista_com_cabeca(lst_cabeca,1);
	lista_com_cabeca(lst_cabeca,2);
	lista_com_cabeca(lst_cabeca,4);
	lista_com_cabeca(lst_cabeca,12);
	imprime_com_cabeca(lst_cabeca);

    insertSort(lst_cabeca);
    printf("\n");
	imprime_com_cabeca(lst_cabeca);


}
