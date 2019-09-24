#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    char valor;
    struct celula *prox;
}; typedef struct celula celula;

celula * cria_Pilha(){
    celula *p;
    p = malloc(sizeof(celula));
    p->prox = NULL;
    p->valor = '0';
    return p;
}
void empilha(char valor, celula *P){
    celula * nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = P->prox; //aponta o prox para o topo da pilha
    P->prox = nova;// atualiza o topo da pilha
}
char desempilhar(celula *P){
    char valor;
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
        printf("%c\n", aux->valor);
 }
int validacao(char *s){
    celula *p = cria_Pilha();
    int i;
    for(i = 0; s[i]!='\0'; i++){
        char * aux;
        switch(s[i]){
            case ')':
                if(p->prox == NULL)return 0;
                aux = desempilhar(p);
                if (aux != '(') return 0;
                break;

            case ']':
                if(p->prox == NULL)return 0;
                aux = desempilhar(p);
                if (aux != '[') return 0;
                break;
            default: empilha(s[i], p);
        }
    }
    return 1;
}


int main(){
    celula *p = cria_Pilha();
    char s[5] = "((()))";
    char s2[5] = "(((])))";

   if(validacao(&s) == 1)printf("\nS1 Bem formada");
   else printf("\nS1 mal formada");

   if(validacao(&s2) == 1)printf("\nS2 Bem formada");
   else printf("\nS2 mal formada");






}
