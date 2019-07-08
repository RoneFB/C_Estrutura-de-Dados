#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/**/
	char palavra[20] = "TESTE";
	char palavra2[20];
	
	
	int i, j = 0;
	for(i = strlen(palavra)-1; i>=0; i--){
	
		palavra2[j] = palavra[i];
		j++;
	}
	palavra2[j]= '\0';
	printf("palavra 2 = %s \n", palavra2);
	
	
	
	/*método 2*/
	char c;
	int tam = strlen(palavra);
	for(i = 0; i<tam/2; i++){
		c = palavra[i];
		palavra[i] = palavra[tam-1-i];
		palavra[tam-1-i] = c;
	}
	printf("palavra = %s \n", palavra);
	system("pause");
	return 0;
}
