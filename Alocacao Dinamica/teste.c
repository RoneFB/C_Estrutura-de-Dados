/* O ARQUIVO fila.h ESTA NA PASTA COMPACTADA */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main() {

   FILA *f;

   f = fl_Inicia();
   fl_Insere(f, 1);
   fl_Insere(f, 2);
   fl_Insere(f, 3);
   fl_Insere(f, 4);
   fl_Insere(f, 5);
   fl_Insere(f, 6);
   fl_Insere(f, 7);


   fl_Imprime(f);
   fl_Retira(f);
   puts("");
   fl_Imprime(f);

   puts("POR FUNCOES");
   printf("\nMAIOR ELEMENTO DA FILA : %d", fl_Maior(f));
   printf("\nMENOR ELEMENTO DA FILA: %d", fl_Menor(f));
   printf("\nSOMA DE TODOS OS ELEMENTOS DA FILA: %d", fl_Soma(f));
   printf("\nMAIOR ELEMENTO DA FILA: %.2f", fl_Media(f));
   puts("");
    if (fl_Libera(f)) {
        puts("FILA LIBERADA COM SUCESSO!");
    } else {
        puts("FILA VAZIA!");
    }
}


// -----------------------------------------------------------------------------
// encontra o maior elemento da Fila
int fl_Maior(FILA *f)
{
   DADOS *aux;
   int maior = f->inicio->valor;
   for(aux = f->inicio; aux != NULL; aux = aux->prox)
   {
      if(aux->valor > maior)
         maior = aux->valor;
   }
   return maior;
}

// -----------------------------------------------------------------------------
// encontra o menor elemento da Fila
int fl_Menor(FILA *f)
{
   DADOS *aux;
   int menor = f->inicio->valor;
   for(aux = f->inicio; aux != NULL; aux = aux->prox)
   {
      if(aux->valor < menor)
         menor = aux->valor;
   }
   return menor;
}

// -----------------------------------------------------------------------------
// encontra o maior elemento da Fila
int fl_Soma(FILA *f)
{
   DADOS *aux;
   int soma = 0;
   for(aux = f->inicio; aux != NULL; aux = aux->prox)
      soma += aux->valor;

   return soma;
}

// -----------------------------------------------------------------------------
// funcao auxiliar para insercao no final da Fila
float fl_Media(FILA *f)
{
   float media = fl_Soma(f) / (float) f->comprimento->contador;
   return media;
}

// -----------------------------------------------------------------------------
// funcao auxiliar para insercao no final da Fila
DADOS* fl_InsereFim(DADOS* fim, int valor) {
    DADOS* n = (DADOS*) malloc(sizeof (DADOS));
    n->valor = valor;
    n->prox = NULL;
    if (fim != NULL)
        fim->prox = n;
    return n;
}

// -----------------------------------------------------------------------------
//  insere elementos na Fila

void fl_Insere(FILA* f, int valor) {
    f->fim = fl_InsereFim(f->fim, valor);
    f->comprimento->contador++;
    if (fl_Vazia(f)){
       f->comprimento->maior = f->fim->valor;
       f->comprimento->menor = f->fim->valor;
       f->comprimento->soma += f->comprimento->soma + f->fim->valor;
       f->comprimento->media = f->comprimento->soma / f->comprimento->contador;
        f->inicio = f->fim;
   }else
   {
      if(valor > f->comprimento->maior)
         f->comprimento->maior = valor;
      if(valor < f->comprimento->menor)
         f->comprimento->maior = valor;
      f->comprimento->soma += valor;
      f->comprimento->media = (f->comprimento->soma / (float) f->comprimento->contador);
   }
}

// -----------------------------------------------------------------------------
// funcao auxiliar para remocao de elemento no inicio da Fila

DADOS* fl_RetiraInicio(DADOS *inicio) {
    DADOS *temp;
    temp = inicio->prox;
   free(inicio);
    return (temp);
}

// -----------------------------------------------------------------------------
// remove elemento da fila

int fl_Retira(FILA *f) {
    int temp;
    if (fl_Vazia(f)) {
        puts("FILA VAZIA!");
        return NULL;
    } else {
        temp = f->inicio->valor;
        f->inicio = fl_RetiraInicio(f->inicio);
        f->comprimento->contador--;
        if(temp > f->comprimento->maior)
           f->comprimento->maior = fl_Maior(f);
        if(temp < f->comprimento->menor)
         f->comprimento->menor = fl_Menor(f);
      f->comprimento->soma -= temp;
      f->comprimento->media = (f->comprimento->soma / (float) f->comprimento->contador);
        return temp;
    }
}

// -----------------------------------------------------------------------------
// imprime elementos da Fila

void fl_Imprime(FILA *f) {
    DADOS *aux;
    int i = 1;
    printf(" POSICAO NA PILHA |   VALOR | COMPRIMENTO |  MAIOR  | MENOR   |   SOMA  | MEDIA\n");
    for (aux = f->inicio; aux != NULL; aux = aux->prox, i++)
        printf("          [%5d] | [%5d] | [%9d] | [%5d] | [%5d] | [%5d] | [%.2f]\n", i, aux->valor, f->comprimento->contador,f->comprimento->maior, f->comprimento->menor, f->comprimento->soma, f->comprimento->media);
    puts("");
}

// -----------------------------------------------------------------------------
// inici a fila de elementos

FILA* fl_Inicia() {
    FILA *n = (FILA *) calloc(1, sizeof (FILA));
    CONTADOR *c = (CONTADOR *) calloc(1, sizeof(CONTADOR));
    if (n != NULL) {
        n->inicio = n->fim = NULL;
        n->comprimento = c;
        n->comprimento->contador = n->comprimento->maior = n->comprimento->menor = n->comprimento->soma = n->comprimento->media = 0;
        return n;
    } else {
        return NULL;
    }
}

// -----------------------------------------------------------------------------
// libera fila de elementos

int fl_Libera(FILA *f) {
    if (fl_Vazia(f)) {
        return 0;
    } else {
        DADOS *aux;
        while (f->inicio != NULL) {
            aux = f->inicio;
            f->inicio = f->inicio->prox;
        }
        free(f->comprimento);
        return 1;
    }
}

// -----------------------------------------------------------------------------
// verifica se fila está vazia

int fl_Vazia(FILA *f) {
    return (f->inicio == NULL);
}
