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
int desempilhar(celula *P){
    int valor;
    if(P->prox!= NULL){
        celula *lixo = P->prox;
        P->prox = lixo->prox;
        valor = lixo->valor;
        free(lixo);
    }
    return valor;
}
void imprimir_pilha(celula *P) {
    for (celula *aux = P->prox; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->valor);
}

void convDecBin(celula * p, int valor){
    int b = 0;
    while(valor >= 1){
        b = valor%2;
        valor = valor /2;
        empilha(b, p);
    }
}

int main(){

    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    celula * p = cria_Pilha();

    convDecBin(p, numero);

    imprimir_pilha(p);

}

