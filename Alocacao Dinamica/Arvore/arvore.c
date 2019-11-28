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

no *MenorEsquerda(no **arv){
    if((*arv)->esq != NULL)
       return MenorEsquerda(&(*arv)->esq);
    else{
       no *aux = *arv;
       if((*arv)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *arv = (*arv)->dir;
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
          no *aux = *arv;
          if (((*arv)->esq == NULL) && ((*arv)->dir == NULL)){
                free(aux);
                (*arv) = NULL;
          }
          else{
             if((*arv)->esq == NULL){
                (*arv) = (*arv)->dir;
                aux->dir = NULL;
                free(aux); aux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*arv)->dir == NULL){
                    (*arv) = (*arv)->esq;
                    aux->esq = NULL;
                    free(aux); aux = NULL;
                    }
                else{
                   aux = MenorEsquerda(&(*arv)->dir);
                   aux->esq = (*arv)->esq;
                   aux->dir = (*arv)->dir;
                   (*arv)->esq = (*arv)->dir = NULL;
                   free((*arv));  *arv = aux;  aux = NULL;
                   }
                }
             }
          }
}

int main(){
    /*cria arvore*/
    no *arv = NULL;

    inserir(&arv,90);
    inserir(&arv,50);
    inserir(&arv,54);
    inserir(&arv,40);
    inserir(&arv,35);
    inserir(&arv,37);
    inserir(&arv,30);
    inserir(&arv,20);
    inserir(&arv,10);
    inserir(&arv,5);






    remover(&arv, 50);
    imprimir(arv);
    printf("\nBusca %d", busca(25, &arv)->valor);

}
