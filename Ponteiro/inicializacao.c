#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x = 10;
	int *p;//ponteiro
	
	p = &x;
	
	printf("x = %d\n", x);//conteudo de x
	printf("x = %d\n", &x);//endere�o de x
	printf("p = %d\n", p);//endere�o de p->x
	printf("p = %d\n", *p);//conteudo de p->x
	
	*p = 12;//modifica��o do conteudo do endere�o
	
	printf("p = %d\n", *p);//conteudo de p->x
	printf("x = %d\n", x);//conteudo de x
	
	system("pause");
}
