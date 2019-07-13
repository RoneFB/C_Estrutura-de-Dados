#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x = 10;
	int *p;//ponteiro
	
	p = &x;
	
	printf("x = %d\n", x);//conteudo de x
	printf("x = %d\n", &x);//endereço de x
	printf("p = %d\n", p);//endereço de p->x
	printf("p = %d\n", *p);//conteudo de p->x
	
	*p = 12;//modificação do conteudo do endereço
	
	printf("p = %d\n", *p);//conteudo de p->x
	printf("x = %d\n", x);//conteudo de x
	
	system("pause");
}
