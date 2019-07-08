#include<stdio.h>
#include<stdlib.h>

int main(){
	/*Cópia*/
	char palavra[20] = "Hello Horld";
	char palavra2[20];
	
	int i;
	for(i = 0; palavra[i] != '\0'; i++){
		palavra2[i] = palavra[i];
	}
	palavra2[i] = '\0';
	
	printf("%s", palavra2);
	
	
	
	/*
		strlen Tamanho da Stirng
		strcpy Copiar uma String
		strcat Concatenar duas Strings
		strcmp Comparar suas Strings
	*/
	
	
	
	system("pause");
	return 0;
}
