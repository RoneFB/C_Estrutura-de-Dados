#include <stdio.h>

#define MAX 50


int vazia(int proxTopo)
{
    return proxTopo == 0;
}

void empilhar(char valor, int *topo, int *pilha)
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
                printf("%c\n",pilha[topo]);
            }
        }else{
            printf("Pilha vazia");
        }
}

int main(void)
{
    int opcao, pilha[MAX], *topo = 0;
    char valor;

    printf("\nempilhando\n");
    empilhar('{', &topo, pilha);
    empilhar('}', &topo, pilha);
    listar(topo, pilha);



    return 0;
}
