#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	/**/
	char palavra[20] = "Testanto Frase";
	char vogais[11] = "aeiouAEIOU";
	int i,j,total = 0;
	int tam = strlen(palavra);
	int tamVog = strlen(vogais);
	
	for(i=0; i<tam; i++){
		for(j = 0; j<tamVog; j++){
			if(palavra[i] == vogais[j]){
				total++;
				break;
			}
		}
	}
	printf("Nro vogais = %d\n", total); 
	
	
	system("pause");
	return 0;
}
