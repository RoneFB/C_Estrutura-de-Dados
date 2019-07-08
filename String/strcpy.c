#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/**/
	char palavra[20] = "Hello Horld";
	char novapalvra[30];
	strcpy(novapalvra, palavra);
	
	printf("Copia = %s\n", novapalvra);
	
	
	system("pause");
	return 0;
}
