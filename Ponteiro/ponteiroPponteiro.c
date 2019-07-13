#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x = 10;
	int *p = &x;
	int **p2 = &p;
	
	//endereco em p2
	printf("p2: %d\n", p2);//&p
	
	//conteudo do endereço que é o endereço de x
	printf("*p2: %d\n", *p2);//&x
	
	//conteudo do endereço do endereço que é o conteudo de x
	printf("**p2: %d\n", **p2);//x
	system("pause");
}
