#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
	
};

int main(){
	struct pessoa p;
	strcpy(p.nome, "Rone");
	strcpy(p.rua, "Rua 1");
	
	p.idade = 31;
	p.numero = 10;
	
	/*Incializa��o como arrays*/
	struct pessoa p2 = {"Rone", "Rua 2", 22, 516};	
	
	struct pessoa p3 = {"Felipe", "Rua", 12};
	
	/*Atribui��o*/
	
	p = p3;
	system("pause");
}
