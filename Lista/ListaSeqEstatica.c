#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};


struct lista{
	int qtd
	struct aluno dados[MAX]
};
typedef struct lista Lista;
Lista *li;


Lista * cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(struct lista));
	if(li != NULL){
		li->qtd  = 0;
		return li;
	}
}

void libera_lista(Lista* li){
	free(li);
}

int tamanho_lista(Lista* li){
	if(li == NULL){
		return -1;
	}else{
		return li->qtd;
	}
}

int lista_cheia(Lista* li){
	if(li = NULL)
		return -1;
	return (li->qtd == MAX);
	
}


/*inser��o*/
int insere_lista_final(Lista* li, struct aluno al){
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li->dados[li->qtd] = al;
	li->qtd++;
	return 1;
}


int insere_lista_inicio(Lista* li, struct aluno al){
	if(li == NULL)return 0;
	if(lista_cheia(li))return 0;
	int i;
	for(i = li->qtd-1; i>=0; i--)
		li->dados[i+1] = li->dados[i];
	li->dados[0] = al;
	li->qtd++;
	return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
	if(li == NULL) return 0;
	if(lista_cheia(li)) return 0;
	int k,i=0;
	while(i<li->qtd && li->dados[i].matricula < al.matricula)
		i++;
		
	for(k = li->qtd-1; k >= i; k--)
		li->dados[k+1] = li->dados[k];
	li->dados[i] = al;
	li->qtd++;
	return 1;
}

/*remo��o*/
int
int main(){
	li = cria_lista();
	libera_lista(li);
	int x = tamanho_lista(li);
}
