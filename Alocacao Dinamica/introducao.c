#include <stdio.h>
#include <stdlib.h>



struct teste{
	int x, y;
	char s[4];
};
int main(){
	/*fun��es para tabalhar com aluca��o dinamica, stdlib.h
		malloc, calloc, realloc e free
		
		operador
		- sizeof
		
		int *p -> []
				  []
				  []
				  []
				  
		char:   1 byte
		int:    4 bytes
		float:  4 bytes
		double: 8 bytes
		
		sizeof(nome_do_tipo) retorna o numeros de byetes necess�rios para alocar um �nico elemento de um determinado tipo de dado
	*/
	/*Exemplo*/
	
	
	printf("x = %d\n", sizeof(char));
	printf("x = %d\n", sizeof(char));
	printf("x = %d\n", sizeof(char));
	printf("x = %d\n", sizeof(char));
	printf("x = %d\n", sizeof(struct teste));
	
	/**/
	
	
	system("pause");
	
}
