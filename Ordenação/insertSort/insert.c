#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int valor;
    struct celula *prox;
}; typedef struct celula celula;

celula * cria(){
    celula * nova = malloc(sizeof(celula));
    nova->valor = 0;
    nova->prox = NULL;
}

void add(celula * lst, int valor){
    celula * nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = lst->prox;
    lst->prox = nova;

}

void imprime(celula * lst){
    for(celula *p = lst->prox;p != NULL; p = p->prox){
        printf("%d\n", p->valor);
    }
}

void insertSort(celula * lst){
    celula *p = lst->prox->prox;
    celula *q;
    int x;

    while (p->prox != NULL) {
        q = lst->prox;
        x = p->valor;

        while ((q != p) && (q->valor > x)) {
            q->prox->valor =  q->valor;
            q = q->prox;
        }
        q->prox->valor = x;
        p = p->prox;
    }
}

int main(){
    celula * lst = cria();
    add(lst, 3);
    add(lst, 7);
    add(lst, 1);
    add(lst, 4);

    insertSort(lst);
    imprime(lst);
}
