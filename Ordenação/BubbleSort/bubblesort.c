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

void bubbleSorte(cel * lst){
    int min;

        for(cel *x = lst->prox; x->prox != NULL; x = x->prox){
            for(cel *y = x->prox; y->prox != NULL; y = y->prox){
                if(y->prox->valor > y->prox->valor){
                    min = x->prox->valor;
                    x->prox->valor = y->prox->valor;
                    y->prox->valor = min;
                }else{
                   break;
                }
            }
        }


}
int main(){
	cel *lst_cabeca;
	lst_cabeca =  malloc(sizeof(cel));
	lst_cabeca->prox = NULL;


    lista_com_cabeca(lst_cabeca, 5);
    lista_com_cabeca(lst_cabeca, 8);
    lista_com_cabeca(lst_cabeca, 12);
    lista_com_cabeca(lst_cabeca, 0);
    lista_com_cabeca(lst_cabeca, 7);

    //selectionSort(lst_cabeca);
    bubbleSorte(lst_cabeca);
    imprime_com_cabeca(lst_cabeca);
}
