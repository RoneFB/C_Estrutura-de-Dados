#include <stdio.h>

#define MAX 50


int vazia(int proxTopo)
{
    return proxTopo == 0;
}

void empilhar(int valor, int *topo, int *pilha)
{
    if(*topo < MAX) pilha[(*topo)++] = valor;
    else printf("Pilha Cheia");
}

void desempilhar(int *topo, int *pilha)
{
    if(*topo > 0) {
            pilha[--*topo] = NULL;
    }else pilha[*topo--] = NULL;

}

void listar(int topo, int pilha[])
{       if(topo != 0){
            while (topo > 0)
            {
                topo--;
                printf("%d\n",pilha[topo]);
            }
        }else{
            printf("Pilha vazia");
        }
}

int main(void)
{
    int opcao, pilha[MAX], *topo = 0, valor;
    printf("\nempilhando\n");
    empilhar(10, &topo, pilha);
    empilhar(20, &topo, pilha);
    empilhar(1, &topo, pilha);
    listar(topo, pilha);

    printf("\nDesempilhando\n");
    desempilhar(&topo, pilha);
    listar(topo, pilha);
    printf("\nDesempilhando\n");
    desempilhar(&topo, pilha);
    listar(topo, pilha);
    printf("\nDesempilhando\n");
    desempilhar(&topo, pilha);
    listar(topo, pilha);

    return 0;
}
