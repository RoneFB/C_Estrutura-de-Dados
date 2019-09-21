#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int valor;
    struct celula *prox;
}; typedef struct celula celula;

celula * cria_Pilha(){
    celula *p;
    p = malloc(sizeof(celula));
    p = NULL;
    return p;
}
void empilha(int valor, celula **P){
    celula * nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = (*P);//aponta o prox para o topo da pilha
    *P = nova;// atualiza o topo da pilha
}
void desempilhar(celula **P){
    if((*P)->prox!= NULL){
        celula *lixo;
        lixo = (*P);
        *P = lixo->prox;
        free(lixo);
    }else{
        *P = NULL;
        printf("Pilha Vazia");
    }
}
 void imprimir_pilha(celula *P) {
    for (celula *aux = P; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->valor);
 }

int main(){
    celula *p = cria_Pilha();
    printf("\Empilhando\n");
    empilha(11,&p);
    empilha(8,&p);
    empilha(4,&p);
    empilha(3,&p);
    empilha(2,&p);
    imprimir_pilha(p);

    printf("\nDesempilhando\n");
    desempilhar(&p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(&p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(&p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(&p);
    imprimir_pilha(p);
    printf("\nDesempilhando\n");
    desempilhar(&p);
    imprimir_pilha(p);

}
