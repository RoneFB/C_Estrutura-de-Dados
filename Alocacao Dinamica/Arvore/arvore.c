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

no *MaiorDireita(no **arv){
    if((*arv)->esq != NULL)
       return MaiorDireita(&(*arv)->dir);
    else{
       no *aux = *arv;
       if((*arv)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *arv = (*arv)->esq;
       else
          *arv = NULL;
       return aux;
    }
}


void remover(no **arv, int numero){
    if(*arv == NULL) return;
    if(numero < (*arv)->valor)
       remover(&(*arv)->esq, numero);
    else
       if(numero > (*arv)->valor)
          remover(&(*arv)->dir, numero);
       else{
          /*Nó encontrador*/
          no *aux = *arv;
          if (((*arv)->esq == NULL) && ((*arv)->dir == NULL)){
                /*Caso nó não tenha filho*/
                free(aux);
                (*arv) = NULL;
               }
          else{
             if ((*arv)->esq == NULL){ /*Caso nó tem filho a sua direita*/
                (*arv) = (*arv)->dir;
                aux->dir = NULL;
                free(aux);
             }
             else{
                if ((*arv)->dir == NULL){
                    (*arv) = (*arv)->esq;
                    aux->esq = NULL;
                    free(aux);
                    }
                else{
                   aux = MaiorDireita(&(*arv)->esq);
                   aux->esq = (*arv)->esq;
                   aux->dir = (*arv)->dir;
                   (*arv)->esq = (*arv)->dir = NULL;
                   free((*arv));
                   *arv = aux;
                   }
                }
             }
          }
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

    remover(&arv, 16);
    imprimir(arv);
    printf("\nBusca %d", busca(25, &arv)->valor);

}
