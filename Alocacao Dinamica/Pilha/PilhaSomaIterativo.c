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
int desempilhar(celula **P){
    int valor;
    celula *lixo;
    lixo = (*P);
    if((*P)->prox!= NULL){
        *P = lixo->prox;
        valor = lixo->valor;
        free(lixo);
        return valor;
    }else{
        valor = lixo->valor;
        (*P) = NULL;
        return valor;
    }
    return NULL;
}

void imprimir_pilha(celula *P) {
    for (celula *aux = P; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->valor);
}

int somaPilha(celula **p) {
    int soma = 0;
    while ((*p)->prox != NULL) {
        if ((*p)->valor > 0)
            soma += desempilhar(&(*p));
        else
            desempilhar(&(*p));
    }soma += desempilhar(&(*p));
    return soma;
}

int main(){
    celula * p = cria_Pilha();

    empilha(2,&p);
    empilha(4,&p);
    empilha(8,&p);
    empilha(16,&p);
    empilha(32,&p);

    imprimir_pilha(p);
    printf("Soma = %d", somaPilha(&p));
    imprimir_pilha(p);
}
