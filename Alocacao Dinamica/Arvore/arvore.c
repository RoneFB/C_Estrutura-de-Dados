#include<stdio.h>
#include<stdlib.h>

struct cel{
    int valor;
    struct cel *esq, *dir;
};typedef struct cel no;

void imprimir(no *arv){
    if(arv != NULL){
        imprimir(arv->esq);
        printf("esq -> %d | %d = %d| dir -> %d\n\n",arv->esq, arv->valor, arv, arv->dir);
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

no* buscaArvore (no* arv, int valor){
    if (arv == NULL)
        return NULL;
    else if (arv->valor > valor)
        return buscaArvore(arv->esq, valor);
    else if (arv->valor < valor)
        return buscaArvore(arv->dir, valor);
    else return arv;
}

no* buscaPai (no* arv, int valor){
    if (arv == NULL)
        return NULL;
    else if (arv->esq->valor > valor)
        return buscaArvore(arv->esq, valor);
    else if (arv->dir->valor < valor)
        return buscaArvore(arv->dir, valor);
    else return arv;
}

int remmaior(no **arv){
    while((*arv)->dir != NULL) *arv = (*arv)->dir;
    no * aux = *arv;
    int v = aux->valor;
    *arv = aux->esq;
    free(aux);
    return v;
}

void remover(no **arv){
    if(*arv == NULL)return;
    else{
        no * aux = *arv;
        if(aux->esq == NULL){
           *arv = (*arv) -> dir;
        }
        else if(aux->dir == NULL){
           *arv = (*arv) -> esq;
        }
        else aux->valor = remmaior(&aux->esq);
        if(aux != *arv) free(aux);
    }
}


void remover2(no ** arv) {
  no * aux;

  if ((*arv) -> dir ==  NULL) {
    aux = *arv;
    *arv = (*arv) -> esq;
    free(aux);
  } else
  if ((*arv) -> esq == NULL) {
    aux = *arv;
    *arv = (*arv) -> dir;
    free(aux);
  } else {
    aux = (*arv) -> dir;

    while (aux -> esq !=  NULL) {
      aux = aux -> esq;
    }

    aux -> esq = (*arv) -> esq;
    aux = *arv;
    *arv = aux -> dir;

    free(aux);
  }
}

int main(){
    /*cria arvore*/
    no *arv = NULL;


   inserir(&arv,8);
   inserir(&arv,3);
   inserir(&arv,1);
   inserir(&arv,6);
   inserir(&arv,4);
   inserir(&arv,7);
   inserir(&arv,10);
   inserir(&arv,14);
   inserir(&arv,13);

    int valor = 3;

    no * busca = buscaArvore(arv, valor);


    remover(&busca);
    imprimir(arv);
    printf("\nBusca %d",  arv);


}
