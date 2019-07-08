#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
	
};

int main(){
	struct pessoa p[4];
	
	for(i = 0; i< 4; i++){
		gets(p[i].nome);
		scanf("%d", &p[i].idade);
		gets(p[i].rua);
		scanf("%d", &p[i].numero);
	}
	
	system("pause");
	
}
