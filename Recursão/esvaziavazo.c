#include<stdio.h>
#include<stdlib.h>

void esvaziaVaso(int flores){
	if(flores > 0){
		esvaziaVaso(flores - 1);
	}
}

int main(){
	esvaziaVaso(20);
	
	system("pause");
}
