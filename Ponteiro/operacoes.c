#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x = 10;
	int *p, *p1;
	float y = 20.0;
	
	p = &x;
	printf("*p: %d\n", *p);
	p1 = p;
	printf("*p1: %d \n", *p1);
	
	
	int *p3 = 0x5dc;//1500
	printf("p = %d \n", p);
	p++;
	printf("p - %d \n", p);//1504
	p = p+15;
	printf("p - %d \n", p);//1564
	p = p-2;
	printf("p - %d \n", p);//1556
	
	
	system("pause");
}
