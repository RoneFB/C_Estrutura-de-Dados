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
char * desempilhar(celula **P){
    celula *lixo;
    char aux;
    if((*P)->prox!= NULL){
        lixo = (*P);
        (*P) = lixo->prox;
        aux = lixo->valor;
        free(lixo);
        return aux;
    }else{
        aux = (*P)->valor;
        *P = NULL;
        return aux;
    }
    return NULL;
}
 void imprimir_pilha(celula *P) {
    for (celula *aux = P; aux != NULL; aux = aux->prox)
        printf("%c\n", aux->valor);
 }
int validacao(char *s){
    celula *p = cria_Pilha();
    int i;
    for(i = 0; s[i]!='\0'; i++){
        char * aux;
        switch(s[i]){
            case ')':
                if(p == NULL)return 0;
                aux = desempilhar(&p);
                if (aux != '(') return 0;
                break;

            case ']':
                if(p == NULL)return 0;
                aux = desempilhar(&p);
                if (aux != '[') return 0;
                break;
            default: empilha(s[i], &p);
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
