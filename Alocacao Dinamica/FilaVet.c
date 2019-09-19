#include <stdio.h>
#include <stdlib.h>

/*
Exibindo uma fila
*/

#define N 6

struct fil 
{
    int ini, fim;
    int vet[N];
};

typedef struct fil fila;

fila *criar()
{
    fila *novafila = malloc(sizeof(fila));
    novafila->ini = 0;  //inicializa fila vazia
    novafila->fim = 0;  //inicializa fila vazia

    return novafila;
}

int incr(int i)
{
    if(i == N-1) return 0;  //se coincidir do i estar na ultima posicao do vetor, ao incrementar, seu valor é alterado para referenciar a primeira posição do vetor
    else return (i + 1);    //senão, o i simplesmente 'anda' para a próxima posição do vetor
}

int vazia(fila *f)
{
    return (f->ini == f->fim);  //retorna 1 (true) se a fila estiver vazia
                                //retorna 0 (false) se a fila não estiver vazia
}

int cheia(fila *f)
{
    return (incr(f->fim) == f->ini);    //retorna 1 (true) se a fila estiver cheia
                                        //retorna 0 (false) se a fila não estiver cheia
}

void inserir(fila *f, int valor)
{
    if(cheia(f)) printf("\nA fila está cheia\n");
    else{
        f->vet[f->fim] = valor;
        f->fim = incr(f->fim);
    }
}

void remover(fila *f)
{
    if(vazia(f)) printf("\nA fila está vazia\n");
    else{
        f->vet[f->ini] = 0;
        f->ini = incr(f->ini);
    }
}

void exibir(fila *f)
{
    if(vazia(f)) printf("\nA fila está vazia\n");
    else{
        for(int i = f->ini; i != f->fim; i = incr(i))
        {
            printf("\n|indice %d | valor %d |\n", i, f->vet[i]);
        }
    }
}

void liberar(fila *f)
{
    free(f);
}

int main()
{
    //declarando variaveis
    fila *f;

    //declarando as funções
    fila *criar();
    int incr(int i);
    int vazia(fila *f);
    int cheia(fila *f);
    void inserir(fila *f, int valor);
    void remover(fila *f);
    void exibir(fila *f);
    void liberar(fila *f);

    f = criar();

    printf("\nCRIANDO A FILA\n");
    inserir(f, 1);
    inserir(f, 2);
    inserir(f, 3);
    inserir(f, 4);
    inserir(f, 5);
    
    exibir(f);

    printf("\nREMOVENDO DA FILA\n");
    remover(f);

    exibir(f);

    printf("\nLIBERANDO A FILA\n");
    liberar(f);

    exibir(f);

    return 0;
}
