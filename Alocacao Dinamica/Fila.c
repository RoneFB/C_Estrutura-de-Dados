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
/*
celula * inserefim(celula * t, int valor){
    celula * p = (celula *) malloc(sizeof(celula));
    p->valor = valor;
    p->prox = NULL;
    if(t != NULL){
        t->prox = p;
    }return p;
}

void insere(fila * f, int valor){
    f->t = inserefim(f->t, valor);
    if(f->i == NULL) f->i = f->t;
}
*/

void imprime(fila * f){
    celula * p;
    for(p = f->i; p!= NULL; p = p->prox){
        printf("%d\n", p->valor);
    }
}

/*insere com ponteiro de ponteiro*/
void inserepp(celula ** ini, celula ** fim, int valor){
    /*cria uma nova celula*/
    celula * p = (celula *) malloc(sizeof(celula));
    p->valor = valor;
    p->prox = NULL;

    if((*ini) == NULL){/*verifica se a fila está vazia*/
        *ini = p; /*fila insere caso vazia inicio e fim aponta para o mesmo endereço*/
        *fim = p;
    }else{
        (*fim)->prox = p;/*caso tenha contrario, fim adiciona celula no prox*/
        *fim = p;/*ando com meu fim para o endereço alocado*/
    }
}
void removeFila(){

}
int main(){

    fila *flt = cria();
    void insere(fila *f, int valor);
    inserepp(&flt->i ,&flt->t, 5);
    inserepp(&flt->i, &flt->t, 8);
    inserepp(&flt->i, &flt->t, 3);
    imprime(flt);
    //addFila(&flt->i, &flt->t, 3);


}
