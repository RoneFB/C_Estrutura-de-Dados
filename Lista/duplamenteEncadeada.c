#include<stdio.h>
#include<stdlib.h>

struct celula {
  int valor;
  struct celula* ant;
  struct celula* prox;

};
typedef struct celula cel;

void insere_lista_duplamente_encadeada(cel* lista, int v)
{
    cel* no;
    no = (cel*) malloc(sizeof(cel));
    no->valor = v;
    if(lista->prox == NULL){
        no->ant = NULL;
        no->prox = NULL;
    }else{
        no->prox = lista->prox;
        no->ant = NULL;
        lista->prox->ant = no;
    }

    lista->prox = no;
}

void imprime_com_cabeca(cel *le) {
   cel *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->valor);
}
void insertSort(cel *le){
    int aux;
    cel *q = NULL;
    for(cel *p = le->prox; p!= NULL; p=p->prox){
        q = le->prox;
        aux = p->valor;
        while(q != NULL && q->valor < aux){
            q->prox->valor = q->valor;
            q = p->ant;
        }
        q->prox->valor = aux;
    }
}
int main(){

    cel * lst = NULL;
    lst = malloc(sizeof(cel));
    lst->ant = NULL;
    lst->prox = NULL;
    lst->valor = 0;
    insere_lista_duplamente_encadeada(lst, 5);
    insere_lista_duplamente_encadeada(lst, 7);
    insere_lista_duplamente_encadeada(lst, 1);
    insere_lista_duplamente_encadeada(lst, 3);
    insere_lista_duplamente_encadeada(lst, 4);

    insertSort(&lst);
    imprime_com_cabeca(lst);
}


