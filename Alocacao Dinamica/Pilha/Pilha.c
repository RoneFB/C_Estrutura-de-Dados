#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int valor;
    struct celula *prox;
}; typedef struct celula celula;

celula * cria_Pilha(){
    celula *p;
    p = malloc(sizeof(celula));
    p->prox = NULL;
    p->valor = 0;
    return p;
}
void empilha(int valor, celula *P){
    celula * nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = P->prox; //aponta o prox para o topo da pilha
    P->prox = nova;// atualiza o topo da pilha
}
void desempilhar(celula *P){
    if(P->prox!= NULL){
        celula *lixo = P->prox;
        P->prox = lixo->prox;
        free(lixo);
    }
}
 void imprimir_pilha(celula *P) {
    for (celula *aux = P->prox; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->valor);
 }

int main(){
    celula *p = cria_Pilha();
    printf("\Empilhando\n");
    empilha(11,p);
    empilha(8,p);
    empilha(4,p);
    empilha(3,p);
    empilha(2,p);
    imprimir_pilha(p);

    printf("\nDesempilhando\n");
    desempilhar(p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(p);
    imprimir_pilha(p);

}
