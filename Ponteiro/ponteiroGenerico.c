#include <stdio.h>
#include <stdlib.h>

int main(){
	
	void *pp;//ponteiro generico
	
	int *p1, p2 = 10;
	
	p1 = &p2;
	pp = &p2;//endere�o de int
	printf("Endereco em pp: %p \n", pp);
	pp = &p1;//endereco de int*
	printf("Endereco em pp: %p \n", pp);
	pp = p1;//endereco de int
	printf("Endereco em pp: %p \n", pp);
	
	printf("conteudo: %d\n", *pp);//ERRO
	
	printf("Conteudo: %d\n", *(int*)pp)//conver��o "TypeCast" Correto
	
	
	
	system("pause");
}
