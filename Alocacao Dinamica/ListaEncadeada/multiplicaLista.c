#include <stdio.h>
#include <stdlib.h>

struct cel 
{
    int valor;
    struct cel *prox;
};

typedef struct cel celula;

celula *criaCelula(int valor)
{
    celula *p;                  
    p = malloc(sizeof(celula)); 
    p->valor = valor;     
    p->prox = NULL;         
    return p;                   
}


celula *multiplicaLista(celula *a, celula *b){
    celula *r = NULL;
    celula *p1, *p2;
    int mult, div1, mod1;
    p1 = inverter(a);
    p2 = inverter(b);
    while(p1 != NULL && p2 != NULL){
        //verifica o maior e inverte se necessário
        if(sizeof(p1) < sizeof (p2)){
            celula *troca = p2;
            p2 = p1;
            p1 = troca;
            free(troca);
        }else{
            mult = p1->valor*p2->valor;
            if(mult > 9){
                mod1 = mult % 10;
                div1 = mult / 10;
                r = criaCelula(mod1);
                r->prox = criaCelula(div1);
            }else{
                r = criaCelula(mult);
            }
        }
        p1 = p1->prox;
        p2 = p2->prox;
        
    }
}

celula *inverter(celula *p){
    celula *aux;
    celula *nova;
    for(aux = p; aux != NULL; aux = aux->prox){
        nova = malloc(sizeof(celula));
        nova->prox = p->valor;
        nova->prox = p;
        nova = nova->prox;
    }
}

