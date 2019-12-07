#include<stdio.h>
#include<stdlib.h>

struct cel{
    int valor;
    struct cel *esq, *dir;
};typedef struct cel no;

void imprimir(no *arv){
    if(arv != NULL){
        imprimir(arv->esq);
        printf("%d\n",arv->valor);
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


void remover2(no ** raiz) {
  no * conc, *prev;

  conc = *raiz;
  if ((*raiz) -> dir ==  NULL) {
    *raiz = (*raiz) -> esq;
    free(conc);
  } else
  if ((*raiz) -> esq == NULL) {
    *raiz = (*raiz) -> dir;
    free(conc);
  } else if((*raiz)->dir != NULL && (*raiz)->esq != NULL) {

    conc = (*raiz) -> esq;
    while (conc->dir !=  NULL) {
      prev = conc;
      conc = conc->dir;
    }
    if(prev != *raiz){
        prev->dir = conc->esq;
        (*raiz)->valor = conc->valor;
        free(conc);
    }


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

    //int valor = 10;

   // no * busca = buscaArvore(arv, valor);


    remover2(&arv);
    imprimir(arv);
    //printf("\nBusca %d",  arv);


}
