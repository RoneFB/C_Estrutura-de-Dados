#include<stdio.h>
#include<stdlib.h>

struct celula{
	int valor;
	struct celula *prox;
};
typedef struct celula cel;


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

void selectionSort(cel * lst){
    int min;
    for(cel *x = lst->prox; x != NULL; x = x->prox){
            for(cel *y = x->prox; y != NULL; y = y->prox){
                if(y->valor < x->valor){
                    min = y->valor;
                    y->valor = x->valor;
                    x->valor = min;
                }
            }

    }
}

void bubbleSorte(cel * lst){
    int min;
    cel * aux = lst->prox;
    while(aux != lst){
        for(cel *x = lst->prox; x->prox != NULL; x = x->prox){
            if(x > x->prox){
                min = x->prox->valor;
                x->prox->valor = min;
                x->valor = min;
            }
        }

    }
}
int main(){
	cel *lst_cabeca;
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;

    lista_com_cabeca(lst_cabeca, 12);
    lista_com_cabeca(lst_cabeca, 5);
    lista_com_cabeca(lst_cabeca, 8);
    lista_com_cabeca(lst_cabeca, 0);
    lista_com_cabeca(lst_cabeca, 7);

    //selectionSort(lst_cabeca);
    bubbleSorte(lst_cabeca);
    imprime_com_cabeca(lst_cabeca);
}
