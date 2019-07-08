#include<stdio.h>
#include<stdlib.h>

int main(){
	/*String em é um array de caracteres*/
	
	char palavra[20];
	/*  Leitura  */
	printf("Digite uma palavra");
	//scanf("%s", palavra);//Leitura até digitar um espaço ou enter
	gets(palavra);//Leitura somente quando gitar o Enter
	/*  Imprimir  */
	printf("\nPalavra lida: %s\n", palavra);
	
	
	/*	Inicializar  */
	/*forma convercional*/
	char nome1[20] = {'r','o','n','e','\0'};
	printf("\nnome: %s ",nome1);
	
	/*forma especial*/
	char nome2[20] = "felipe";
	printf("\nnome: %s ", nome2);
	
	system("pause");
}
