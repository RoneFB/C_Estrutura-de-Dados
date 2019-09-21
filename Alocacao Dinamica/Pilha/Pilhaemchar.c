#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    char valor;
    struct celula *prox;
}; typedef struct celula celula;

celula * cria_Pilha(){
    celula *p;
    p = NULL;
    return p;
}
void empilha(char valor, celula **P){
    celula * nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = (*P);//aponta o prox para o topo da pilha
    *P = nova;// atualiza o topo da pilha
}
void desempilhar(celula **P){
    if((*P)->prox!= NULL){
        celula *lixo = malloc(sizeof(celula));
        lixo = (*P);
        *P = lixo->prox;
        free(lixo);
    }else{
        *P = NULL;
        free(*P);
        printf("Pilha Vazia");
    }
}
 void imprimir_pilha(celula *P) {
    for (celula *aux = P; aux != NULL; aux = aux->prox)
        printf("%d\n", aux->valor);
 }
int validacao(char *s){
    celula *p = cria_Pilha();
    int i;
    for(i = 0; s[i]!='\0'; ++i){
        switch(s[i]){
            case ")":
                if(p == NULL || p->valor != "(")return 0;
                break;
            }
            case "]":
                if(p == NULL || p->valor != "[")return 0;
                break;
            default: empilha(char[i], &p);
        }
    }

    return 1;

}

int main(){
    celula *p = cria_Pilha();
    char s[5] = '{[]}{}';
    printf("\Empilhando\n");

    validacao(&s);




}
