#include <stdio.h>
#include <stdlib.h>

void fatorial(int numero){
	if(numero == 0){
		return 1;
	}else{
		return numero * fatorial(numero - 1);
	}
}

int main(){
	int x = fatorial(4);
}
