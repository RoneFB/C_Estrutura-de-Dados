#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*compartilha reserva de mem�ria*/
union tipo{
	short int x;
	unsigned char c;
	/*16 bits*/
	
};
/*Soma da quantidade de mem�ria necess�ria para a cada variavel*/
struct tipoS{
	short int x;
	unsigned char x;
	/*24 bits*/
};

int main(){
	union tipo u;
	struct tipoS s;
	
	system("pause");
	
}
