#include<stdio.h>
#include<stdlib.h>

struct celula{
    int valor;
    struct celula *prox;
};typedef struct celula celula;

struct fila{
    celula * i;
    celula * t;
};typedef struct fila fila;

fila * cria(){
    fila *f = (fila*) malloc(sizeof(fila));
    f->i = f->t = NULL;
    return f;
}


void imprime(fila * f){
    celula * p;
    if(f->i == NULL){
        printf("Fila Vazia");
    }
    for(p = f->i; p!= NULL; p = p->prox){
        printf("|%d\t|", p->valor);
    }
}

/*insere com ponteiro de ponteiro*/
void inserepp(celula ** ini, celula ** fim, int valor){
    /*cria uma nova celula*/
    celula * p = (celula *) malloc(sizeof(celula));
    p->valor = valor;
    p->prox = NULL;

    if((*ini) == NULL){/*verifica se a fila está vazia*/
        *ini = *fim = p; /*fila insere caso vazia inicio e fim aponta para o mesmo endereço*/
    }else{
        (*fim)->prox = p;/*caso tenha contrario, fim adiciona celula no prox*/
        *fim = p;/*ando com meu fim para o endereço alocado*/
    }
}
void removeFila(celula ** ini, celula ** fim){
    celula * lixo;
    lixo = *ini;//ponteiro auxiliar no inicio da fila
    if(*ini == *fim){//Verifica se inicio em fim se encontra na mesma posição
        *ini = *fim = NULL;//remove o ultimo
        free(lixo);//libera o espaço alocado
    }else{
        *ini = (*ini)->prox;//inicio anda uma célula
        free(lixo);
    }
}
int main(){

    fila *flt = cria();

    inserepp(&flt->i ,&flt->t, 5);
    inserepp(&flt->i, &flt->t, 8);
    inserepp(&flt->i, &flt->t, 3);
    imprime(flt);

    removeFila(&flt->i, &flt->t);
    printf("\nRemoveu\n");
    imprime(flt);
    removeFila(&flt->i, &flt->t);
    printf("\nRemoveu\n");
    imprime(flt);
    removeFila(&flt->i, &flt->t);
    printf("\nRemoveu\n");
    imprime(flt);

}
