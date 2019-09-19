#include <stdio.h>
#include <stdlib.h>

/* 2ª Lista de Eestrutura de Dados: Lista Encadeada
 *
 * 1- Faça uma função que retorne apenas uma lista encadeada ordenada com os elementos das duas listas encadeadas ordenadas
 */

 struct Cel {
    int valor;
    struct Cel *prox;
};

typedef struct Cel cel;

void inserirFila(cel **i, cel **t, int valor) {
    if (*t == NULL || valor != (*t)->valor) {
        cel *temp = malloc(sizeof(cel));
        temp->prox = NULL;
        temp->valor = valor;

        if (*i == NULL) *i = temp;
        else (*t)->prox = temp;

        *t = temp;
    }
}

void intercalar(cel *p1, cel *p2, cel **i, cel **t) {
    cel *temp1 = p1;
    cel *temp2 = p2;

    while (temp1 != NULL && temp2 != NULL) {

        if  (temp1->valor <= temp2->valor) {
            inserirFila(i, t, temp1->valor);
            temp1 = temp1->prox;

        } else if (temp2->valor < temp1->valor) {
            inserirFila(i, t, temp2->valor);
            temp2 = temp2->prox;
        }
    }

    for ( ; temp1 != NULL; temp1 = temp1->prox)
        inserirFila(i, t, temp1->valor);

    for ( ; temp2 != NULL; temp2 = temp2->prox)
        inserirFila(i, t, temp2->valor);
 }

 void imprimir(cel *lista) {
    for (cel *aux = lista; aux != NULL; aux = aux->prox)
    printf("%d\n", aux->valor);
 }


 void *inserirLista (cel **lista, int x) {
    cel *temp = NULL, *aux = *lista;

    temp = malloc(sizeof(cel));
    temp->valor = x;
    temp->prox = NULL;


    if (*lista == NULL)
      *lista = temp;
    else {
      for (; aux->prox != NULL; aux = aux->prox);
      aux->prox = temp;
    }
 }

int main() {
    cel *lista1 = NULL;
    cel *lista2 = NULL;

    cel *i = NULL;
    cel *t = NULL;

    inserirLista (&lista1, 1);
    inserirLista (&lista1, 1);
    inserirLista (&lista1, 2);
    inserirLista (&lista1, 3);
    inserirLista (&lista1, 4);
    inserirLista (&lista1, 5);
    inserirLista (&lista1, 6);
    inserirLista (&lista1, 7);

    inserirLista (&lista2, 2);
    inserirLista (&lista2, 4);
    inserirLista (&lista2, 6);
    inserirLista (&lista2, 8);
    inserirLista (&lista2, 9);
    inserirLista (&lista2, 10);
    inserirLista (&lista2, 11);

    intercalar(lista1, lista2, &i, &t);

    imprimir(i);
 }


