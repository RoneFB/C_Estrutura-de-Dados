#include<stdio.h>
#include<stdlib.h>

struct cel{
    int valor;
    struct cel *esq, *dir;
};typedef struct cel no;

void imprimir(no *arv){
    if(arv != NULL){
        imprimir(arv->esq);
        printf(" %d ", arv->valor);
        imprimir(arv->dir);
    }

}
void inserir(no **arv, int valor){
    if(*arv == NULL){
        *arv = malloc(sizeof(no));
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
        (*arv)->valor = valor;
    }if(valor > (*arv)->valor){
       inserir(&(*arv)->dir, valor);
    }if(valor < (*arv)->valor){
       inserir(&(*arv)->esq, valor);
    }
}


no * busca (int valor, no **arv){
    no * aux;
    aux = *arv;

    while(aux->valor != valor){
        if(aux->valor = valor) return aux;
        if(aux->valor > valor) aux = aux->dir;
        else aux = aux->esq;

        return NULL;
    }
}

void remove(no ** arv, int valor){
    if((*arv)->valor == valor){
        if((*arv)->dir == NULL &&(*arv)->esq == NULL){
            free(*arv);
            return NULL;
        }if((*arv)->dir != NULL && (*arv)->esq != NULL){
            no * lixo = *arv;
            if((*arv)->dir->valor > (*arv)->esq->valor){
                (*arv)->dir->esq = (*arv)->esq;
                return (*arv)->dir;
            }else{
                (*arv)->esq->esq = (*arv)->dir;
                return (*arv)->esq;
            }

        }

        return;
    }
    if((*arv)->valor > valor)
        remove(&(*arv)->dir)
    if((*arv)->valor < valor)
        remove(&(*arv)->esq)


}

int main(){
    /*cria arvore*/
    no *arv = NULL;
    inserir(&arv,11);
    inserir(&arv,8);
    inserir(&arv, 3);
    inserir(&arv, 1);
    inserir(&arv, 0);
    inserir(&arv, 2);
    inserir(&arv, 5);
    inserir(&arv, 4);

    inserir(&arv, 15);
    inserir(&arv, 21);
    inserir(&arv, 16);
    inserir(&arv, 20);
    inserir(&arv, 19);
    inserir(&arv, 25);
    inserir(&arv, 30);

    remover(&arv, 15);
    imprimir(arv);
    printf("\nBusca %d", busca(25, &arv)->valor);

}
