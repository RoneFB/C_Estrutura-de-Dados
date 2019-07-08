#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct endereco{
	char rua[50];
	int numero;
};


struct pessoa{
	char nome[50];
	int idade;
	struct endereco ende;
};



int main(){
	struct pessoa p;
	p.idade = 22
	p.ende.numero = 15;
	
	
	
	system("pause");
	
}
