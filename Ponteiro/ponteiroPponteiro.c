#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x = 10;
	int *p = &x;
	int **p2 = &p;
	
	//endereco em p2
	printf("p2: %d\n", p2);//&p
	
	//conteudo do endere�o que � o endere�o de x
	printf("*p2: %d\n", *p2);//&x
	
	//conteudo do endere�o do endere�o que � o conteudo de x
	printf("**p2: %d\n", **p2);//x
	system("pause");
}
