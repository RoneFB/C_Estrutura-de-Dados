#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/**/
	char palavra[20] = "Jesus ";
	char palavra2[30] = "Cristo";
	strcat(palavra, palavra2);
	
	printf("Palavra = %s\n", palavra);
	
	
	system("pause");
	return 0;
}
