#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum semana{Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado};


int main(){
	
	enum semana s;
	
	s = Terca;
	printf("Valor = %d\n", s);
	system("pause");
	
}
