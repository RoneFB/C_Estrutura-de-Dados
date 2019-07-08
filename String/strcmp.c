#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/**/
	char palavra[20] = "TESTE";
	char palavra2[30] = "TESTE";
	
	
	if(strcmp(palavra,palavra2) == 0){
		printf("String Iguais\n");
	}else printf("Palavras diferentes\n");
	
	system("pause");
	return 0;
}
