#include <stdio.h>
#include <stdlib.h>

struct celula{
    int valor;
    struct celula *prox;
};typedef struct celula celula;


celula * cria_celula(int valor){
    celula * nova;
    nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = NULL;
    return nova;
}

void lista_ccabeca(celula * lst, int valor){
    celula * p;

    p = cria_celula(valor);
    p->prox = lst->prox;
    lst->prox = p;
}

void imprime_lstccabeca(celula * lst){
    celula * p = lst->prox;
    for(p->prox; p!= NULL; p = p->prox){
        printf("%d\t", p->valor);
    }
}

void soma(celula *a, celula *b){
    celula * soma = cria_celula(0);
    celula * p = soma;
    celula *p1 = a->prox;
    celula *p2 = b->prox;

    while(p1!= NULL){

        p->prox = cria_celula(p1->valor + p2->valor);
        p1 = p1->prox;
        p2 = p2->prox;
        if(p2 == NULL){
            p->prox = p1;
        }
        p = p->prox;
    }if(p2 != NULL){
        p->prox = p2;
    }

    imprime_lstccabeca(soma);
}

int main(){
    celula *lst = cria_celula(0);
    lista_ccabeca(lst, 5);
    lista_ccabeca(lst, 11);
    lista_ccabeca(lst, 4);

    imprime_lstccabeca(lst);

    printf("\n");
    celula *lst2 = cria_celula(0);
    lista_ccabeca(lst2, 3);
    lista_ccabeca(lst2, 88);
    lista_ccabeca(lst2, 9);
    lista_ccabeca(lst2, 1);
    imprime_lstccabeca(lst2);
printf("\n");
    soma(lst,lst2);
}


